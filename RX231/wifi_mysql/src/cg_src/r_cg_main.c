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
* Creation Date: 2018/3/1
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
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

extern int tx_flag,i;
extern char command[100];

char rx[1]={0},stack[100]={0};
int now=0,old=0,s,j,count=0,n=0,history[4]={0},x[4]={0},num=0,k=0;
const char OK[2]="OK";
const char ERROR[5]="ERROR";
const char CLOSED[6]="CLOSED";
const char FAIL[4]="FAIL";
// flags
int flag=0,ok_flag=0,count_flag=0,stack_flag=0;

//commands
const char CIPSTART[39]="AT+CIPSTART=\"TCP\",\"140.125.49.210\",80\r\n";
char CIPSEND[15]="AT+CIPSEND=37\r\n";
char GET[300]="Get /bear/time.php?count=01&state=0\r\n";

/* End user code. Do not edit comment generated here */


static void R_MAIN_UserInit(void);
static void R_MAIN_COMMAND(void);
static void R_MAIN_CLEAR(char * array);
int FINDWORD(char *com,char *word ,int comlen, int wordlen);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    R_SCI5_Create();
    R_PORT_Create();

    R_SCI5_Start();
    R_SCI5_Serial_Receive(rx,1);

    /* Start user code. Do not edit comment generated here */
    while (1U)
    {
    	if( PORT4.PIDR.BIT.B1==0 ) { x[0]=1; n++;}   // button for jump
		else x[0]=0;
		if( PORT4.PIDR.BIT.B2==0 ) { x[1]=1; n++;}
		else x[1]=0;
		if( PORT4.PIDR.BIT.B3==0 ) { x[2]=1; n++;}
		else x[2]=0;
		if( PORT4.PIDR.BIT.B4==0 ) { x[3]=1; n++;}
		else x[3]=0;

		if( PORT4.PIDR.BIT.B1 && PORT4.PIDR.BIT.B2 && PORT4.PIDR.BIT.B3 && PORT4.PIDR.BIT.B4 ) now=0;

		for(j=0;j<=3;j++)    // button for history
			if(history[j]!=x[j])
				{ n=0;
				history[j]=x[j]; }

		if(n>=500)
			{
				now=0;
				if(x[0]) now++;
				if(x[1]) now+=2;
				if(x[2]) now+=4;
				if(x[3]) now+=8;
				n=1000;
			}
		else if (n>=1000)
			n=3000;

    	if(!count_flag) // All has sent already.
		{
    		if(old!=now && !stack_flag) // Check whether old different from new and stack.
				{
					GET[35]='\r';
					GET[36]='\n';
					GET[25]='0';
					GET[26]='1';
					CIPSEND[11]='3';
					CIPSEND[12]='7';
					for(j=0;j<62;j++)
						GET[37+j]=0;
    				GET[34]= (now+'0');
    				flag=1;
    				old=now;
				}
    		else if(stack_flag)
    			{
    			    for(k=1;k<num;k++)
    			    	GET[33+k]=stack[k];
    				GET[33+k]='\r';
    				GET[34+k]='\n';
    				GET[25]=((num/2)/10)+'0';
    				GET[26]=((num/2)%10)+'0';
    				CIPSEND[11]=((num+35)/10)+'0';
    				CIPSEND[12]=((num+35)%10)+'0';
    				stack_flag=0;
    				k=0; num=0;
    				flag=1;
    			}
		}
    	else
    	{
    		if( GET[34]!= (now+'0') && old!=now)
    			{
    				 stack[num++]=',';
    				 stack[num++]=(now+'0');

    				old=now;
    				stack_flag=1;
    			}
    	}
         R_MAIN_COMMAND();
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

void R_MAIN_CLEAR(char *array)  // Clear command[100]
{
	for(j=0;j<100;j++)
		array[j]=0;
	i=0;
}

int FINDWORD(char *com, char *word ,int comlen, int wordlen)  // find string
{
	for(s=0;s<comlen;s++)
	{
		if( *word == *com )
			for(int l=0;l<wordlen;l++)
			{
				if( *word != *com ) {
					s+=l; word-=l;
					break; }
				else if(l==(wordlen-1))
					return 1;
				word++;
				com++;
			}
		else com++;
		if(s>=comlen)break;
	}
	return 0;
}

void R_MAIN_COMMAND(void)  // for AT command
{
   	if(flag && !count_flag)  // flag : old not same with now ; count_flag : all send already.
    	{
    		count_flag=1;  // you can start count
    		flag=0;
    		R_MAIN_CLEAR(command);
    		R_SCI5_Serial_Send(CIPSTART,39); //Send AT command to connect TCP.
    		tx_flag=0;
    		count=0;
    	}

    	  // 判斷AT指令成功與否 //
	if( FINDWORD(command,OK,i,2) )
		{
			ok_flag=1;
			if(count_flag)
				count++;
			R_MAIN_CLEAR(command);
		}
	else if( FINDWORD(command,ERROR,i,5) ) //判斷錯誤
		 {
			if(count==0)  //在指令1的錯誤 可能已經連上
			  {
				ok_flag=1;
				count++;
				R_MAIN_CLEAR(command);
			  }

		 }
	else if( FINDWORD(command,CLOSED,i,6) || FINDWORD(command,FAIL,i,4))
			count_flag=0;



	// 確定有回傳OK 才送下一個指令 //
		if(tx_flag && ok_flag)
		{
			if(count==1)
				{
					R_SCI5_Serial_Send(CIPSEND,15);
					tx_flag=0;
					ok_flag=0;
				}
			else if(count==2)
				{
					R_SCI5_Serial_Send(GET,300);
					tx_flag=0;
					ok_flag=0;
				}

		}

}

/* End user code. Do not edit comment generated here */
