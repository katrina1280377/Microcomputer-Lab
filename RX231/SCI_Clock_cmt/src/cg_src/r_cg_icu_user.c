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
* File Name    : r_cg_icu_user.c
* Version      : Code Generator for RX231 V1.00.04.01 [11 Nov 2016]
* Device(s)    : R5F52318AxFP
* Tool-Chain   : CCRX
* Description  : This file implements device driver for ICU module.
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
#include "r_cg_icu.h"
#include "r_cg_cmt.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
char input[1]={0};
extern int k;
char change[1]='\n';
int shine=0,flag=0;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_icu_irq1_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ1
#pragma interrupt r_icu_irq1_interrupt(vect=VECT(ICU,IRQ1),fint)
#else
#pragma interrupt r_icu_irq1_interrupt(vect=VECT(ICU,IRQ1))
#endif
static void r_icu_irq1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	R_CMT0_Stop();
	flag=1;
	k=0;
	R_SCI5_Serial_Receive(input,1);

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_icu_irq4_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ4
#pragma interrupt r_icu_irq4_interrupt(vect=VECT(ICU,IRQ4),fint)
#else
#pragma interrupt r_icu_irq4_interrupt(vect=VECT(ICU,IRQ4))
#endif
static void r_icu_irq4_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	R_CMT0_Stop();
	shine=1;
	k=0;
	R_SCI5_Serial_Send(change,1);
	R_SCI5_Serial_Receive(input,1);

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
