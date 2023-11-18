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
* Creation Date: 2017/11/21
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
#include "r_cg_cmt.h"
#include "r_cg_rtc.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
int flag=1,sec,min,hr,x,counter,value,num=1,bt1=0,bt2=0,bt3=0,alarm=0,k=0;
char output[10]={'\r',0,0,':',0,0,':',0,0,' '};
char clock[9]={'\r','0','0',':','0','0',':','0','0'};
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
    R_RTC_Create();  // 建置與開啟各種周邊
    R_SCI5_Create();
    R_PORT_Create();
    R_CMT0_Create();
    R_CMT1_Create();
    R_RTC_Start();
    R_SCI5_Start();
	RTC.RSECCNT.BYTE = 0x12;  //  設置初始值
    RTC.RMINCNT.BYTE = 0x14;
    RTC.RHRCNT.BYTE = 0;
    while (1U)
    {
    	if(flag)  // 開始跑 RTC顯示時間
    	{   flag=0;
    		R_RTC_Get_CalendarCounterValue(&count);
    		output[8]=(count.rseccnt&0xf)+'0';  output[7]=(count.rseccnt>>4)+'0';
        	output[5]=(count.rmincnt&0xf)+'0';  output[4]=(count.rmincnt>>4)+'0';
            output[2]=(count.rhrcnt&0xf)+'0';   output[1]=(count.rhrcnt>>4)+'0';
            R_SCI5_Serial_Send(output,10);
    	}


        /*以下BT1判斷*/
 		if(!PORT3.PIDR.BIT.B1) 		// 長短按判斷 用CMT計數 x++
 			 	 { R_CMT0_Start(); bt1=1;}
 		else
 			if(bt1)
 				{R_CMT0_Stop();counter=x; 	// 放開計數結束 把值丟進判斷值counter
				if(counter>300) 	 // 若長按 為確定
					{ if(!alarm)output[num]=(value+'0');
					  else clock[num]=(value+'0');	// 把時鐘的值放進value
					  R_CMT1_Stop();
						  RTC.RSECCNT.BYTE = ((output[8]-'0')+(output[7]-'0')*16); // 把時間的值設定到暫存器
					      RTC.RMINCNT.BYTE = ((output[5]-'0')+(output[4]-'0')*16);
					      RTC.RHRCNT.BYTE = ((output[2]-'0')+(output[1]-'0')*16);
					  R_RTC_Start();
					  x=0; counter=0; num=1; alarm=0;}
				if(counter>30 && counter<300) 	// 若為短按 右移
				{ if(!alarm)   // 判斷是設鬧鐘還是時間
					{ output[num]=(value+'0'); // 右移就確認值
				 	  num++; num%=9; // 在指向下一個
				 	  if(num==3||num==6||num==0)num++;
				 	  value=(output[num]-'0');
					  x=0;counter=0;}
				  else
					{ clock[num]=(value+'0');
				 	  num++; num%=9;
				 	  if(num==3||num==6||num==0)num++;
				 	  value=(clock[num]-'0');
					  x=0;counter=0;}
				 }
				bt1=0;}

        /*以下BT2判斷*/
        if(!PORT3.PIDR.BIT.B4) 	// 長短按判斷 用CMT計數 x++
        	{	R_CMT0_Start();bt2=1;}
        else
        	if(bt2)
        		{R_CMT0_Stop();counter=x; 	//放開計數結束 把值丟進判斷值counter
				if(counter>300)  	//若長按 設定時間
				{ R_RTC_Stop(); R_CMT1_Start();
				  value=(output[num]-'0'); 		//把數值放進value
				  x=0; counter=0;}
				if(counter>30 && counter<300) 	//若為短按 上數
				{ value++; value%=10;
				  x=0; counter=0;}
			bt2=0;}

        /*以下BT3判斷*/
		if(!PORT0.PIDR.BIT.B7) 	// 長短按判斷 用CMT計數 x++
			{	 R_CMT0_Start(); bt3=1;}
		else
			if(bt3)
				{R_CMT0_Stop();counter=x; 	//放開計數結束 把值丟進判斷值counter
				if(counter>300)  	//若為長按 則設定鬧鐘
					{ R_RTC_Stop(); R_CMT1_Start();
					  value=(clock[num]-'0'); 		//把鬧鐘的值放進value
					  x=0; counter=0; alarm=1;}
				if(counter>30 && counter<300) 	//若為短按 下數
					{ value--; value%=10;
				 	 x=0;counter=0;}
				bt3=0;}

		/*進位判斷*/
		if(!alarm)
		  {if((output[1]-'0')==2)
			if(num==2){ if(value<0) value=3;
						value%=4; }}
		else
		  {if((clock[1]-'0')==2)
			if(num==2){ if(value<0) value=3;
						value%=4; }}
		if(num==1)    {if(value<0) value=2; value%=3;}
		if(num==4 || num==7)  { if(value<0) value=5; value%=6;}
	    if(value<0) value=9;

		/*鬧鈴響*/
	    for(int i=0;i<9;i++)
	    	if(output[i]==clock[i])
	    		k++;
	   if(k==9) output[9]='R';
	   else  output[9]=' ';
	            k=0;


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
