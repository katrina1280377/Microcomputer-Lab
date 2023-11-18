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
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G12 V2.03.04.01 [11 Nov 2016]
* Device(s)    : R5F1026A
* Tool-Chain   : GCCRL78
* Description  : This file implements main function.
* Creation Date: 2018/4/10
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

extern int tx_flag,i,sec;
extern char command[100];

char rx[1]={0},s[500]={0};
int now=0,old=0,j,l,count=0,n=0,history[4]={0},x[4]={0},num=0,k=0,no,t;
char TIME[21]="2018-04-10%2022:30:10";

const char OK[2]="OK";
const char time[5]="time=";
const char ERROR[5]="ERROR";
const char CLOSED[6]="CLOSED";
const char FAIL[4]="FAIL";
// flags
int flag=1,ok_flag=0,count_flag=0,stack_flag=0;

//commands
const char CIPSTART[39]="AT+CIPSTART=\"TCP\",\"140.125.49.210\",80\r\n";
char GET[500]="Get /bear/time.php?count=000&state=0010,2018-04-11%2010:40:39\r\n";
char CIPSEND[16]="AT+CIPSEND=063\r\n";

/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

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
    R_UART0_Create();
    R_UART0_Start();
    R_PORT_Create();
    R_TAU0_Create();
    R_TAU0_Channel0_Start();

    R_UART0_Receive(rx,1);
    while (1U)
    {
    	no=0;
    	// 以下為按鈕(訊號)判斷
    	if( P2_bit.no0==0 ) { x[0]=1; n++;}
		else x[0]=0;
		if( P2_bit.no1==0 ) { x[1]=1; n++;}
		else x[1]=0;
		if( P2_bit.no2==0 ) { x[2]=1; n++;}
		else x[2]=0;
		if( P2_bit.no3==0 ) { x[3]=1; n++;}
		else x[3]=0;

		if( P6_bit.no0==0 ) no++;
		if( P6_bit.no1==0 ) no+=2;
		if( P4_bit.no1==0 ) no+=4;
		if( P4_bit.no2==0 ) no+=8;
		if( P12_bit.no1==0 ) no+=16;
		if( P12_bit.no2==0 ) no+=32;
		if( P13_bit.no7==0 ) no+=64;

		GET[35]= (no/100+'0');
		GET[36]= ((no/10)%10+'0');
		GET[37]= (no%10+'0');

		if( P2_bit.no0 && P2_bit.no1 && P2_bit.no2 && P2_bit.no3 ) now=0;

		for(j=0;j<=3;j++)
			if(history[j]!=x[j])
				{ n=0; history[j]=x[j]; }

		if(n>=300 && n<2000)
			{
				now=0;
				if(x[0]) now++;
				if(x[1]) now+=2;
				if(x[2]) now+=4;
				if(x[3]) now+=8;
				n=2000;
			}
		else if (n>=2000)
			n=2000;


		if(!count_flag) // All has sent already.
		{
			if(old!=now && !stack_flag) // Check whether old different from new and stack.
				{

					GET[25]='0';
					GET[26]='0';
					GET[27]='1';
					CIPSEND[11]='0';
					CIPSEND[12]='6';
					CIPSEND[13]='3';
					for(j=0;j<465;j++)
						GET[35+j]=0;
					GET[38]=(now+'0');
					GET[39]=',';
					for(j=0;j<21;j++)
						GET[40+j]=TIME[j];
					GET[61]='\r';
					GET[62]='\n';
					flag=1;
					old=now;
				}
			 else if(stack_flag)
				{
					for(k=1;k<num;k++)
						GET[34+k]=s[k];
					GET[34+k]='\r';
					GET[35+k]='\n';
					GET[25]=((num/25)/100)+'0';
					GET[26]=((num/250)%10)+'0';
					GET[27]=((num/25)%10)+'0';
					CIPSEND[11]=((num+36)/100)+'0';
					CIPSEND[12]=(((num+36)/10)%10)+'0';
					CIPSEND[13]=((num+36)%10)+'0';
					stack_flag=0;
					k=0; num=0;
					flag=1;
				}
			}
		else
			{
				if( GET[36]!= (now+'0') && old!=now)
					{
						 s[num++]=',';
						 s[num++]=(no/100+'0');
						 s[num++]=((no/10)%10+'0');
						 s[num++]=(no%10+'0');
						 s[num++]=(now + '0');
						 s[num++]=',';
						 for(j=0;j<21;j++)
							 s[num++]=TIME[j];
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
    EI();
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
	for(j=0;j<comlen;j++)
	{
		if( *word == *com )
			for(l=0;l<wordlen;l++)
			{
				if( *word != *com ) {
					j+=l; word-=l;
					break; }
				else if(l==(wordlen-1)){
					t=j+l+1;
					return 1;
				}
				word++;
				com++;
			}
		else com++;
		if(j>=comlen)break;
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
    		R_UART0_Send(CIPSTART,39); //Send AT command to connect TCP.
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
			else
			{
				ok_flag=0;
				R_MAIN_CLEAR(command);
				R_UART0_Send(CIPSTART,39);
				tx_flag=0;
				count=0;
			}
		 }
	else if( FINDWORD(command,CLOSED,i,6) || FINDWORD(command,FAIL,i,4))
			{ count_flag=0;
			  ok_flag=0;
			}
	else if( FINDWORD(command,time,i,5))
			{   sec=0;
		    	for(j=0;j<19;j++)
		    		TIME[j]=command[t+j];
			}

	// 確定有回傳OK 才送下一個指令 //
		if(tx_flag && ok_flag)
		{
			if(count==1)
				{
				    R_UART0_Send(CIPSEND,16);
					tx_flag=0;
					ok_flag=0;
				}
			else if(count==2)
				{
				    R_UART0_Send(GET,500);
					tx_flag=0;
					ok_flag=0;
				}
		}

}

/* End user code. Do not edit comment generated here */
