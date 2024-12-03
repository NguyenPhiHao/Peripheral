/*
 * Copyright(C) 2022 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "iodefine.h"
#include "r_cg_macrodriver.h"
#include "Test_Environment.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void set_Port_Data_Outputs_wrapper(boolean_T *u0,
            boolean_T *y0,
            const real_T *port, const int_T p_width0,
            const real_T *pin, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
# ifdef ETVPF
    // Generated source code
    char portType = (char)*port;
    char pinType = (char)*pin;
    Set_port_value(u0, portType, pinType);
# else
    // Execute on MATLAB
    y0[0] = u0[0];
# endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


