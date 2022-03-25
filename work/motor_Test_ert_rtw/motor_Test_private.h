/*
 * motor_Test_private.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "motor_Test".
 *
 * Model version              : 3.20
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 24 16:26:16 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_Test_private_h_
#define RTW_HEADER_motor_Test_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "motor_Test.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void motor_Test_CANReceive_Start(B_CANReceive_motor_Test_T *localB,
  DW_CANReceive_motor_Test_T *localDW, P_CANReceive_motor_Test_T *localP);
extern void motor_Test_CANReceive(B_CANReceive_motor_Test_T *localB,
  DW_CANReceive_motor_Test_T *localDW, P_CANReceive_motor_Test_T *localP);
extern void motor_Test_CANReceive_Term(DW_CANReceive_motor_Test_T *localDW);

#endif                                 /* RTW_HEADER_motor_Test_private_h_ */
