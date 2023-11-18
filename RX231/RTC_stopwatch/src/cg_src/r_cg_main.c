/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_main.c
* Version      : Code Generator for RX231 V1.00.04.01 [11 Nov 2016]
* Device(s)    : R5F52318AxFP
* Tool-Chain   : CCRX
* Description  : This file implements main function.
* Creation Date: 2017/11/16
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_rtc.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
int flag=0,hr=0,min=0,sec=0,tenthsecond=0,push=0,x=0;
char output[12]={'\r',0,0,':',0,0,':',0,0,'.',0,0};
char get[13]={'\r',0,0,':',0,0,':',0,0,'.',0,0,'\n'};
rtc_calendarcounter_value_t count;
/* End user code. Do not edit comment generated here */


static void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    R_RTC_Create();
    R_RTC_Start();
    R_SCI5_Create();
    R_SCI5_Start();
    RTC.RSECCNT.BYTE = 0;
    RTC.RMINCNT.BYTE = 0;
    RTC.RHRCNT.BYTE = 0;
    while (1U)
    {

    	if(flag)
    	{   flag=0;
    		R_RTC_Get_CalendarCounterValue(&count);
    		output[10]=(RTC.R64CNT.BYTE/12.7)+'0';     output[11]=((int)(RTC.R64CNT.BYTE/1.27)%10)+'0';
    		output[8]=(count.rseccnt&0xf)+'0';  output[7]=(count.rseccnt>>4)+'0';
        	output[5]=(count.rmincnt&0xf)+'0';  output[4]=(count.rmincnt>>4)+'0';
            output[2]=(count.rhrcnt&0xf)+'0';   output[1]=(count.rhrcnt>>4)+'0';
            if(!push)R_SCI5_Serial_Send(output,12);

    	}

    	if(RTC.RTCCR1.BIT.TCST==1U)
    	{
			push=1;
			R_RTC_Get_CalendarTimeCaptureValue1(&count);
			get[10]=(RTC.R64CNT.BYTE/12.7)+'0';     get[11]=((int)(RTC.R64CNT.BYTE/1.27)%10)+'0';
			get[8]=(count.rseccnt&0xf)+'0';  get[7]=(count.rseccnt>>4)+'0';
			get[5]=(count.rmincnt&0xf)+'0';  get[4]=(count.rmincnt>>4)+'0';
			get[2]=(count.rhrcnt&0xf)+'0';   get[1]=(count.rhrcnt>>4)+'0';
			if(push)R_SCI5_Serial_Send(get,13);
    	}

    }
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    uint16_t protect_dummy = (uint16_t)(SYSTEM.PRCR.WORD & 0x000FU);

    /* Disable protect bit */
    SYSTEM.PRCR.WORD = 0xA50FU;

    SYSTEM.VBATTCR.BYTE = 0x81U;
	
    /* Restore the previous state of the protect register */
    SYSTEM.PRCR.WORD = (uint16_t)(0xA500U | protect_dummy);
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
