/*
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Project3.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_adc16.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

void configure_adc()
{
	//Set single ended 16-bit conversion
	ADC0->SC1[0] &= ~ADC_SC1_DIFF_MASK;
	ADC0->CFG1  |= ADC_CFG1_MODE(3);
	//Select DADP0 as input channel
	ADC0->SC1[0] &= ~ADC_SC1_ADCH_MASK;

	adc16_config_t ADCconfig;
	//16 bit single ended conversion
	ADCconfig.resolution = kADC16_ResolutionSE16Bit;
	//Select bus clock for clock sourc
	ADCconfig.clockSource = kADC16_ClockSourceAlt0;
	//Set clock divider to 1
	ADCconfig.clockDivider = kADC16_ClockDivider1;
	//Enable continuous conversion
	ADCconfig.enableContinuousConversion = true;

	adc16_channel_config_t ADCchannelconfig;
	ADCchannelconfig.channelNumber = 0;
	ADCchannelconfig.enableDifferentialConversion = false;
	ADCchannelconfig.enableInterruptOnConversionCompleted = false;



	ADC16_Init(ADC0, &ADCconfig);
	ADC16_SetChannelConfig(ADC0, 0, &ADCchannelconfig);
}

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    PRINTF("Hello World\n");

   while(1) {
       if(ADC0->SC1[0] & ADC_SC1_COCO_MASK)
       {
    	   uint16_t data = ADC0->R[0] & ADC_R_D_MASK;
    	   PRINTF("\n\rData: %lu", data);
       }

    }
    return 0 ;
}
