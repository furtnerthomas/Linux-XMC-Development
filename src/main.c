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


#include "XMC4500.h"

void thedelay(unsigned long delay)
{
  while(delay--)
{
__NOP();
}
}

int main(void)
{
  PORT1->IOCR0 = 0x80UL << 0; //P1.0 output, push pull
  PORT1->IOCR0|= 0x80UL << 8; //P1.1 output, push pull
  PORT1->PDR0 = 0x02UL << 0;  //P1.0, pad driver strong
  PORT1->PDR0 |= 0x02UL << 8; //P1.1, pad driver strong

  while(1)
    {
      PORT1->OMR = (1UL<<0)|((1UL<<0)<<16); // P1.0 ON
      PORT1->OMR |=(1UL<<1)<<16;            // P1.1 OFF
      thedelay(8000000);
      PORT1->OMR = (1UL<<0)<<16;            // P1.0 OFF
      PORT1->OMR = (1UL<<1)|((1UL<<1)<<16); // P1.1 ON
      thedelay(8000000);
    }
  return 0;
}

