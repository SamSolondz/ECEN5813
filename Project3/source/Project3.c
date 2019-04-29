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
#include <math.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_adc16.h"
#include "fsl_dma.h"

#define RAWADC 1
//#define DMATEST 1
#define DMACHANNEL0 0

#define max16	65536

uint32_t buffer[256];
uint32_t *buffer_ptr = buffer;

uint32_t reading[256];
int32_t dbfs;

int buffer_select = 0;
int half_full = 0;
int j = 0;
int k, l;

void configure_gpio()
{
		/*GPIO shit*/
		 //Enable Port E Clock Gate control - SCGC5
		 SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
		 SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

		 SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;

		 GPIOD->PDDR |= (1<<1);
		 GPIOD->PSOR |= (1<<1);
		 PORTD->PCR[1] |= PORT_PCR_MUX(1);

		 GPIOE->PDDR |= (30<<1);
		 GPIOE->PSOR |= (30<<1);
		 PORTE->PCR[30] |= PORT_PCR_MUX(1);
}

void configure_adc()
{
	adc16_config_t ADCconfig;
	//16 bit single ended conversion
	ADCconfig.resolution = kADC16_ResolutionSE16Bit;
	//Select bus clock for clock source
	ADCconfig.clockSource = kADC16_ClockSourceAlt0;
	//Set clock divider to 1
	ADCconfig.clockDivider = kADC16_ClockDivider1;
	//Enable continuous conversion
	ADCconfig.enableContinuousConversion = true;

	ADC16_Init(ADC0, &ADCconfig);

	//Set single ended 16-bit conversion
	ADC0->SC1[0] &= ~ADC_SC1_DIFF_MASK;
	ADC0->CFG1  |= ADC_CFG1_MODE(3);
	//Select DADP0 as input channel
	ADC0->SC1[0] &= ~ADC_SC1_ADCH_MASK;
	//DMA request ADC enable
	ADC0->SC2 |= ADC_SC2_DMAEN_MASK;
	//Enable interrupt
	ADC0->SC1[0] |= ADC_SC1_AIEN_MASK;

	adc16_channel_config_t ADCchannelconfig;
	ADCchannelconfig.channelNumber = 0;
	ADCchannelconfig.enableDifferentialConversion = false;
	ADCchannelconfig.enableInterruptOnConversionCompleted = false;

	ADC16_SetChannelConfig(ADC0, 0, &ADCchannelconfig);
}

void configure_dma()
{
	//Enable clock to DMA Mux;
	SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;

	//Disable DMAMUX
	DMAMUX0->CHCFG[0] &= ~DMAMUX_CHCFG_ENBL_MASK;
	//Disable DMAMUX trigger
	DMAMUX0->CHCFG[0] &= ~DMAMUX_CHCFG_TRIG_MASK;

	//Set ADC as DMAMUX input channel source
	DMAMUX0->CHCFG[0] |= DMAMUX_CHCFG_SOURCE(40); //ADC souce module

	//Enable clock to DMA
	SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;

	DMA_ResetChannel(DMA0, DMACHANNEL0);

	dma_transfer_config_t config;
	config.srcAddr = (uint32_t)(&(ADC0->R[0]));

	if(half_full)
		config.destAddr = (uint32_t)(buffer_ptr);
	else
		config.destAddr =(uint32_t)(&(buffer[128]));

	config.enableSrcIncrement = false;
	config.enableDestIncrement = true;
	config.srcSize = kDMA_Transfersize32bits;
	config.destSize = kDMA_Transfersize32bits;
	config.transferSize = sizeof(buffer)/2;	//Buffer size of 256

	//Enable DMA interrupt on transfer complete
	DMA0->DMA[0].DCR |= DMA_DCR_EINT_MASK;
	//Enable peripheral request
	DMA0->DMA[0].DCR |= DMA_DCR_ERQ_MASK;

	DMA_Init(DMA0);

	DMA_SetTransferConfig(DMA0, DMACHANNEL0, &config);

	//Enable DMAMUX
	DMAMUX0->CHCFG[0] |= DMAMUX_CHCFG_ENBL_MASK;
}

void DMA0_IRQHandler()
{
	NVIC_DisableIRQ(DMA0_IRQn);

	//Toggle GPIO PTE30 = J11
	GPIOE->PTOR |= (1<<30);
	//Toggle LED
	GPIOD->PTOR |= (1<<1);

	if(half_full == 0)
		half_full = 1;

	else
		half_full = 0;

	//Acknowledge Interupt
	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;
	//Reconfigure DMA channel
	configure_dma();

	NVIC_EnableIRQ(DMA0_IRQn);
}

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    PRINTF("\n\rHello World");

    //Initialize buffer
    for(int k = 0; k < (sizeof(buffer)/sizeof(uint32_t)); k++)
    	buffer[k] = 0;

    NVIC_EnableIRQ(DMA0_IRQn);
    configure_gpio();
    configure_adc();
    //TODO:  add ADC calibration function
    configure_dma();

    while(1)
    {

#ifdef RAWADC
       if(ADC0->SC1[0] & ADC_SC1_COCO_MASK)
       {
    	   uint32_t data = ADC0->R[0] & ADC_R_D_MASK;
           double pre = ((double)3.3)/((double)0xffff);
    	   double adc_read = ((double)data) * pre;

    	   // dbfs calculations
    	   float test = (((float)data)/((float)max16));
    	   float result = log(test);
           dbfs = (20)*result;
           PRINTF("\n\n\rdbfs: -%d", dbfs);

    	   PRINTF("\n\rADC channel 0: %u, %d", data, (int)adc_read);
       }
#endif

#ifdef DMATEST
        NVIC_DisableIRQ(DMA0_IRQn);

		for(int i = 0; i < 256; i++)
		{
		   uint32_t val = buffer[i];

//		   PRINTF("\n\ri = %d, buffer = %u", i, val);

		   // add to readout if larger
		   if(val >= buffer[i-1])									//////////// Inserted PeakMeter /////////////////
		   {
		       reading[j] = val;
		   }

		   // reduce readout if not larger
		   else
		   {
		       reading[j] = 0.5 * reading[j-1];
		   }

//		   PRINTF("\n\rPeakMeter = %d\n", reading[j]);

		   j++;
		}

		PRINTF("\n\n\rDONE\n");
		j = 0;

	    NVIC_EnableIRQ(DMA0_IRQn);
#endif

   }
    return 0;
}
