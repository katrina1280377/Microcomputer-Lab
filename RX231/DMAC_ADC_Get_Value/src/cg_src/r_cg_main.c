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
* Creation Date: 2017/12/14
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
#include "r_cg_dmac.h"
#include "r_cg_mtu2.h"
#include "r_cg_sci.h"
#include "r_cg_s12ad.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern unsigned short ADC_Result[1300];
extern int finish_flag;
char input[4]={0};     // 輸入4位數
char output[41]="\r\nmax=0.0000v min=0.0000v aver=0.0000v\r\n";
int flag=1,start_flag=0; // 各種flag
int voltage,count,aver,max=0,min=33000;
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
     R_DMAC_Create();
     R_S12AD_Create();
     R_MTU2_Create();
     R_SCI5_Create();
     R_SCI5_Start();
	 R_SCI5_Serial_Receive(input,4);
     while (1U)
     {
     	 if(start_flag)
     	 {
     	  DMAC0.DMCRA =count;
     	  R_DMAC0_Start();
     	  R_S12AD_Start();
     	  R_MTU2_C0_Start();
 		  start_flag=0;
     	 }

	    if(finish_flag)
		 {
			max=0,min=33000,aver=0;
			for(int i=0;i<count;i++)   // 換算電壓
			 {
				voltage=((float)ADC_Result[i]*3.3)/4095*100000;
				voltage+=5; voltage/=10;
			    aver+=voltage;   // 電壓總和
			    if( max < voltage )  // 最大值
				  max=voltage;
			    else if( min > voltage )  // 最小值
				  min=voltage;
			  }
			if(min==33000) min=0;
			 aver/=count;  // average
			for(int i=36;i>=31;i--)
			 { if(i==32) i--;
				output[i]=(aver%10)+'0';
				aver/=10;
			 }
			for(int i=23;i>=18;i--)
			 { if(i==19) i--;
				output[i]=(min%10)+'0';
				min/=10;
			 }

			  for(int i=11;i>=6;i--)
			  { if(i==7) i--;
				output[i]=(max%10)+'0';
				max/=10;
			  }

			 if(flag)
			  {
				flag=0;
				R_SCI5_Serial_Send(output,41);

			  }
				finish_flag=0;
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
