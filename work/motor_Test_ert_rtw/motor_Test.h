/*
 * motor_Test.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "motor_Test".
 *
 * Model version              : 3.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Mar 21 14:30:01 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_Test_h_
#define RTW_HEADER_motor_Test_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef motor_Test_COMMON_INCLUDES_
#define motor_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "LED.h"
#endif                                 /* motor_Test_COMMON_INCLUDES_ */

#include "motor_Test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_LE_T obj; /* '<Root>/LED' */
  real_T NextOutput;                   /* '<Root>/Random Number' */
  uint32_T RandSeed;                   /* '<Root>/Random Number' */
  uint8_T Output_DSTATE;               /* '<S1>/Output' */
  boolean_T objisempty;                /* '<Root>/LED' */
} DW_motor_Test_T;

/* Parameters (default storage) */
struct P_motor_Test_T_ {
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S3>/FixPt Switch'
                                        */
  real_T RandomNumber_Mean;            /* Expression: 0
                                        * Referenced by: '<Root>/Random Number'
                                        */
  real_T RandomNumber_StdDev;         /* Computed Parameter: RandomNumber_StdDev
                                       * Referenced by: '<Root>/Random Number'
                                       */
  real_T RandomNumber_Seed;            /* Expression: 0
                                        * Referenced by: '<Root>/Random Number'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S1>/Output'
                                   */
  uint8_T Threshold_Value;             /* Computed Parameter: Threshold_Value
                                        * Referenced by: '<Root>/Threshold '
                                        */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S2>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_Test_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_motor_Test_T motor_Test_P;

/* Block states (default storage) */
extern DW_motor_Test_T motor_Test_DW;

/* Model entry point functions */
extern void motor_Test_initialize(void);
extern void motor_Test_step(void);
extern void motor_Test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_Test_T *const motor_Test_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'motor_Test'
 * '<S1>'   : 'motor_Test/Counter Limited'
 * '<S2>'   : 'motor_Test/Counter Limited/Increment Real World'
 * '<S3>'   : 'motor_Test/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_motor_Test_h_ */
