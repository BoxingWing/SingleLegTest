/*
 * motor_Test.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "motor_Test".
 *
 * Model version              : 3.63
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Mar 30 16:59:54 2022
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
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef motor_Test_COMMON_INCLUDES_
#define motor_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "can_motor_encoder.h"
#endif                                 /* motor_Test_COMMON_INCLUDES_ */

#include "motor_Test_types.h"

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
  real_T abs_angle;                    /* '<Root>/MATLAB System1' */
  real_T y;                            /* '<Root>/MATLAB Function1' */
  real_T y_l;                          /* '<Root>/MATLAB Function' */
  int32_T MATLABSystem_o1[4];          /* '<Root>/MATLAB System' */
  int32_T MATLABSystem_o3;             /* '<Root>/MATLAB System' */
  uint8_T raw_Data[32];                /* '<Root>/MATLAB System' */
  boolean_T calibration_res;           /* '<Root>/MATLAB System1' */
} B_motor_Test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  MotorAngle_motor_Test_T obj;         /* '<Root>/MATLAB System1' */
  posCtr_and_offset_motor_Test_T obj_m;/* '<Root>/MATLAB System3' */
  canSendRecv_motor_Test_T obj_d;      /* '<Root>/MATLAB System' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MATLA;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_e;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_i;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_n;   /* synthesized block */

  boolean_T objisempty;                /* '<Root>/MATLAB System3' */
  boolean_T objisempty_m;              /* '<Root>/MATLAB System1' */
  boolean_T objisempty_c;              /* '<Root>/MATLAB System' */
} DW_motor_Test_T;

/* Parameters (default storage) */
struct P_motor_Test_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  uint16_T Constant_Value[2];          /* Expression: [0x142,0x142]
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_Test_T {
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
extern P_motor_Test_T motor_Test_P;

/* Block signals (default storage) */
extern B_motor_Test_T motor_Test_B;

/* Block states (default storage) */
extern DW_motor_Test_T motor_Test_DW;

/* Model entry point functions */
extern void motor_Test_initialize(void);
extern void motor_Test_step(void);
extern void motor_Test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_Test_T *const motor_Test_M;

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
 * '<S1>'   : 'motor_Test/MATLAB Function'
 * '<S2>'   : 'motor_Test/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_motor_Test_h_ */
