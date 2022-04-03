/*
 * encoder_Test.c
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

#include "encoder_Test.h"
#include "encoder_Test_private.h"

/* Block signals (default storage) */
B_encoder_Test_T encoder_Test_B;

/* Block states (default storage) */
DW_encoder_Test_T encoder_Test_DW;

/* Real-time model */
static RT_MODEL_encoder_Test_T encoder_Test_M_;
RT_MODEL_encoder_Test_T *const encoder_Test_M = &encoder_Test_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void encoder_Test_step(void)
{
  real_T tmp;
  int32_T c_canID_array[2];
  int32_T i;
  uint32_T y;
  uint16_T x;
  uint8_T b_send_RawData[8];
  uint8_T y_1[4];
  uint8_T y_0[2];

  /* MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  /*  Implement algorithm. Calculate y as a function of input u and */
  /*  discrete states. */
  if (encoder_Test_DW.obj.itr_count < 1.0) {
    encoder_Test_DW.obj.offset_Num = encoder_Test_P.Constant4_Value;
  }

  for (i = 0; i < 8; i++) {
    /* MATLABSystem: '<Root>/MATLAB System' incorporates:
     *  MATLABSystem: '<Root>/MATLAB System3'
     */
    b_send_RawData[i] = 0U;
  }

  /* MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  if (encoder_Test_P.Constant4_Value != encoder_Test_DW.obj.offset_Num) {
    b_send_RawData[0] = 25U;
    encoder_Test_DW.obj.offset_Num = encoder_Test_P.Constant4_Value;
  } else {
    b_send_RawData[0] = 164U;
    tmp = floor(encoder_Test_P.Constant3_Value);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        x = (uint16_T)tmp;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint16_T;
    }

    memcpy((void *)&y_0[0], (void *)&x, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    b_send_RawData[2] = y_0[0];
    b_send_RawData[3] = y_0[1];
    tmp = floor(encoder_Test_P.Constant1_Value * 6.0 * 100.0);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        i = (int32_T)tmp;
      } else {
        i = MIN_int32_T;
      }
    } else {
      i = MAX_int32_T;
    }

    memcpy((void *)&y_1[0], (void *)&i, (uint32_T)((size_t)4 * sizeof(uint8_T)));
    b_send_RawData[4] = y_1[0];
    b_send_RawData[5] = y_1[1];
    b_send_RawData[6] = y_1[2];
    b_send_RawData[7] = y_1[3];
  }

  if (encoder_Test_DW.obj.itr_count < 100.0) {
    encoder_Test_DW.obj.itr_count++;
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  /*         %% Define output properties */
  /*  canID_array: int32 * */
  /*  send_RawData: uint8 * */
  /*  dev_Num: unint8 */
  encoder_Test_B.MATLABSystem_o1[0] = 0;
  encoder_Test_B.MATLABSystem_o1[1] = 0;
  encoder_Test_B.MATLABSystem_o1[2] = 0;
  encoder_Test_B.MATLABSystem_o1[3] = 0;

  /*  up to 4 devices */
  for (i = 0; i < 32; i++) {
    /* MATLABSystem: '<Root>/MATLAB System' */
    encoder_Test_B.raw_Data[i] = 0U;
  }

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   */
  /*  Call C-function implementing device output */
  /* y = coder.ceval('source_output'); */
  c_canID_array[0] = encoder_Test_P.Constant_Value[0];
  c_canID_array[1] = encoder_Test_P.Constant_Value[1];
  tmp = rt_roundd_snf(encoder_Test_P.Constant2_Value);
  if (tmp < 2.147483648E+9) {
    if (tmp >= -2.147483648E+9) {
      i = (int32_T)tmp;
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  encoder_Test_B.MATLABSystem_o3 = batchMessage(&c_canID_array[0],
    &b_send_RawData[0], i, &encoder_Test_B.MATLABSystem_o1[0],
    &encoder_Test_B.raw_Data[0]);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  memcpy((void *)&y, (void *)&encoder_Test_B.raw_Data[0], (uint32_T)((size_t)1 *
          sizeof(uint32_T)));
  encoder_Test_B.encoder1 = (real_T)y / 100.0;
  memcpy((void *)&y, (void *)&encoder_Test_B.raw_Data[4], (uint32_T)((size_t)1 *
          sizeof(uint32_T)));
  encoder_Test_B.encoder2 = (real_T)y / 100.0;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.005s, 0.0s] */
    rtExtModeUpload(0, (real_T)encoder_Test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(encoder_Test_M)!=-1) &&
        !((rtmGetTFinal(encoder_Test_M)-encoder_Test_M->Timing.taskTime0) >
          encoder_Test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(encoder_Test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(encoder_Test_M)) {
      rtmSetErrorStatus(encoder_Test_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++encoder_Test_M->Timing.clockTick0)) {
    ++encoder_Test_M->Timing.clockTickH0;
  }

  encoder_Test_M->Timing.taskTime0 = encoder_Test_M->Timing.clockTick0 *
    encoder_Test_M->Timing.stepSize0 + encoder_Test_M->Timing.clockTickH0 *
    encoder_Test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void encoder_Test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)encoder_Test_M, 0,
                sizeof(RT_MODEL_encoder_Test_T));
  rtmSetTFinal(encoder_Test_M, 300.0);
  encoder_Test_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  encoder_Test_M->Sizes.checksums[0] = (1170581714U);
  encoder_Test_M->Sizes.checksums[1] = (1430250823U);
  encoder_Test_M->Sizes.checksums[2] = (459268722U);
  encoder_Test_M->Sizes.checksums[3] = (664679808U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    encoder_Test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(encoder_Test_M->extModeInfo,
      &encoder_Test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(encoder_Test_M->extModeInfo,
                        encoder_Test_M->Sizes.checksums);
    rteiSetTPtr(encoder_Test_M->extModeInfo, rtmGetTPtr(encoder_Test_M));
  }

  /* block I/O */
  (void) memset(((void *) &encoder_Test_B), 0,
                sizeof(B_encoder_Test_T));

  /* states (dwork) */
  (void) memset((void *)&encoder_Test_DW, 0,
                sizeof(DW_encoder_Test_T));

  /* Start for MATLABSystem: '<Root>/MATLAB System3' */
  encoder_Test_DW.obj.offset_Num = 0.0;
  encoder_Test_DW.obj.itr_count = 0.0;
  encoder_Test_DW.objisempty = true;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Perform one-time calculations, such as computing constants */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  encoder_Test_DW.obj_d.matlabCodegenIsDeleted = false;
  encoder_Test_DW.objisempty_c = true;
  encoder_Test_DW.obj_d.isInitialized = 1;

  /*         %% Define output properties */
  /*  Call C-function implementing device initialization */
  canSetup();
  encoder_Test_DW.obj_d.isSetupComplete = true;

  /*  Initialize / reset discrete-state properties */
}

/* Model terminate function */
void encoder_Test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!encoder_Test_DW.obj_d.matlabCodegenIsDeleted) {
    encoder_Test_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((encoder_Test_DW.obj_d.isInitialized == 1) &&
        encoder_Test_DW.obj_d.isSetupComplete) {
      /*  Call C-function implementing device termination */
      close_port();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
}
