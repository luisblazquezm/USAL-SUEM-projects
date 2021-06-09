/** ###################################################################
 **     Filename    : KBI0_Init.c
 **     Processor   : MKE06Z128LK4
 **     Abstract    :
 **          This file implements the KBI0 module initialization
 **          according to the Peripheral Initialization settings, and
 **          defines interrupt service routines prototypes.
 **
 **     Contents    :
 **         Int   - void KBI0_Init(void);
 **
 **     Copyright : 1997 - 2015 Freescale Semiconductor, Inc.
 **     All Rights Reserved.
 **
 **     Redistribution and use in source and binary forms, with or without modification,
 **     are permitted provided that the following conditions are met:
 **
 **     o Redistributions of source code must retain the above copyright notice, this list
 **       of conditions and the following disclaimer.
 **
 **     o Redistributions in binary form must reproduce the above copyright notice, this
 **       list of conditions and the following disclaimer in the documentation and/or
 **       other materials provided with the distribution.
 **
 **     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 **       contributors may be used to endorse or promote products derived from this
 **       software without specific prior written permission.
 **
 **     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 **     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 **     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 **     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 **     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 **     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 **     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 **     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 **     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 **     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **
 **     http: www.freescale.com
 **     mail: support@freescale.com
 ** ###################################################################*/

/*!
 * @file KBI0_Init.c
 * @brief This file implements the KBI0 module initialization according to the
 *        Peripheral Initialization settings, and defines interrupt service
 *        routines prototypes.
 */


/* MODULE KBI0_Init. */

#include "KBI0_Init.h"
#include "MKE06Z4.h"
#include "Init_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

void KBI0_Init(void) {

  /* Register 'KBI0_SC' initialization */
  #if KBI0_SC_MASK_1
    #if KBI0_SC_MASK_1 == 0xFFFFFFFF
  KBI0_SC = KBI0_SC_VALUE_1;
    #elif KBI0_SC_MASK_1 == KBI0_SC_VALUE_1
  KBI0_SC |= KBI0_SC_VALUE_1;
    #elif KBI0_SC_VALUE_1 == 0
  KBI0_SC &= ~KBI0_SC_MASK_1;
    #else
  KBI0_SC = (KBI0_SC & (~KBI0_SC_MASK_1)) | KBI0_SC_VALUE_1;
    #endif
  #elif defined(KBI0_SC_VALUE_1)
  KBI0_SC = KBI0_SC_VALUE_1;
  #endif

  /* Register 'KBI0_ES' initialization */
  #ifdef KBI0_ES_VALUE
  KBI0_ES = KBI0_ES_VALUE;
  #endif

  /* Register 'KBI0_PE' initialization */
  #ifdef KBI0_PE_VALUE
  KBI0_PE = KBI0_PE_VALUE;
  #endif

  /* Register 'KBI0_SC' initialization */
  #if KBI0_SC_MASK_2
    #if KBI0_SC_MASK_2 == 0xFFFFFFFF
  KBI0_SC = KBI0_SC_VALUE_2;
    #elif KBI0_SC_MASK_2 == KBI0_SC_VALUE_2
  KBI0_SC |= KBI0_SC_VALUE_2;
    #elif KBI0_SC_VALUE_2 == 0
  KBI0_SC &= ~KBI0_SC_MASK_2;
    #else
  KBI0_SC = (KBI0_SC & (~KBI0_SC_MASK_2)) | KBI0_SC_VALUE_2;
    #endif
  #elif defined(KBI0_SC_VALUE_2)
  KBI0_SC = KBI0_SC_VALUE_2;
  #endif

  /* Register 'KBI0_SC' initialization */
  #if KBI0_SC_MASK_3
    #if KBI0_SC_MASK_3 == 0xFFFFFFFF
  KBI0_SC = KBI0_SC_VALUE_3;
    #elif KBI0_SC_MASK_3 == KBI0_SC_VALUE_3
  KBI0_SC |= KBI0_SC_VALUE_3;
    #elif KBI0_SC_VALUE_3 == 0
  KBI0_SC &= ~KBI0_SC_MASK_3;
    #else
  KBI0_SC = (KBI0_SC & (~KBI0_SC_MASK_3)) | KBI0_SC_VALUE_3;
    #endif
  #elif defined(KBI0_SC_VALUE_3)
  KBI0_SC = KBI0_SC_VALUE_3;
  #endif
}

#ifdef __cplusplus
}
#endif

/* END KBI0_Init. */

/** ###################################################################
 **
 **     This file is a part of Processor Expert static initialization
 **     library for Freescale microcontrollers.
 **
 ** ################################################################### */
