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
* Creation Date: 2017/10/26
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
#include "r_cg_port.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
char keyonetwo[25]="Key1&2 are pressed!\n\r";
char keytwothree[25]="Key2&3 are pressed!\n\r";
char keyonethree[25]="Key1&3 are pressed!\n\r";
char keyone[25]="Key1 is pressed!\n\r";
char keytwo[25]="Key2 is pressed!\n\r";
char keythree[25]="Key3 is pressed!\n\r";
char allkey[25]="All keys are pressed!\n\r";
extern int flag;
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
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
    R_SCI5_Create();
    R_PORT_Create();
    R_SCI5_Start();
    int key=0,keyold=8;
    while (1U)
    {


	if(PORT3.PIDR.BIT.B1==0)
		key |=1;
	else
		key &=~1;
	if(PORT3.PIDR.BIT.B4==0)
		key |=2;
	else
		key &=~2;
	if(PORT0.PIDR.BIT.B7==0)
		key |=4;
	else
		key &=~4;
    if(flag)
    if(flag && keyold!=key)
	{
    	keyold=key;
    	switch(key)
    	{
    		case 1:
    			R_SCI5_Serial_Send(keyone,25);
    			flag=0;
    			break;
    		case 2:
    			R_SCI5_Serial_Send(keytwo,25);
    			flag=0;
    			break;
    		case 3:
			 	 R_SCI5_Serial_Send(keyonetwo,25);
			 	 flag=0;
			 	 break;
		 	case 4:
		 		 R_SCI5_Serial_Send(keythree,25);
		 		 flag=0;
		 		 break;
		 	case 5:
		 		R_SCI5_Serial_Send(keyonethree,25);
		 		flag=0;
		 		break;
		 	case 6:
		 		R_SCI5_Serial_Send(keytwothree,25);
		 		flag=0;
		 		break;
		 	case 7:
		 		R_SCI5_Serial_Send(allkey,25);
		 		flag=0;
		 		break;
    	}
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
