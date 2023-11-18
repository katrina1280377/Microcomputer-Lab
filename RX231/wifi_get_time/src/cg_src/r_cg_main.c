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
* Creation Date: 2018/2/10
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
#include "r_cg_icu.h"
#include "r_cg_port.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
char rx[1]={0};
int flag=1,ok_flag=0,count_flag=1,led[4]={0},s=0;
extern int i,count;
extern char command[100];
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
    R_ICU_Create();
    R_ICU_IRQ1_Start();
    PORT5.PODR.BYTE=7;
    PORT1.PODR.BIT.B7=1;
    R_SCI5_Start();
    R_SCI5_Serial_Receive(rx,1);

    while (1U)
    {

    	if(command[i-3]=='K' && command[i-4]=='O')  // 判斷AT指令成功
		{
    		ok_flag=1;
    		if(count_flag)
    			count++;
    		for(int j=0;j<100;j++)
    			command[j]=0;
    		i=0;
		}
    	else if( command[i-7]=='E'&& command[i-6]=='R' && command[i-5]=='R'&& command[i-4]=='O' && command[i-3]=='R') //判斷錯誤
    	 {
    		if(count==0)  //在指令1的錯誤 可能已經連上
    		  {
    			ok_flag=1;
    			count++;
    			for(int j=0;j<100;j++)
    			   command[j]=0;
    			i=0;
    		  }
    		else  //其他的顯示全亮 表示有ERROR
    		  {
    			PORT5.PODR.BYTE=0;
    			PORT1.PODR.BIT.B7=0;
    		  }

    	 }

    	if(flag && ok_flag)  //確定有回傳OK 才送下一個指令
		{
			if(count==1)
				{
					R_SCI5_Serial_Send("AT+CIPSEND=20\r\n",15);
					flag=0;
					ok_flag=0;
				}
			else if(count==2)
				{
					R_SCI5_Serial_Send("Get /etao/time.php\r\n",22);
					flag=0;
					ok_flag=0;
				}
			else if(count==3)
				{
					count_flag=0;  //停止數count
					if(command[29]=='C'&&command[30]=='L' &&command[31]=='O'&&command[32]=='S'&&command[33]=='E'&&command[34]=='D')
					{	s= (command[28]-'0');
						for(int j=0;j<s;j++)
					    {
							led[0]++;
							if(led[0]==2)
							 {
								led[0]=0;
								led[1]++;
							 }
							if(led[1]==2)
							 {
								led[1]=0;
								led[2]++;
							 }
							if(led[2]==2)
							 {
								led[2]=0;
								led[3]++;
							 }
						   }
						PORT1.PODR.BIT.B7=(1-led[3]);
						PORT5.PODR.BIT.B0=(1-led[2]);
						PORT5.PODR.BIT.B1=(1-led[1]);
						PORT5.PODR.BIT.B2=(1-led[0]);
						count++;
					}
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
