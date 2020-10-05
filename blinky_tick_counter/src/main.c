/*******************************************************************************
 Copyright (c) 2018, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
*******************************************************************************/

#define XMC4500_F144x1024

#include <xmc_gpio.h>

#define TICKS_PER_SECOND 1000
#define TICKS_WAIT 500

#define LED1 P1_1
#define LED2 P1_0

void SysTick_Handler(void)
{
  static uint32_t ticks = 0;

  ticks++;
  if (ticks == TICKS_WAIT)
  {
    XMC_GPIO_ToggleOutput(LED1);
    XMC_GPIO_ToggleOutput(LED2);
    ticks = 0;
  }
}


int main(void)
{
  XMC_GPIO_CONFIG_t config;

  config.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL;
  config.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH;
  config.output_strength = XMC_GPIO_OUTPUT_STRENGTH_MEDIUM;

  XMC_GPIO_Init(LED1, &config);

  config.output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;
  XMC_GPIO_Init(LED2, &config);

  /* System timer configuration */
  SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);

  while(1)
  {
    /* Infinite loop */
  }
}

