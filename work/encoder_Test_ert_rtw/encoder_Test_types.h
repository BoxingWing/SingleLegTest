/*
 * encoder_Test_types.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "encoder_Test".
 *
 * Model version              : 3.72
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Apr  2 16:27:14 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_encoder_Test_types_h_
#define RTW_HEADER_encoder_Test_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_FIVpFXZq8dV57OZtpFzMZC
#define struct_tag_FIVpFXZq8dV57OZtpFzMZC

struct tag_FIVpFXZq8dV57OZtpFzMZC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_FIVpFXZq8dV57OZtpFzMZC */

#ifndef typedef_canSendRecv_encoder_Test_T
#define typedef_canSendRecv_encoder_Test_T

typedef struct tag_FIVpFXZq8dV57OZtpFzMZC canSendRecv_encoder_Test_T;

#endif                                 /* typedef_canSendRecv_encoder_Test_T */

#ifndef struct_tag_QYYgC9m6ZLb4lpMjqhspqH
#define struct_tag_QYYgC9m6ZLb4lpMjqhspqH

struct tag_QYYgC9m6ZLb4lpMjqhspqH
{
  real_T offset_Num;
  real_T itr_count;
};

#endif                                 /* struct_tag_QYYgC9m6ZLb4lpMjqhspqH */

#ifndef typedef_posCtr_and_offset_encoder_Tes_T
#define typedef_posCtr_and_offset_encoder_Tes_T

typedef struct tag_QYYgC9m6ZLb4lpMjqhspqH posCtr_and_offset_encoder_Tes_T;

#endif                             /* typedef_posCtr_and_offset_encoder_Tes_T */

/* Parameters (default storage) */
typedef struct P_encoder_Test_T_ P_encoder_Test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_encoder_Test_T RT_MODEL_encoder_Test_T;

#endif                                 /* RTW_HEADER_encoder_Test_types_h_ */
