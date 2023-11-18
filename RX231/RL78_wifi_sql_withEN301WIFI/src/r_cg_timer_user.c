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
* Copyright (C) 2011, 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_timer_user.c
* Version      : CodeGenerator for RL78/G12 V2.03.04.01 [11 Nov 2016]
* Device(s)    : R5F1026A
* Tool-Chain   : GCCRL78
* Description  : This file implements device driver for TAU module.
* Creation Date: 2018/10/11
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern char TIME[21],GET[500];
extern char flag,j,F_RESET,F_delay;
int t[3]={0},sec=0,delay_sec=0;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_tau0_channel0_interrupt
* Description  : This function is INTTM00 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_tau0_channel0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

    sec++;
    if(F_delay)
    	delay_sec++;
    if(sec>=60){
        GET[27]='0';
        /*
        TIME[17]++;
        if(TIME[17]>'9'){
        	TIME[17]='0';
        	TIME[16]++;

        }
        if(TIME[16]>'5'){
        	TIME[16]='0';
        	TIME[14]++;

        }

        if(TIME[14]>'9'){
        	TIME[14]='0';
        	TIME[13]++;

        }
        if(((TIME[13]-'0')*10+(TIME[14]-'0') )> 24){
                	TIME[14]='0';
                	TIME[13]='0';
                	TIME[9]++;

                }
        if(TIME[9]>'9'){
        	TIME[9]='0';
        	TIME[8]++;

        }*/
        flag=1;
        sec=0;
    }

    if(delay_sec==3)
    {
    	 PM6 = _00_PMn0_MODE_OUTPUT | _02_PMn1_MODE_INPUT | _FC_PM6_DEFAULT;

    	 P6_bit.no0=0;
    	 F_RESET=1;
    	 F_delay=0;
    }
	t[2]=(TIME[19]-'0')*10+(TIME[20]-'0');
	t[1]=(TIME[16]-'0')*10+(TIME[17]-'0');
	t[0]=(TIME[13]-'0')*10+(TIME[14]-'0');

	t[2]++;
	t[2]=t[2]%60;

    if(t[2]==0){
    	t[1]++;
    	t[1]=t[1]%60;
    	if(t[1]==0)t[0]++;
    }
    for(j=0;j<3;j++)
    	{
    	TIME[13+(j*3)]=((t[j]/10)+'0');
    	TIME[14+(j*3)]=((t[j]%10)+'0');
    	}
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
