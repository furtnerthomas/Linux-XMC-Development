/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

#include <string.h>
#include "cmsis_os.h"

#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/stats.h"
#include "lwip/debug.h"


#if !NO_SYS


#ifndef SYS_SEM_COUNT
#define SYS_SEM_COUNT   4
#endif

typedef struct os_semaphore_cb {
  uint32_t cb[2];
} os_semaphore_cb_t;

typedef struct os_semaphore {
  os_semaphore_cb_t cb;
  osSemaphoreDef_t  def;
} os_semaphore_t;

osPoolDef(sys_pool_sem, SYS_SEM_COUNT, os_semaphore_t);
osPoolId  sys_pool_sem;

err_t sys_sem_new(sys_sem_t *sem, u8_t count)
{
  os_semaphore_t *ptr;
  osSemaphoreId   id;

  ptr = osPoolCAlloc(sys_pool_sem);
  if (ptr == NULL) {
    return ERR_MEM;
  }
  ptr->def.semaphore = ptr;
  id = osSemaphoreCreate(&ptr->def, count);
  if (id == NULL) {
    return ERR_MEM;
  }
  *sem = id;

  return ERR_OK;
}

void sys_sem_free(sys_sem_t *sem)
{
  osSemaphoreDelete(*sem);
  osPoolFree(sys_pool_sem, *sem);
}

u32_t sys_arch_sem_wait(sys_sem_t *sem, u32_t timeout)
{
  int32_t  count;
  uint32_t tick;

  tick = osKernelSysTick();
  if (timeout == 0) {
    count = osSemaphoreWait(*sem, osWaitForever);
  } else {
    count = osSemaphoreWait(*sem, timeout);
  }
  if (count == 0) {
    return SYS_ARCH_TIMEOUT;
  }
  tick = 1000*(uint64_t)((osKernelSysTick() - tick)) / osKernelSysTickFrequency;

  return tick;
}

void sys_sem_signal(sys_sem_t *sem)
{
  osSemaphoreRelease(*sem);
}


#ifndef SYS_MBOX_COUNT
#define SYS_MBOX_COUNT  16
#endif
#ifndef SYS_MBOX_SIZE
#define SYS_MBOX_SIZE   32
#endif

typedef struct os_messageQ_cb {
  uint32_t cb[4+SYS_MBOX_SIZE];
} os_messageQ_cb_t;

typedef struct os_messageQ {
  os_messageQ_cb_t cb;
  osMessageQDef_t  def;
} os_messageQ_t;

osPoolDef(sys_pool_mbox, SYS_MBOX_COUNT, os_messageQ_t);
osPoolId  sys_pool_mbox;

err_t sys_mbox_new(sys_mbox_t *mbox, int size)
{
  os_messageQ_t *ptr;
  osMessageQId   id;

  if (size > SYS_MBOX_SIZE) {
    return ERR_MEM;
  }

  ptr = osPoolCAlloc(sys_pool_mbox);
  if (ptr == NULL) {
    return ERR_MEM;
  }
  ptr->def.queue_sz = SYS_MBOX_SIZE;
  ptr->def.pool = ptr;
  id = osMessageCreate(&ptr->def, NULL);
  if (id == NULL) {
    return ERR_MEM;
  }
  *mbox = id;

  return ERR_OK;
}

void sys_mbox_free(sys_mbox_t *mbox)
{
  osPoolFree(sys_pool_mbox, *mbox);
}

void sys_mbox_post(sys_mbox_t *q, void *msg)
{
  osMessagePut(*q, (uint32_t)msg, osWaitForever);
}

err_t sys_mbox_trypost(sys_mbox_t *q, void *msg)
{
  osStatus status;

  status = osMessagePut(*q, (uint32_t)msg, 0);
  if (status != osOK) {
    return ERR_MEM;
  }
  return ERR_OK;
}

u32_t sys_arch_mbox_fetch(sys_mbox_t *q, void **msg, u32_t timeout)
{
  osEvent  event;
  uint32_t tick;

  tick = osKernelSysTick();
  if (timeout == 0) {
    event = osMessageGet(*q, osWaitForever);
  } else {
    event = osMessageGet(*q, timeout);
  }
  if (event.status != osEventMessage) {
    return SYS_ARCH_TIMEOUT;
  }
  if (msg != NULL) {
    *msg = event.value.p;
  }
  tick = 1000*(uint64_t)((osKernelSysTick() - tick)) / osKernelSysTickFrequency;

  return tick;
}

u32_t sys_arch_mbox_tryfetch(sys_mbox_t *q, void **msg)
{
  osEvent event;

  event = osMessageGet(*q, 0);
  if (event.status != osEventMessage) {
    return SYS_MBOX_EMPTY;
  }
  if (msg != NULL) {
    *msg = event.value.p;
  }

  return 0;
}


#ifndef SYS_THREAD_COUNT
#define SYS_THREAD_COUNT 6
#endif

osPoolDef(sys_pool_thrd, SYS_THREAD_COUNT, osThreadDef_t);
osPoolId  sys_pool_thrd;

sys_thread_t sys_thread_new(const char *name, lwip_thread_fn function, void *arg, int stacksize, int prio)
{
  osThreadDef_t *def;
  osThreadId     id;
  LWIP_UNUSED_ARG(name);
  LWIP_UNUSED_ARG(prio);

  def = osPoolAlloc(sys_pool_thrd);
  if (def == NULL) {
    return NULL;
  }
  def->pthread = (os_pthread)function;
  def->tpriority = osPriorityNormal;
  def->stacksize = stacksize;
  def->instances = 1;
  id = osThreadCreate(def, arg);

  return id;
}

#if SYS_LIGHTWEIGHT_PROT

osMutexDef(lwip_mutex);
osMutexId  lwip_mutex;

sys_prot_t sys_arch_protect(void)
{
  osMutexWait(lwip_mutex, osWaitForever);
  return 0;
}

void sys_arch_unprotect(sys_prot_t pval)
{
  LWIP_UNUSED_ARG(pval);
  osMutexRelease(lwip_mutex);
}

#endif /* SYS_LIGHTWEIGHT_PROT */


#endif /* !NO_SYS */


u32_t sys_now()
{
  return (1000*(uint64_t)(osKernelSysTick()) / osKernelSysTickFrequency);
}

void sys_init()
{
#if !NO_SYS
  sys_pool_sem  = osPoolCreate(osPool(sys_pool_sem));
  sys_pool_mbox = osPoolCreate(osPool(sys_pool_mbox));
  sys_pool_thrd = osPoolCreate(osPool(sys_pool_thrd));
#if SYS_LIGHTWEIGHT_PROT
  lwip_mutex = osMutexCreate(osMutex(lwip_mutex));
#endif
#endif /* !NO_SYS */
}
