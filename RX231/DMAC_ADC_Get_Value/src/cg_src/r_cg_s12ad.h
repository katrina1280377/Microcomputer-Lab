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
* File Name    : r_cg_s12ad.h
* Version      : Code Generator for RX231 V1.00.04.01 [11 Nov 2016]
* Device(s)    : R5F52318AxFP
* Tool-Chain   : CCRX
* Description  : This file implements device driver for S12AD module.
* Creation Date: 2017/12/14
***********************************************************************************************************************/
#ifndef S12AD_H
#define S12AD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    A/D control register (ADCSR)
*/
/* Group B scan end interrupt enable (GBADIE) */
#define _0000_AD_GBADI_DISABLE               (0x0000U) /* Disables GBADI interrupt generation upon group B scan
                                                          completion */
#define _0040_AD_GBADI_ENABLE                (0x0040U) /* Enables GBADI interrupt generation upon group B scan
                                                          completion */
/* Double trigger mode select (DBLE) */
#define _0000_AD_DBLTRIGGER_DISABLE          (0x0000U) /* Disable double trigger mode */
#define _0080_AD_DBLTRIGGER_ENABLE           (0x0080U) /* Enable double trigger mode */
/* Trigger select (EXTRG) */
#define _0000_AD_SYNC_TRIGGER                (0x0000U) /* A/D conversion started by synchronous trigger */
#define _0100_AD_ASYNC_TRIGGER               (0x0100U) /* A/D conversion started by asynchronous trigger */
/* Trigger start enable (TRGE) */
#define _0000_AD_SYNCASYNCTRG_DISABLE        (0x0000U) /* A/D conversion synchronous or asynchronous trigger disable */
#define _0200_AD_SYNCASYNCTRG_ENABLE         (0x0200U) /* A/D conversion synchronous or asynchronous trigger enable */
/* A/D Conversion Select (ADHSC) */
#define _0000_AD_HIGH_SPEED                  (0x0000U) /* High-speed conversion */
#define _0400_AD_LOW_CURRENT                 (0x0400U) /* Low-current conversion */
/* Scan end interrupt enable (ADIE) */
#define _0000_AD_SCAN_END_INTERRUPT_DISABLE  (0x0000U) /* Disable S12ADI0 interrupt generation upon scan completion */
#define _1000_AD_SCAN_END_INTERRUPT_ENABLE   (0x1000U) /* Enable S12ADI0 interrupt generation upon scan completion */
/* Scan mode select (ADCS) */
#define _0000_AD_SINGLE_SCAN_MODE            (0x0000U) /* Single scan mode */
#define _2000_AD_GROUP_SCAN_MODE             (0x2000U) /* Group scan mode */
#define _4000_AD_CONTINUOUS_SCAN_MODE        (0x4000U) /* Continuous scan mode */
/* A/D conversion start (ADST) */
#define _0000_AD_CONVERSION_STOP             (0x0000U) /* Stop A/D conversion */
#define _8000_AD_CONVERSION_START            (0x8000U) /* Start A/D conversion */

/*
    A/D converted value addition count select register (ADADC)
*/
/* Addition Count Select ADC[2:0] */
#define _00_AD_1_TIME_CONVERSION             (0x00U) /* 1-time conversion */
#define _01_AD_2_TIME_CONVERSION             (0x01U) /* 2-time conversion */
#define _02_AD_3_TIME_CONVERSION             (0x02U) /* 3-time conversion */
#define _03_AD_4_TIME_CONVERSION             (0x03U) /* 4-time conversion */
#define _05_AD_16_TIME_CONVERSION            (0x05U) /* 16-time conversion */
/* Average Mode Enable bit (AVEE) */
#define _00_AD_ADDITION_MODE                 (0x00U) /* Addition mode */
#define _80_AD_AVERAGE_MODE                  (0x80U) /* Average mode */

/*
    A/D control extended register (ADCER)
*/
/* Automatic clearing enable (ACE) */
#define _0000_AD_AUTO_CLEARING_DISABLE       (0x0000U) /* Disable auto clearing */
#define _0020_AD_AUTO_CLEARING_ENABLE        (0x0020U) /* Enable auto clearing */
/* A/D Self-diagnosis selection (DIAGVAL) */
#define _0000_AD_SELFTDIAGST_DISABLE         (0x0000U) /* Disable self-diagnosis */
#define _0100_AD_SELFTDIAGST_VREFH0_0        (0x0100U) /* Self-diagnosis using a voltage of 0V */
#define _0200_AD_SELFTDIAGST_VREFH0_HALF     (0x0200U) /* Self-diagnosis using a voltage of VREFH0_1/2 */
#define _0300_AD_SELFTDIAGST_VREFH0          (0x0300U) /* Self-diagnosis using a voltage of VREFH0_1 */

/* A/D Self-diagnostic mode selection (DIAGLD) */
#define _0000_AD_SELFTDIAGST_ROTATION        (0x0000U) /* Rotation mode for self-diagnosis voltage */
#define _0400_AD_SELFTDIAGST_FIX             (0x0400U) /* Fixed mode for self-diagnosis voltage */
/* A/D Self-diagnostic enable (DIAGM) */
#define _0000_AD_SELFTDIAGST_DISABLE         (0x0000U) /* 12-bit self-diagnosis disable */
#define _0800_AD_SELFTDIAGST_ENABLE          (0x0800U) /* 12-bit self-diagnosis enable */
/* A/D data register format selection (ADRFMT) */
#define _0000_AD_RIGHT_ALIGNMENT             (0x0000U) /* Right-alignment for data register format */
#define _8000_AD_LEFT_ALIGNMENT              (0x8000U) /* Left-alignment for data register format */

/*
    A/D start trigger select register (ADSTRGR)
*/
/* A/D conversion start trigger select for group B (TRSB) */
#define _0001_AD_TRSB_TRG0AN                 (0x0001U) /* Compare match with or input capture from MTU0.TGRA */
#define _0002_AD_TRSB_TRG0BN                 (0x0002U) /* Compare match with or input capture from MTU0.TGRB */
#define _0003_AD_TRSB_TRGAN                  (0x0003U) /* Compare match with or input capture from MTU0 to MTU4.TGRA or 
                                                           underflow (trough) of MTU4.TCNT in complementary PWM mode */
#define _0004_AD_TRSB_TRG0EN                 (0x0004U) /* Compare match from MTU0.TGRE */
#define _0005_AD_TRSB_TRG0FN                 (0x0005U) /* Compare match from MTU0.TGRF */
#define _0006_AD_TRSB_TRG4AN                 (0x0006U) /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _0007_AD_TRSB_TRG4BN                 (0x0007U) /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _0008_AD_TRSB_TRG4ABN                (0x0008U) /* Compare match between MTU4.TADCORA and MTU4.TCNT or
                                                           compare match between MTU4.TADCORB and MTU4.TCNT */
#define _000D_AD_TRSB_TRGAN1                 (0x000DU) /* Compare match with or input capture from TPUn.TGRAn(n=0 to 4) */
#define _000E_AD_TRSB_TRG4ABN1               (0x000EU) /* Compare match with or input capture from TPU0.TGRA */
#define _0009_AD_TRSB_ELCTRG0N               (0x0009U) /* Trigger from ELC */
/* A/D conversion start trigger select for group A (TRSA) */
#define _0000_AD_TRSA_ADTRG                  (0x0000U) /* Input pin for the trigger */
#define _0100_AD_TRSA_TRG0AN                 (0x0100U) /* Compare match with or input capture from MTU0.TGRA */
#define _0200_AD_TRSA_TRG0BN                 (0x0200U) /* Compare match with or input capture from MTU0.TGRB */
#define _0300_AD_TRSA_TRGAN                  (0x0300U) /* Compare match with or input capture from MTU0 to MTU4.TGRA or 
                                                           underflow (trough) of MTU4.TCNT in complementary PWM mode */
#define _0400_AD_TRSA_TRG0EN                 (0x0400U) /* Compare match from MTU0.TGRE */
#define _0500_AD_TRSA_TRG0FN                 (0x0500U) /* Compare match from MTU0.TGRF */
#define _0600_AD_TRSA_TRG4AN                 (0x0600U) /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _0700_AD_TRSA_TRG4BN                 (0x0700U) /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _0800_AD_TRSA_TRG4ABN                (0x0800U) /* Compare match between MTU4.TADCORA and MTU4.TCNT or
                                                           compare match between MTU4.TADCORB and MTU4.TCNT */
#define _0D00_AD_TRSA_TRGAN1                 (0x0D00U) /* Compare match with or input capture from TPUn.TGRAn(n=0 to 4) */
#define _0E00_AD_TRSA_TRG4ABN1               (0x0E00U) /* Compare match with or input capture from TPU0.TGRA */
#define _0900_AD_TRSA_ELCTRG0N               (0x0900U) /* Trigger from ELC */

/*
    A/D converted extended input control register (ADEXICR)
*/
/* Temperature sensor output A/D conversion value addition mode selection (TSSAD) */
#define _0000_AD_TEMP_ADDITION_DISABLE       (0x0000U) /* Temperature sensor output A/D converted value addition/average
                                                          mode disabled */
#define _0001_AD_TEMP_ADDITION_ENABLE        (0x0001U) /* Temperature sensor output A/D converted value addition/average
                                                          mode enabled */
/* Internal reference voltage A/D conversion value addition mode select (OCSAD) */
#define _0000_AD_IREF_ADDITION_DISABLE       (0x0000U) /* Internal ref. voltage A/D converted value addition/average 
                                                          mode disabled */
#define _0002_AD_IREF_ADDITION_ENABLE        (0x0002U) /* Internal ref. voltage A/D converted value addition/average
                                                           mode enabled */
/* Temperature sensor output A/D conversion select (TSSA) */
#define _0000_AD_TEMP_GROUPA_DISABLE         (0x0000U) /* A/D conversion of temperature sensor output is disabled in 
                                                          group A  */
#define _0100_AD_TEMP_GROUPA_ENABLE          (0x0100U) /* A/D conversion of temperature sensor output is enabled in 
                                                          group A  */
/* Internal reference voltage A/D conversion select (OCSA) */
#define _0000_AD_IREF_GROUPA_DISABLE         (0x0000U) /* A/D conversion of internal reference voltage is disabled in 
                                                          group A  */
#define _0200_AD_IREF_GROUPA_ENABLE          (0x0200U) /* A/D conversion of internal reference voltage is enabled in 
                                                          group A  */

/*
    A/D Event Link Control Register (ADELCCR)
*/
/* Event Link Control (ELCC[1:0]) */
#define _00_NOT_GROUPB_SCAN_COMPLETION       (0x00U) /* Event is generated on completion of the scan other than group B in group scan mode */
#define _01_GROUPB_SCAN_COMPLETION           (0x01U) /* Event is generated on completion of the scan of group B in group scan mode */
#define _02_ALL_SCAN_COMPLETION              (0x02U) /* Event is generated on completion of all scans */

/*
    A/D Group Scan Priority Control Register (ADGSPCR)
*/
/* Group-A Priority Control Setting (PGS) */
#define _0000_AD_GPAPRIORITY_DISABLE         (0x0000U) /* Operation is without group A priority control */
#define _0001_AD_GPAPRIORITY_ENABLE          (0x0001U) /* Operation is with group A priority control */
/* Group B Restart Setting (GBRSCN) */
#define _0000_AD_GPBRESTART_DISABLE          (0x0000U) /* Group B not restart after discontinued due to Group A
                                                          priority */
#define _0002_AD_GPBRESTART_ENABLE           (0x0002U) /* Group B restart after discontinued due to Group A priority */
/* Group B Single Cycle Scan Continuous Start (GBRP) */
#define _0000_AD_GPBSCSCS_DISABLE            (0x0000U) /* Single cycle scan for group B not continuously activated */
#define _8000_AD_GPBSCSCS_ENABLE             (0x8000U) /* Single cycle scan for group B is continuously activated */

/* 
    A/D High-Potential/Low-Potential Reference Voltage Control Register (ADHVREFCNT)
*/
/* High-Potential Reference Voltage Select (HVSEL) */
#define _00_AD_HIGH_POTENTIAL_AVCC0          (0x00U) /* AVCC0 is selected as the high-potential reference voltage. */ 
#define _01_AD_HIGH_POTENTIAL_VREFH0         (0x01U) /* VREFH0 is selected as the high-potential reference voltage. */
/* Low-Potential Reference Voltage Select (LVSEL) */
#define _00_AD_LOW_POTENTIAL_AVSS0           (0x00U) /* AVSS0 is selected as the low-potential reference voltage. */ 
#define _10_AD_LOW_POTENTIAL_VREFL0          (0x10U) /* VREFL0 is selected as the low-potential reference voltage. */

/* 
    A/D Compare Control Register (ADCMPCR)
*/
/* Window Function Setting (WCMPE) */
#define _0000_AD_WINDOW_DISABLE              (0x0000U) /* Window function disabled */ 
#define _4000_AD_WINDOW_ENABLE               (0x4000U) /* Window function enabled */
/* Window A Function Setting (CMPAE) */
#define _0000_AD_WINDOWA_DISABLE             (0x0000U) /* Window function A disabled */ 
#define _0800_AD_WINDOWA_ENABLE              (0x0800U) /* Window function A enabled */
/* Window B Function Setting (CMPBE) */
#define _0000_AD_WINDOWB_DISABLE             (0x0000U) /* Window function B disabled */ 
#define _0200_AD_WINDOWB_ENABLE              (0x0200U) /* Window function B enabled */
/* Window A/B Composite Condition Setting (CMPAB[1:0]) */
#define _0000_S12ADWMELC_CONDITION_OR        (0x0000U) /* S12ADWMELC is output when window A comparison conditions are met OR
                                                        window B comparison conditions are met.
                                                        S12ADWUMELC is output in other cases. */ 
#define _0001_S12ADWMELC_CONDITION_EXOR      (0x0001U) /* S12ADWMELC is output when window A comparison conditions are met EXOR
                                                        window B comparison conditions are met.
                                                        S12ADWUMELC is output in other cases. */ 
#define _0002_S12ADWMELC_CONDITION_AND       (0x0002U) /* S12ADWMELC is output when window A comparison conditions are met AND
                                                        window B comparison conditions are met.
                                                        S12ADWUMELC is output in other cases. */ 

/* 
    A/D Compare Function Window A Extended Input Select Register (ADCMPANSER)
*/
/* Temperature Sensor Output Compare Select(CMPTSA) */
#define _00_AD_TEMP_COMPARE_DISABLE          (0x00U) /* Temperature sensor output is not a target for compare window A */ 
#define _01_AD_TEMP_COMPARE_ENABLE           (0x01U) /* Temperature sensor output is a target for compare window A */
/* Internal Reference Voltage Compare Select (CMPOCA) */
#define _00_AD_IREF_COMPARE_DISABLE          (0x00U) /* Internal reference voltage is not a target for compare window A */ 
#define _02_AD_IREF_COMPARE_ENABLE           (0x02U) /* Internal reference voltage is a target for compare window A */

/* 
    A/D Compare Function Window A Extended Input Comparison Condition Setting Register (ADCMPLER)
*/
/* Compare Window A Temperature Sensor Output Comparison Condition Select (CMPLTSA) */
#define _00_AD_TEMP_AD_TEMP_COMPARELEVEL     (0x00U) /* AD-converted value < ADCMPDR0 register value or A/D-converted
                                                      value > ADCMPDR1 register value */ 
#define _01_AD_TEMP_AD_TEMP_COMPARELEVEL     (0x01U) /* ADCMPDR0 register value < A/D-converted value < ADCMPDR1
                                                      register value */
/* Internal Reference Voltage Comparison Condition Select (CMPLOCA) */
#define _00_AD_TEMP_AD_IREF_COMPARELEVEL     (0x00U) /* AD-converted value < ADCMPDR0 register value or A/D-converted
                                                      value > ADCMPDR1 register value */ 
#define _02_AD_TEMP_AD_IREF_COMPARELEVEL     (0x02U) /* ADCMPDR0 register value < A/D-converted value < ADCMPDR1
                                                      register value */

/* 
    A/D Data Storage Buffer Enable Register (ADBUFEN)
*/
/* Data Storage Buffer Enable (BUFEN) */
#define _00_AD_STORAGE_BUFF_UNUSED           (0x00U) /* The data storage buffer is not used. */
#define _01_AD_STORAGE_BUFF_USED             (0x01U) /* The data storage buffer is used. */

/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _00_AD_PRIORITY_LEVEL0               (0x00U) /* Level 0 (interrupt disabled) */
#define _01_AD_PRIORITY_LEVEL1               (0x01U) /* Level 1 */
#define _02_AD_PRIORITY_LEVEL2               (0x02U) /* Level 2 */
#define _03_AD_PRIORITY_LEVEL3               (0x03U) /* Level 3 */
#define _04_AD_PRIORITY_LEVEL4               (0x04U) /* Level 4 */
#define _05_AD_PRIORITY_LEVEL5               (0x05U) /* Level 5 */
#define _06_AD_PRIORITY_LEVEL6               (0x06U) /* Level 6 */
#define _07_AD_PRIORITY_LEVEL7               (0x07U) /* Level 7 */
#define _08_AD_PRIORITY_LEVEL8               (0x08U) /* Level 8 */
#define _09_AD_PRIORITY_LEVEL9               (0x09U) /* Level 9 */
#define _0A_AD_PRIORITY_LEVEL10              (0x0AU) /* Level 10 */
#define _0B_AD_PRIORITY_LEVEL11              (0x0BU) /* Level 11 */
#define _0C_AD_PRIORITY_LEVEL12              (0x0CU) /* Level 12 */
#define _0D_AD_PRIORITY_LEVEL13              (0x0DU) /* Level 13 */
#define _0E_AD_PRIORITY_LEVEL14              (0x0EU) /* Level 14 */
#define _0F_AD_PRIORITY_LEVEL15              (0x0FU) /* Level 15 (highest) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _0001_AD_CHANNEL_SELECT_A0           (0x0001U) /* Channel select register A0 value */
#define _0000_AD_CHANNEL_SELECT_A1           (0x0000U) /* Channel select register A1 value */
#define _0000_AD_ADDAVG_CHANNEL_SELECT0      (0x0000U) /* Converted value add/average function select register 0 */
#define _0000_AD_ADDAVG_CHANNEL_SELECT1      (0x0000U) /* Converted value add/average function select register 1 */
#define _00_AD_DISCONECT_SETTING             (0x00U) /* Disconnection detection assist setting */
#define _C6_AD_SAMPLING_STATE_0              (0xC6U) /* AN000 sampling state register value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    ADCHANNEL0, ADCHANNEL1, ADCHANNEL2, ADCHANNEL3, ADCHANNEL4, ADCHANNEL5, ADCHANNEL6,
    ADCHANNEL7, ADCHANNEL16, ADCHANNEL17, ADCHANNEL18, ADCHANNEL19, ADCHANNEL20,
    ADCHANNEL21, ADCHANNEL22, ADCHANNEL23, ADCHANNEL24, ADCHANNEL25, ADCHANNEL26,
    ADCHANNEL27, ADCHANNEL28, ADCHANNEL29, ADCHANNEL30, ADCHANNEL31, ADSELFDIAGNOSIS,
    ADTEMPSENSOR, ADINTERREFVOLT,ADDATADUPLICATION
} ad_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_S12AD_Create(void);
void R_S12AD_Start(void);
void R_S12AD_Stop(void);
void R_S12AD_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
