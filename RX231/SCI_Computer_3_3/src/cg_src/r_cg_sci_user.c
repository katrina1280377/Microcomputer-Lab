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
* File Name    : r_cg_sci_user.c
* Version      : Code Generator for RX231 V1.00.04.01 [11 Nov 2016]
* Device(s)    : R5F52318AxFP
* Tool-Chain   : CCRX
* Description  : This file implements device driver for SCI module.
* Creation Date: 2017/10/25
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
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern uint8_t * gp_sci5_tx_address;                /* SCI5 send buffer address */
extern uint16_t  g_sci5_tx_count;                   /* SCI5 send data number */
extern uint8_t * gp_sci5_rx_address;                /* SCI5 receive buffer address */
extern uint16_t  g_sci5_rx_count;                   /* SCI5 receive data number */
extern uint16_t  g_sci5_rx_length;                  /* SCI5 receive data length */
/* Start user code for global. Do not edit comment generated here */
extern char num[8];
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_sci5_transmit_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_SCI5_TXI5
#pragma interrupt r_sci5_transmit_interrupt(vect=VECT(SCI5,TXI5),fint)
#else
#pragma interrupt r_sci5_transmit_interrupt(vect=VECT(SCI5,TXI5))
#endif
static void r_sci5_transmit_interrupt(void)
{
    if (0U < g_sci5_tx_count)
    {
        SCI5.TDR = *gp_sci5_tx_address;
        gp_sci5_tx_address++;
        g_sci5_tx_count--;
    }
    else
    {
        SCI5.SCR.BIT.TIE = 0U;
        SCI5.SCR.BIT.TEIE = 1U;
    }
}

/***********************************************************************************************************************
* Function Name: r_sci5_transmitend_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_SCI5_TEI5
#pragma interrupt r_sci5_transmitend_interrupt(vect=VECT(SCI5,TEI5),fint)
#else
#pragma interrupt r_sci5_transmitend_interrupt(vect=VECT(SCI5,TEI5))
#endif
static void r_sci5_transmitend_interrupt(void)
{
    /* Set TXD5 pin */
    PORTA.PMR.BYTE &= 0xEFU;
    SCI5.SCR.BIT.TIE = 0U;
    SCI5.SCR.BIT.TE = 0U;
    SCI5.SCR.BIT.TEIE = 0U;

    r_sci5_callback_transmitend();
}
/***********************************************************************************************************************
* Function Name: r_sci5_receive_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_SCI5_RXI5
#pragma interrupt r_sci5_receive_interrupt(vect=VECT(SCI5,RXI5),fint)
#else
#pragma interrupt r_sci5_receive_interrupt(vect=VECT(SCI5,RXI5))
#endif
static void r_sci5_receive_interrupt(void)
{
    if (g_sci5_rx_length > g_sci5_rx_count)
    {
        *gp_sci5_rx_address = SCI5.RDR;
        gp_sci5_rx_address++;
        g_sci5_rx_count++;

        if (g_sci5_rx_length <= g_sci5_rx_count)
        {
            r_sci5_callback_receiveend();
        }
    }
}
/***********************************************************************************************************************
* Function Name: r_sci5_receiveerror_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_SCI5_ERI5
#pragma interrupt r_sci5_receiveerror_interrupt(vect=VECT(SCI5,ERI5),fint)
#else
#pragma interrupt r_sci5_receiveerror_interrupt(vect=VECT(SCI5,ERI5))
#endif
static void r_sci5_receiveerror_interrupt(void)
{
    uint8_t err_type;

    r_sci5_callback_receiveerror();

    /* Clear overrun, framing and parity error flags */
    err_type = SCI5.SSR.BYTE;
    err_type &= 0xC7U;
    err_type |= 0xC0U;
    SCI5.SSR.BYTE = err_type;
}
/***********************************************************************************************************************
* Function Name: r_sci5_callback_transmitend
* Description  : This function is a callback function when SCI5 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_sci5_callback_transmitend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_sci5_callback_receiveend
* Description  : This function is a callback function when SCI5 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_sci5_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
	char sum[8]={0};    //宣告放結果的字串
	char error[7]="error\n\r";  //宣告放錯誤的字串
    int n1,n2,i,ans,count=1,temp=0,negetaive=0; //宣告各種用到的整數變數
     // n1 = 數字1 ; n2 = 數字2 ; ans = 結果 ; temp = 判斷num[3]有無錯誤 ; negetaive = 判斷減號後的正負

	n1= 100*(num[0]-'0')+10*(num[1]-'0')+(num[2]-'0'); // 寫出n1的運算,(-'0')是要char -> int
	n2= 100*(num[4]-'0')+10*(num[5]-'0')+(num[6]-'0'); // 寫出n2的運算,(-'0')是要char -> int

   if(num[7] == '=')     // 如果今天最後有打 = 開始運算
   {
	 switch(num[3])  // 判斷運算子
	 {
	 case '+':   // 加
		   	ans=n1+n2;
		 break;
	 case '-':  // 減
		 if(n2>n1) // 若小減大
		 { ans=n2-n1;
		     negetaive=1;} // 讓 negetaive=1
		 else
			 ans=n1-n2;
		 break;
	 case '*':  // 乘
		    ans=n1*n2;
		 break;
	 case '/':  // 除
		    ans=n1/n2;
		   break;
	 default:
		 temp=1; // 如果格式錯誤 , temp=1
		 break;
	   }
	 if(temp) // temp=1, 送出error
		 R_SCI5_Serial_Send(error,7);
	 else  // temp=0, 格式正確
	 {
		 int counter=ans; // counter 用來數有幾位數
	     for(int j=0;j<6;j++) //最多6位 所以至多判斷6次
	      {
	         if( (counter/10) != 0 ) // (counter/10)不等於0 代表有位數
		         { count++; //從1位數開始往上+
		         counter=counter/10; // 然後把(counter/10)往高位數繼續判斷
		         }
	         else
	        	 break; // (counter/10)=0 代表沒位數了 跳出迴圈
	      }
	     if(negetaive) //negetaive=1,有負號的情形
	     {for(i=0;i<count;i++)
	 	 {
		  sum[count-i]=ans%10+'0'; //sum從高(低位數)填至低(高位數),(+'0')是要int -> char
	 	  ans=ans/10;
	     } sum[0]='-'; //在第一位元放上 '-'
	     }
	 else
	 for(i=1;i<=count;i++)
	 	 {
		  sum[count-i]=ans%10+'0'; //sum從高(低位數)填至低(高位數),(+'0')是要int -> char
	 	  ans=ans/10;
	 	 }
	 sum[count+1]='\n'; //最後放上換行並往前
	 sum[count+2]='\r';
	 R_SCI5_Serial_Send(sum,count+3); // 顯示結果
	 }
    }
    else  // 今天最後沒有打 = 送出error
	R_SCI5_Serial_Send(error,7);

	R_SCI5_Serial_Receive(num,8); // 繼續輸入

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_sci5_callback_receiveerror
* Description  : This function is a callback function when SCI5 reception encounters error.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_sci5_callback_receiveerror(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
