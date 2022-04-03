/*
 * multi_motor_Test.c
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

#include "multi_motor_Test.h"
#include "multi_motor_Test_private.h"

/* Block signals (default storage) */
B_multi_motor_Test_T multi_motor_Test_B;

/* Block states (default storage) */
DW_multi_motor_Test_T multi_motor_Test_DW;

/* Real-time model */
static RT_MODEL_multi_motor_Test_T multi_motor_Test_M_;
RT_MODEL_multi_motor_Test_T *const multi_motor_Test_M = &multi_motor_Test_M_;

/* Model step function */
void multi_motor_Test_step(void)
{
  real_T b_varargout_1;
  real_T rtb_angle_idx_0;
  real_T rtb_angle_idx_1;
  real_T rtb_angle_idx_2;
  int32_T i;
  int32_T idx;
  int32_T rtb_speed_idx_1;
  int16_T b_y;
  uint16_T x;
  uint8_T y_0[4];
  uint8_T y[2];
  boolean_T motor_stop;

  /*  Implement algorithm. Calculate y as a function of input u and */
  /*  discrete states. */
  for (i = 0; i < 24; i++) {
    /* MATLABSystem: '<Root>/MATLAB System2' */
    multi_motor_Test_B.MATLABSystem2[i] = 0U;
  }

  /* MATLABSystem: '<Root>/MATLAB System2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   */
  for (i = 0; i < 3; i++) {
    idx = ((i + 1) << 3) - 7;
    multi_motor_Test_B.MATLABSystem2[idx - 1] = 164U;
    b_varargout_1 = floor(multi_motor_Test_P.Constant3_Value[i]);
    if (b_varargout_1 < 65536.0) {
      if (b_varargout_1 >= 0.0) {
        x = (uint16_T)b_varargout_1;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint16_T;
    }

    memcpy((void *)&y[0], (void *)&x, (uint32_T)((size_t)2 * sizeof(uint8_T)));
    multi_motor_Test_B.MATLABSystem2[idx + 1] = y[0];
    multi_motor_Test_B.MATLABSystem2[idx + 2] = y[1];
    b_varargout_1 = floor(multi_motor_Test_P.Constant1_Value[i] * 6.0 * 100.0);
    if (b_varargout_1 < 2.147483648E+9) {
      if (b_varargout_1 >= -2.147483648E+9) {
        rtb_speed_idx_1 = (int32_T)b_varargout_1;
      } else {
        rtb_speed_idx_1 = MIN_int32_T;
      }
    } else {
      rtb_speed_idx_1 = MAX_int32_T;
    }

    memcpy((void *)&y_0[0], (void *)&rtb_speed_idx_1, (uint32_T)((size_t)4 *
            sizeof(uint8_T)));
    multi_motor_Test_B.MATLABSystem2[idx + 3] = y_0[0];
    multi_motor_Test_B.MATLABSystem2[idx + 4] = y_0[1];
    multi_motor_Test_B.MATLABSystem2[idx + 5] = y_0[2];
    multi_motor_Test_B.MATLABSystem2[idx + 6] = y_0[3];
  }

  /* MATLABSystem: '<Root>/MATLAB System' */
  /*         %% Define output properties */
  /*  canID_array: int32 * */
  /*  send_RawData: uint8 * */
  /*  dev_Num: unint8 */
  multi_motor_Test_B.MATLABSystem_o1[0] = 0;
  multi_motor_Test_B.MATLABSystem_o1[1] = 0;
  multi_motor_Test_B.MATLABSystem_o1[2] = 0;
  multi_motor_Test_B.MATLABSystem_o1[3] = 0;

  /*  up to 4 devices */
  for (i = 0; i < 32; i++) {
    /* MATLABSystem: '<Root>/MATLAB System' */
    multi_motor_Test_B.raw_Data[i] = 0U;
  }

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLABSystem: '<Root>/MATLAB System2'
   */
  /*  Call C-function implementing device output */
  /* y = coder.ceval('source_output'); */
  multi_motor_Test_B.c_canID_array[0] = multi_motor_Test_P.Constant_Value[0];
  multi_motor_Test_B.c_canID_array[1] = multi_motor_Test_P.Constant_Value[1];
  multi_motor_Test_B.c_canID_array[2] = multi_motor_Test_P.Constant_Value[2];
  for (i = 0; i < 24; i++) {
    multi_motor_Test_B.b_send_RawData[i] = multi_motor_Test_B.MATLABSystem2[i];
  }

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  multi_motor_Test_B.MATLABSystem_o3 = batchMessage
    (&multi_motor_Test_B.c_canID_array[0], &multi_motor_Test_B.b_send_RawData[0],
     multi_motor_Test_P.Constant2_Value, &multi_motor_Test_B.MATLABSystem_o1[0],
     &multi_motor_Test_B.raw_Data[0]);

  /* MATLAB Function: '<Root>/rawData_decoder' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  memcpy((void *)&x, (void *)&multi_motor_Test_B.raw_Data[6], (uint32_T)((size_t)
          1 * sizeof(uint16_T)));
  rtb_angle_idx_0 = (real_T)x / 65535.0 * 360.0;
  memcpy((void *)&b_y, (void *)&multi_motor_Test_B.raw_Data[4], (uint32_T)
         ((size_t)1 * sizeof(int16_T)));
  idx = b_y;
  memcpy((void *)&x, (void *)&multi_motor_Test_B.raw_Data[14], (uint32_T)
         ((size_t)1 * sizeof(uint16_T)));
  rtb_angle_idx_1 = (real_T)x / 65535.0 * 360.0;
  memcpy((void *)&b_y, (void *)&multi_motor_Test_B.raw_Data[12], (uint32_T)
         ((size_t)1 * sizeof(int16_T)));
  rtb_speed_idx_1 = b_y;
  memcpy((void *)&x, (void *)&multi_motor_Test_B.raw_Data[22], (uint32_T)
         ((size_t)1 * sizeof(uint16_T)));
  rtb_angle_idx_2 = (real_T)x / 65535.0 * 360.0;
  memcpy((void *)&b_y, (void *)&multi_motor_Test_B.raw_Data[20], (uint32_T)
         ((size_t)1 * sizeof(int16_T)));

  /* MATLABSystem: '<Root>/MATLAB System3' */
  /*  speed: unit in LSB */
  if (!multi_motor_Test_DW.obj_f.calibrated) {
    b_varargout_1 = 0.0;
  } else {
    b_varargout_1 = rtb_angle_idx_1 - multi_motor_Test_DW.obj_f.sgl_angle_old;
    if (b_varargout_1 < -180.0) {
      multi_motor_Test_DW.obj_f.loop_count++;
    } else if (b_varargout_1 > 180.0) {
      multi_motor_Test_DW.obj_f.loop_count--;
    }

    b_varargout_1 = rtb_angle_idx_1 / 6.0 + multi_motor_Test_DW.obj_f.loop_count
      * 60.0;
  }

  if (!multi_motor_Test_DW.obj_f.calibrated) {
    motor_stop = true;
    for (i = 0; i < 5; i++) {
      motor_stop = ((fabs(multi_motor_Test_DW.obj_f.speed_prev[i]) <= 20.0) &&
                    motor_stop);
    }

    if (motor_stop && (multi_motor_Test_P.Constant1_Value[1] == 0.0)) {
      if (rtb_angle_idx_1 <= 180.0) {
        multi_motor_Test_DW.obj_f.loop_count = 0.0;
      } else {
        multi_motor_Test_DW.obj_f.loop_count = -1.0;
      }

      multi_motor_Test_DW.obj_f.calibrated = true;
    }
  }

  multi_motor_Test_DW.obj_f.sgl_angle_old = rtb_angle_idx_1;
  multi_motor_Test_DW.obj_f.speed_prev[0] =
    multi_motor_Test_DW.obj_f.speed_prev[1];
  multi_motor_Test_DW.obj_f.speed_prev[1] =
    multi_motor_Test_DW.obj_f.speed_prev[2];
  multi_motor_Test_DW.obj_f.speed_prev[2] =
    multi_motor_Test_DW.obj_f.speed_prev[3];
  multi_motor_Test_DW.obj_f.speed_prev[3] =
    multi_motor_Test_DW.obj_f.speed_prev[4];
  multi_motor_Test_DW.obj_f.speed_prev[4] = rtb_speed_idx_1;

  /* MATLABSystem: '<Root>/MATLAB System3' */
  multi_motor_Test_B.abs_angle2 = b_varargout_1 + 22.5;

  /* MATLABSystem: '<Root>/MATLAB System3' */
  multi_motor_Test_B.calibration_res2 = multi_motor_Test_DW.obj_f.calibrated;

  /* MATLABSystem: '<Root>/MATLAB System1' */
  /*  speed: unit in LSB */
  if (!multi_motor_Test_DW.obj_n.calibrated) {
    b_varargout_1 = 0.0;
  } else {
    b_varargout_1 = rtb_angle_idx_0 - multi_motor_Test_DW.obj_n.sgl_angle_old;
    if (b_varargout_1 < -180.0) {
      multi_motor_Test_DW.obj_n.loop_count++;
    } else if (b_varargout_1 > 180.0) {
      multi_motor_Test_DW.obj_n.loop_count--;
    }

    b_varargout_1 = rtb_angle_idx_0 / 6.0 + multi_motor_Test_DW.obj_n.loop_count
      * 60.0;
  }

  if (!multi_motor_Test_DW.obj_n.calibrated) {
    motor_stop = true;
    for (i = 0; i < 5; i++) {
      motor_stop = ((fabs(multi_motor_Test_DW.obj_n.speed_prev[i]) <= 20.0) &&
                    motor_stop);
    }

    if (motor_stop && (multi_motor_Test_P.Constant1_Value[0] == 0.0)) {
      if (rtb_angle_idx_0 <= 180.0) {
        multi_motor_Test_DW.obj_n.loop_count = 0.0;
      } else {
        multi_motor_Test_DW.obj_n.loop_count = -1.0;
      }

      multi_motor_Test_DW.obj_n.calibrated = true;
    }
  }

  multi_motor_Test_DW.obj_n.sgl_angle_old = rtb_angle_idx_0;
  multi_motor_Test_DW.obj_n.speed_prev[0] =
    multi_motor_Test_DW.obj_n.speed_prev[1];
  multi_motor_Test_DW.obj_n.speed_prev[1] =
    multi_motor_Test_DW.obj_n.speed_prev[2];
  multi_motor_Test_DW.obj_n.speed_prev[2] =
    multi_motor_Test_DW.obj_n.speed_prev[3];
  multi_motor_Test_DW.obj_n.speed_prev[3] =
    multi_motor_Test_DW.obj_n.speed_prev[4];
  multi_motor_Test_DW.obj_n.speed_prev[4] = idx;

  /* MATLABSystem: '<Root>/MATLAB System1' */
  multi_motor_Test_B.abs_angle1 = b_varargout_1 + -17.5;

  /* MATLABSystem: '<Root>/MATLAB System1' */
  multi_motor_Test_B.calibration_res1 = multi_motor_Test_DW.obj_n.calibrated;

  /* MATLABSystem: '<Root>/MATLAB System4' incorporates:
   *  MATLAB Function: '<Root>/rawData_decoder'
   */
  /*  speed: unit in LSB */
  if (!multi_motor_Test_DW.obj.calibrated) {
    b_varargout_1 = 0.0;
  } else {
    b_varargout_1 = rtb_angle_idx_2 - multi_motor_Test_DW.obj.sgl_angle_old;
    if (b_varargout_1 < -180.0) {
      multi_motor_Test_DW.obj.loop_count++;
    } else if (b_varargout_1 > 180.0) {
      multi_motor_Test_DW.obj.loop_count--;
    }

    b_varargout_1 = rtb_angle_idx_2 / 6.0 + multi_motor_Test_DW.obj.loop_count *
      60.0;
  }

  if (!multi_motor_Test_DW.obj.calibrated) {
    motor_stop = true;
    for (i = 0; i < 5; i++) {
      motor_stop = ((fabs(multi_motor_Test_DW.obj.speed_prev[i]) <= 20.0) &&
                    motor_stop);
    }

    if (motor_stop && (multi_motor_Test_P.Constant1_Value[2] == 0.0)) {
      if (rtb_angle_idx_2 <= 180.0) {
        multi_motor_Test_DW.obj.loop_count = 0.0;
      } else {
        multi_motor_Test_DW.obj.loop_count = -1.0;
      }

      multi_motor_Test_DW.obj.calibrated = true;
    }
  }

  multi_motor_Test_DW.obj.sgl_angle_old = rtb_angle_idx_2;
  multi_motor_Test_DW.obj.speed_prev[0] = multi_motor_Test_DW.obj.speed_prev[1];
  multi_motor_Test_DW.obj.speed_prev[1] = multi_motor_Test_DW.obj.speed_prev[2];
  multi_motor_Test_DW.obj.speed_prev[2] = multi_motor_Test_DW.obj.speed_prev[3];
  multi_motor_Test_DW.obj.speed_prev[3] = multi_motor_Test_DW.obj.speed_prev[4];
  multi_motor_Test_DW.obj.speed_prev[4] = b_y;

  /* MATLABSystem: '<Root>/MATLAB System4' */
  multi_motor_Test_B.abs_angle3 = b_varargout_1 + -3.163;

  /* MATLABSystem: '<Root>/MATLAB System4' */
  multi_motor_Test_B.calibration_res3 = multi_motor_Test_DW.obj.calibrated;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.005s, 0.0s] */
    rtExtModeUpload(0, (real_T)multi_motor_Test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(multi_motor_Test_M)!=-1) &&
        !((rtmGetTFinal(multi_motor_Test_M)-multi_motor_Test_M->Timing.taskTime0)
          > multi_motor_Test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(multi_motor_Test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(multi_motor_Test_M)) {
      rtmSetErrorStatus(multi_motor_Test_M, "Simulation finished");
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
  if (!(++multi_motor_Test_M->Timing.clockTick0)) {
    ++multi_motor_Test_M->Timing.clockTickH0;
  }

  multi_motor_Test_M->Timing.taskTime0 = multi_motor_Test_M->Timing.clockTick0 *
    multi_motor_Test_M->Timing.stepSize0 +
    multi_motor_Test_M->Timing.clockTickH0 *
    multi_motor_Test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void multi_motor_Test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)multi_motor_Test_M, 0,
                sizeof(RT_MODEL_multi_motor_Test_T));
  rtmSetTFinal(multi_motor_Test_M, 300.0);
  multi_motor_Test_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  multi_motor_Test_M->Sizes.checksums[0] = (1588005340U);
  multi_motor_Test_M->Sizes.checksums[1] = (3956978230U);
  multi_motor_Test_M->Sizes.checksums[2] = (1974776953U);
  multi_motor_Test_M->Sizes.checksums[3] = (830393975U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    multi_motor_Test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(multi_motor_Test_M->extModeInfo,
      &multi_motor_Test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(multi_motor_Test_M->extModeInfo,
                        multi_motor_Test_M->Sizes.checksums);
    rteiSetTPtr(multi_motor_Test_M->extModeInfo, rtmGetTPtr(multi_motor_Test_M));
  }

  /* block I/O */
  (void) memset(((void *) &multi_motor_Test_B), 0,
                sizeof(B_multi_motor_Test_T));

  /* states (dwork) */
  (void) memset((void *)&multi_motor_Test_DW, 0,
                sizeof(DW_multi_motor_Test_T));

  {
    int32_T i;

    /* Start for MATLABSystem: '<Root>/MATLAB System2' */
    multi_motor_Test_DW.objisempty_k = true;

    /* Start for MATLABSystem: '<Root>/MATLAB System' */
    /*  Perform one-time calculations, such as computing constants */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    multi_motor_Test_DW.obj_d.matlabCodegenIsDeleted = false;
    multi_motor_Test_DW.objisempty_c = true;
    multi_motor_Test_DW.obj_d.isInitialized = 1;

    /*         %% Define output properties */
    /*  Call C-function implementing device initialization */
    canSetup();
    multi_motor_Test_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/MATLAB System3' */
    multi_motor_Test_DW.obj_f.calibrated = false;
    multi_motor_Test_DW.obj_f.loop_count = 0.0;
    for (i = 0; i < 5; i++) {
      multi_motor_Test_DW.obj_f.speed_prev[i] = 99.0;
    }

    multi_motor_Test_DW.obj_f.sgl_angle_old = 0.0;
    multi_motor_Test_DW.objisempty_g = true;

    /* End of Start for MATLABSystem: '<Root>/MATLAB System3' */

    /* Start for ToAsyncQueueBlock generated from: '<Root>/MATLAB System3' */
    /*  Perform one-time calculations, such as computing constants */
    /* Start for MATLABSystem: '<Root>/MATLAB System1' */
    multi_motor_Test_DW.obj_n.calibrated = false;
    multi_motor_Test_DW.obj_n.loop_count = 0.0;
    for (i = 0; i < 5; i++) {
      multi_motor_Test_DW.obj_n.speed_prev[i] = 99.0;
    }

    multi_motor_Test_DW.obj_n.sgl_angle_old = 0.0;
    multi_motor_Test_DW.objisempty_m = true;

    /* End of Start for MATLABSystem: '<Root>/MATLAB System1' */

    /* Start for ToAsyncQueueBlock generated from: '<Root>/MATLAB System1' */
    /*  Perform one-time calculations, such as computing constants */
    /* Start for MATLABSystem: '<Root>/MATLAB System4' */
    multi_motor_Test_DW.obj.calibrated = false;
    multi_motor_Test_DW.obj.loop_count = 0.0;
    for (i = 0; i < 5; i++) {
      multi_motor_Test_DW.obj.speed_prev[i] = 99.0;
    }

    multi_motor_Test_DW.obj.sgl_angle_old = 0.0;
    multi_motor_Test_DW.objisempty = true;

    /* End of Start for MATLABSystem: '<Root>/MATLAB System4' */

    /* Start for ToAsyncQueueBlock generated from: '<Root>/MATLAB System4' */
    /*  Perform one-time calculations, such as computing constants */
  }

  /*  Initialize / reset discrete-state properties */
}

/* Model terminate function */
void multi_motor_Test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!multi_motor_Test_DW.obj_d.matlabCodegenIsDeleted) {
    multi_motor_Test_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((multi_motor_Test_DW.obj_d.isInitialized == 1) &&
        multi_motor_Test_DW.obj_d.isSetupComplete) {
      /*  Call C-function implementing device termination */
      close_port();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
}
