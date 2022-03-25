/*
 * motor_Test_types.h
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

#ifndef RTW_HEADER_motor_Test_types_h_
#define RTW_HEADER_motor_Test_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_FrILEhnpvhQeAYRucCAgZD
#define struct_tag_FrILEhnpvhQeAYRucCAgZD

struct tag_FrILEhnpvhQeAYRucCAgZD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  char_T IdentifierType[28];
  int32_T sockHandleDataFrames;
  int32_T sockHandleErrorFrames;
  boolean_T Initialized;
  boolean_T SetIdentifierType;
};

#endif                                 /* struct_tag_FrILEhnpvhQeAYRucCAgZD */

#ifndef typedef_codertarget_raspi_internal_CA_T
#define typedef_codertarget_raspi_internal_CA_T

typedef struct tag_FrILEhnpvhQeAYRucCAgZD codertarget_raspi_internal_CA_T;

#endif                             /* typedef_codertarget_raspi_internal_CA_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_motor_Test_T
#define typedef_cell_wrap_motor_Test_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_motor_Test_T;

#endif                                 /* typedef_cell_wrap_motor_Test_T */

#ifndef struct_tag_La5gXUeuYHSZ0kHSpmheuB
#define struct_tag_La5gXUeuYHSZ0kHSpmheuB

struct tag_La5gXUeuYHSZ0kHSpmheuB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_motor_Test_T inputVarSize;
  char_T IdentifierType[28];
  int32_T sockHandleDataFrames;
  int32_T sockHandleErrorFrames;
  boolean_T notFirstStep;
  boolean_T Initialized;
  boolean_T SetIdentifierType;
};

#endif                                 /* struct_tag_La5gXUeuYHSZ0kHSpmheuB */

#ifndef typedef_codertarget_raspi_internal__c_T
#define typedef_codertarget_raspi_internal__c_T

typedef struct tag_La5gXUeuYHSZ0kHSpmheuB codertarget_raspi_internal__c_T;

#endif                             /* typedef_codertarget_raspi_internal__c_T */

/* Parameters for system: '<Root>/CAN Receive' */
typedef struct P_CANReceive_motor_Test_T_ P_CANReceive_motor_Test_T;

/* Parameters (default storage) */
typedef struct P_motor_Test_T_ P_motor_Test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_motor_Test_T RT_MODEL_motor_Test_T;

#endif                                 /* RTW_HEADER_motor_Test_types_h_ */
