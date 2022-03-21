/*
 * motor_Test_data.c
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

#include "motor_Test.h"
#include "motor_Test_private.h"

/* Block parameters (default storage) */
P_motor_Test_T motor_Test_P = {
  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S3>/FixPt Switch'
   */
  10U,

  /* Expression: 0
   * Referenced by: '<Root>/Random Number'
   */
  0.0,

  /* Computed Parameter: RandomNumber_StdDev
   * Referenced by: '<Root>/Random Number'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Random Number'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S3>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S1>/Output'
   */
  0U,

  /* Computed Parameter: Threshold_Value
   * Referenced by: '<Root>/Threshold '
   */
  7U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S2>/FixPt Constant'
   */
  1U
};
