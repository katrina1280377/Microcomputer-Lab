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
* File Name    : r_cg_rtc_user.c
* Version      : Code Generator for RX231 V1.00.04.01 [11 Nov 2016]
* Device(s)    : R5F52318AxFP
* Tool-Chain   : CCRX
* Description  : This file implements device driver for RTC module.
* Creation Date: 2017/11/9
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
#include "r_cg_rtc.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
rtc_calendarcounter_value_t  time;
char TX[20]={0};
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_rtc_prd_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_RTC_PRD
#pragma interrupt r_rtc_prd_interrupt(vect=VECT(RTC,PRD),fint)
#else
#pragma interrupt r_rtc_prd_interrupt(vect=VECT(RTC,PRD))
#endif
static void r_rtc_prd_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

	     R_RTC_Get_CalendarCounterValue(&time);

	     TX[19] = '\r';
	     TX[18] = (time.rseccnt&0x0f) +'0';
    	 TX[17] = (time.rseccnt>>4)+'0';
    	 TX[16] = ':';
    	 TX[15] = (time.rmincnt&0x0f)+'0';
    	 TX[14] = (time.rmincnt>>4)+'0';
    	 TX[13]	= ':';
    	 TX[12] = (time.rhrcnt&0x0f)+'0';
    	 TX[11] = (time.rhrcnt>>4)+'0';
    	 TX[10] = '-';
    	 TX[9] = (time.rdaycnt&0x0f)+'0';
    	 TX[8] = (time.rdaycnt>>4)+'0';
    	 TX[7] = '/';
    	 TX[6] = (time.rmoncnt&0x0f)+'0';
    	 TX[5] = (time.rmoncnt>>4)+'0';
    	 TX[4] = '/';
    	 TX[3] = (time.ryrcnt&0x07)+'0';
    	 TX[2] = (time.ryrcnt>>4)+'0';


    	 R_SCI5_Serial_Send(&TX[2],18);

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
