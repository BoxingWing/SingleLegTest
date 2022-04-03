/*
 * multi_motor_Test.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "multi_motor_Test".
 *
 * Model version              : 3.72
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Mar 31 11:20:34 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_multi_motor_Test_h_
#define RTW_HEADER_multi_motor_Test_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef multi_motor_Test_COMMON_INCLUDES_
#define multi_motor_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "can_motor_encoder.h"
#endif                                 /* multi_motor_Test_COMMON_INCLUDES_ */

#include "multi_motor_Test_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T abs_angle3;                   /* '<Root>/MATLAB System4' */
  real_T abs_angle2;                   /* '<Root>/MATLAB System3' */
  real_T abs_angle1;                   /* '<Root>/MATLAB System1' */
  int32_T MATLABSystem_o1[4];          /* '<Root>/MATLAB System' */
  int32_T MATLABSystem_o3;             /* '<Root>/MATLAB System' */
  uint8_T MATLABSystem2[24];           /* '<Root>/MATLAB System2' */
  uint8_T raw_Data[32];                /* '<Root>/MATLAB System' */
  uint8_T b_send_RawData[24];
  int32_T c_canID_array[3];
  boolean_T calibration_res3;          /* '<Root>/MATLAB System4' */
  boolean_T calibration_res2;          /* '<Root>/MATLAB System3' */
  boolean_T calibration_res1;          /* '<Root>/MATLAB System1' */
} B_multi_motor_Test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  MotorAngle_multi_motor_Test_T obj;   /* '<Root>/MATLAB System4' */
  MotorAngle_multi_motor_Test_T obj_f; /* '<Root>/MATLAB System3' */
  MotorAngle_multi_motor_Test_T obj_n; /* '<Root>/MATLAB System1' */
  canSendRecv_multi_motor_Test_T obj_d;/* '<Root>/MATLAB System' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MATLA;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MA_gs;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_e;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_i;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MA_nq;   /* synthesized block */

  Multi_posCtr_multi_motor_Test_T obj_n0;/* '<Root>/MATLAB System2' */
  boolean_T objisempty;                /* '<Root>/MATLAB System4' */
  boolean_T objisempty_g;              /* '<Root>/MATLAB System3' */
  boolean_T objisempty_k;              /* '<Root>/MATLAB System2' */
  boolean_T objisempty_m;              /* '<Root>/MATLAB System1' */
  boolean_T objisempty_c;              /* '<Root>/MATLAB System' */
} DW_multi_motor_Test_T;

/* Parameters (default storage) */
struct P_multi_motor_Test_T_ {
  real_T Constant1_Value[3];           /* Expression: [0,0,0]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value[3];           /* Expression: [100,100,100]
                                        * Referenced by: '<Root>/Constant3'
                                        */
  int32_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
  uint16_T Constant_Value[3];          /* Expression: [0x141,0x142,0x143]
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_multi_motor_Test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_multi_motor_Test_T multi_motor_Test_P;

/* Block signals (default storage) */
extern B_multi_motor_Test_T multi_motor_Test_B;

/* Block states (default storage) */
extern DW_multi_motor_Test_T multi_motor_Test_DW;

/* Model entry point functions */
extern void multi_motor_Test_initialize(void);
extern void multi_motor_Test_step(void);
extern void multi_motor_Test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_multi_motor_Test_T *const multi_motor_Test_M;

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
 * '<Root>' : 'multi_motor_Test'
 * '<S1>'   : 'multi_motor_Test/rawData_decoder'
 */
#endif                                 /* RTW_HEADER_multi_motor_Test_h_ */
