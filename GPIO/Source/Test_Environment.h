/*
 * Copyright(C) 2022 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 *
 */
 
// ET-VPF F1KM Product Version - V1.00.00 - Req. 01
// ID: ET_VPF_V1.00.00_CD_Req_01_012
// Reference: {ET_VPF_V1.00.00_UD_Req_01_001, ET_VPF_V1.00.00_UD_Req_01_002, ET_VPF_V1.00.00_UD_Req_01_004}

#ifndef TEST_ENVIRONMENT_H
#define TEST_ENVIRONMENT_H

/*Common header*/
#include <stddef.h>
#include "rtwtypes.h"
#include "iodefine.h"
#include "r_cg_macrodriver.h"
#include "OSTM_define.h"
#include <math.h>
#include <stdlib.h>
/* Include Section */

/* Defines */
#define EI()      __EI()
#define _OSTM_COUNTER_STOP                  (0x01U) /* OSTM: Stop the counter*/
#define _OSTM_COUNTER_START                 (0x01U) /* OSTM: Starts the counter */
#define _INTERVAL_TIME_START                (0x81)
#define PORT_BASE  0xFFC10000
#define Pn(n)       (*(volatile unsigned short *)(PORT_BASE + 0x0000 + n*0x4))
#define PPRn(n)     (*(volatile unsigned short *)(PORT_BASE + 0x0200 + n*0x4))
#define MAX_VIRTUAL_CHANNEL 36

/* write key code protection register */
#define protected_write_pseudo(preg, reg, value) preg = 0xA5A5A501ul;

/* Global variables */
extern unsigned char GaaTestResult[200];
extern unsigned char GucCurrentTestPoint;
// ET-VPF F1KM Product Version - V1.00.00 - Req. 04
// ID: ET_VPF_V1.00.00_CD_Req_04_024
// Reference: {ET_VPF_V1.00.00_UD_Req_04_001, ET_VPF_V1.00.00_UD_Req_04_002, ET_VPF_V1.00.00_UD_Req_04_004, ET_VPF_V1.00.00_UD_Req_04_005, ET_VPF_V1.00.00_UD_Req_04_006, ET_VPF_V1.00.00_UD_Req_04_007}
extern unsigned int GMemForSetPortRxControl1;
extern volatile struct __tag443 * RLIN3n_reg;
extern volatile struct __tag443 * arr_RLIN3n[4];
extern int send_arr[4];
extern int receive_arr[4];
// ET-VPF F1KM Product Version - V1.00.00 - Req. 04 - End
// ET-VPF F1KM Product Version - V1.00.00 - Req. Supporting ADC unit 1 for F1KM-S4
// ID: ET_VPF_V1.00.00_CD_Req_ADCUnit1_013 
// Reference: {ET_VPF_V1.00.00_UD_Req_ADCUnit1_001, ET_VPF_V1.00.00_UD_Req_ADCUnit1_002, ET_VPF_V1.00.00_UD_Req_ADCUnit1_003, ET_VPF_V1.00.00_UD_Req_ADCUnit1_004, ET_VPF_V1.00.00_UD_Req_ADCUnit1_005, ET_VPF_V1.00.00_UD_Req_ADCUnit1_006, ET_VPF_V1.00.00_UD_Req_ADCUnit1_007}
extern int adc_arr[1];

/* Function Prototypes */
extern void Config_ADC_ScanGroup1_OperationOn(unsigned int unitIndex);
extern float Config_ADC_ScanGroup1_GetResult(unsigned int unitIndex, char unit, char portID);
extern int get_physical_channel_index(char unit_, char portID_);
extern void set_start_end_pointer(char unit, uint32_t * startPointer, uint32_t * endPointer);
extern unsigned long get_adc_base_address(char unit);
extern void Wait_For_Conversion(char unit);
// ET-VPF F1KM Product Version - V1.00.00 - Req. Supporting ADC unit 1 for F1KM-S4 - End
extern void Mcu_Init(void);
extern void R_OSTM0_Create(void);
extern void R_OSTM0_Start(void);
// ET-VPF F1KM Product Version - V1.00.00 - Req. 04
// ID: ET_VPF_V1.00.00_CD_Req_04_025
// Reference: {ET_VPF_V1.00.00_UD_Req_04_001, ET_VPF_V1.00.00_UD_Req_04_002, ET_VPF_V1.00.00_UD_Req_04_004, ET_VPF_V1.00.00_UD_Req_04_005, ET_VPF_V1.00.00_UD_Req_04_006, ET_VPF_V1.00.00_UD_Req_04_007}
extern void Config_UART_Transmission_Send(unsigned int index, uint8_t * const tx_buf, uint16_t tx_num);
extern void Config_UART_Reception_Receive(unsigned int index, uint8_t * const rx_buf, uint16_t rx_num);
// ET-VPF F1KM Product Version - V1.00.00 - Req. 04 - End

extern void Set_port_value(boolean_T *u0, unsigned char port, unsigned char pin);
extern void Get_port_value(boolean_T *y0, unsigned char port, unsigned char pin);
// ET-VPF F1KM Product Version - V1.00.00 - Req. 03
// ID: ET_VPF_V1.00.00_CD_Req_03_015
// Reference: {ET_VPF_V1.00.00_UD_Req_03_001, ET_VPF_V1.00.00_UD_Req_03_002, ET_VPF_V1.00.00_UD_Req_03_003 ,ET_VPF_V1.00.00_UD_Req_03_004, ET_VPF_V1.00.00_UD_Req_03_007} 
extern void Config_TAUD_Start(void);
extern void Config_TAUD_Stop(void);
extern void Update_PWM_duty(const real_T value[]);
extern void Update_Triangle_PWM_duty(const real_T value[]);
extern void Update_PWM_master_pulse(long double value);
extern double calculate_clock_scale(int taud_tps);

// ET-VPF F1KM Product Version - V1.00.00 - Req. 03 - End
// /* Interrupt init function */

// /* Interrupt handler function */
extern void eiint84(void); // OSTM0 for synchronizing

#endif /* TEST_ENVIRONMENT_H */

/* End of file */
// ET-VPF F1KM Product Version - V1.00.00 - Req. 01 - End