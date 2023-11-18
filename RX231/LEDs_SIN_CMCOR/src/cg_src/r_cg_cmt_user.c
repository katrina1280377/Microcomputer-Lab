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
* File Name    : r_cg_cmt_user.c
* Version      : Code Generator for RX231 V1.00.04.01 [11 Nov 2016]
* Device(s)    : R5F52318AxFP
* Tool-Chain   : CCRX
* Description  : This file implements device driver for CMT module.
* Creation Date: 2017/10/12
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
#include "r_cg_cmt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
int i=0,x[100]={8300,8821,9340,9855,10364,10864,11355,11833,12298,12747,13178,13590,13981,14350,14695,15014,15307,15573,15810,16017,16193,16339,16452,16534,16583,16600,16583,16534,16452,16339,16193,16017,15810,15573,15307,15014,14695,14350,13981,13590,13178,12747,12298,11833,11355,10864,10364,9855,9340,8821,8300,7778,7259,6744,6235,5735,5244,4766,4301,3852,3421,3009,2618,2249,1904,1585,1292,1026,789,582,406,260,147,65,16,0,16,65,147,260,406,582,789,1026,1292,1585,1904,2249,2618,3009,3421,3852,4301,4766,5244,5735,6235,6744,7259,7778};
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_cmt_cmi0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT0_CMI0
#pragma interrupt r_cmt_cmi0_interrupt(vect=VECT(CMT0,CMI0),fint)
#else
#pragma interrupt r_cmt_cmi0_interrupt(vect=VECT(CMT0,CMI0))
#endif
static void r_cmt_cmi0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	PORT5.PODR.BYTE=0;
	CMT1.CMCOR = x[i%100];
	CMT2.CMCOR = x[(i+33)%100];
	CMT3.CMCOR = x[(i+66)%100];
	i++;

    R_CMT1_Start();
	R_CMT2_Start();
	R_CMT3_Start();

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi1_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT1_CMI1
#pragma interrupt r_cmt_cmi1_interrupt(vect=VECT(CMT1,CMI1),fint)
#else
#pragma interrupt r_cmt_cmi1_interrupt(vect=VECT(CMT1,CMI1))
#endif
static void r_cmt_cmi1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

		PORT5.PODR.BIT.B0=1;
		R_CMT1_Stop();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi2_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT2_CMI2
#pragma interrupt r_cmt_cmi2_interrupt(vect=VECT(CMT2,CMI2),fint)
#else
#pragma interrupt r_cmt_cmi2_interrupt(vect=VECT(CMT2,CMI2))
#endif
static void r_cmt_cmi2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	PORT5.PODR.BIT.B1=1;
	R_CMT2_Stop();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi3_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT3_CMI3
#pragma interrupt r_cmt_cmi3_interrupt(vect=VECT(CMT3,CMI3),fint)
#else
#pragma interrupt r_cmt_cmi3_interrupt(vect=VECT(CMT3,CMI3))
#endif
static void r_cmt_cmi3_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	PORT5.PODR.BIT.B2=1;
	R_CMT3_Stop();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
