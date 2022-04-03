/*
 * motor_Test.c
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

#include "motor_Test.h"
#include "motor_Test_private.h"

/* Block signals (default storage) */
B_motor_Test_T motor_Test_B;

/* Block states (default storage) */
DW_motor_Test_T motor_Test_DW;

/* Real-time model */
static RT_MODEL_motor_Test_T motor_Test_M_;
RT_MODEL_motor_Test_T *const motor_Test_M = &motor_Test_M_;

/* Model step function */
void motor_Test_step(void)
{
  real_T tmp;
  int32_T i;
  int16_T y;
  uint16_T canID_array[2];
  uint16_T x;
  uint8_T send_RawData[8];
  uint8_T y_1[4];
  uint8_T y_0[2];
  boolean_T motor_stop;

  /* MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  /*  Implement algorithm. Calculate y as a function of input u and */
  /*  discrete states. */
  if (motor_Test_DW.obj_m.itr_count < 1.0) {
    motor_Test_DW.obj_m.offset_Num = motor_Test_P.Constant4_Value;
  }

  for (i = 0; i < 8; i++) {
    /* MATLABSystem: '<Root>/MATLAB System' incorporates:
     *  MATLABSystem: '<Root>/MATLAB System3'
     */
    send_RawData[i] = 0U;
  }

  /* MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  if (motor_Test_P.Constant4_Value != motor_Test_DW.obj_m.offset_Num) {
    send_RawData[0] = 25U;
    motor_Test_DW.obj_m.offset_Num = motor_Test_P.Constant4_Value;
  } else {
    send_RawData[0] = 164U;
    tmp = floor(motor_Test_P.Constant3_Value);
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
    send_RawData[2] = y_0[0];
    send_RawData[3] = y_0[1];
    tmp = floor(motor_Test_P.Constant1_Value * 6.0 * 100.0);
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
    send_RawData[4] = y_1[0];
    send_RawData[5] = y_1[1];
    send_RawData[6] = y_1[2];
    send_RawData[7] = y_1[3];
  }

  if (motor_Test_DW.obj_m.itr_count < 100.0) {
    motor_Test_DW.obj_m.itr_count++;
  }

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /*         %% Define output properties */
  canID_array[0] = motor_Test_P.Constant_Value[0];
  canID_array[1] = motor_Test_P.Constant_Value[1];

  /* MATLABSystem: '<Root>/MATLAB System' */
  /*  canID_array: int32 * */
  /*  send_RawData: uint8 * */
  /*  dev_Num: unint8 */
  motor_Test_B.MATLABSystem_o1[0] = 0;
  motor_Test_B.MATLABSystem_o1[1] = 0;
  motor_Test_B.MATLABSystem_o1[2] = 0;
  motor_Test_B.MATLABSystem_o1[3] = 0;

  /*  up to 4 devices */
  for (i = 0; i < 32; i++) {
    /* MATLABSystem: '<Root>/MATLAB System' */
    motor_Test_B.raw_Data[i] = 0U;
  }

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  /*  Call C-function implementing device output */
  /* y = coder.ceval('source_output'); */
  motor_Test_B.MATLABSystem_o3 = batchMessage(&canID_array[0], &send_RawData[0],
    motor_Test_P.Constant2_Value, &motor_Test_B.MATLABSystem_o1[0],
    &motor_Test_B.raw_Data[0]);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  memcpy((void *)&x, (void *)&motor_Test_B.raw_Data[6], (uint32_T)((size_t)1 *
          sizeof(uint16_T)));
  motor_Test_B.y_l = (real_T)x / 65535.0 * 360.0;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  memcpy((void *)&y, (void *)&motor_Test_B.raw_Data[4], (uint32_T)((size_t)1 *
          sizeof(int16_T)));
  motor_Test_B.y = y;

  /* MATLABSystem: '<Root>/MATLAB System1' */
  /*  speed: unit in LSB */
  if (!motor_Test_DW.obj.calibrated) {
    /* MATLABSystem: '<Root>/MATLAB System1' */
    motor_Test_B.abs_angle = 0.0;
  } else {
    tmp = motor_Test_B.y_l - motor_Test_DW.obj.sgl_angle_old;
    if (tmp < -180.0) {
      motor_Test_DW.obj.loop_count++;
    } else if (tmp > 180.0) {
      motor_Test_DW.obj.loop_count--;
    }

    /* MATLABSystem: '<Root>/MATLAB System1' */
    motor_Test_B.abs_angle = motor_Test_B.y_l / 6.0 +
      motor_Test_DW.obj.loop_count * 60.0;
  }

  if (!motor_Test_DW.obj.calibrated) {
    motor_stop = true;
    for (i = 0; i < 5; i++) {
      motor_stop = ((fabs(motor_Test_DW.obj.speed_prev[i]) <= 20.0) &&
                    motor_stop);
    }

    if (motor_stop && (motor_Test_P.Constant1_Value == 0.0)) {
      if ((motor_Test_B.y_l >= 0.0) && (motor_Test_B.y_l <= 180.0)) {
        motor_Test_DW.obj.loop_count = 0.0;
      } else {
        motor_Test_DW.obj.loop_count = -1.0;
      }

      motor_Test_DW.obj.calibrated = true;
    }
  }

  motor_Test_DW.obj.sgl_angle_old = motor_Test_B.y_l;
  motor_Test_DW.obj.speed_prev[0] = motor_Test_DW.obj.speed_prev[1];
  motor_Test_DW.obj.speed_prev[1] = motor_Test_DW.obj.speed_prev[2];
  motor_Test_DW.obj.speed_prev[2] = motor_Test_DW.obj.speed_prev[3];
  motor_Test_DW.obj.speed_prev[3] = motor_Test_DW.obj.speed_prev[4];
  motor_Test_DW.obj.speed_prev[4] = motor_Test_B.y;

  /* MATLABSystem: '<Root>/MATLAB System1' */
  motor_Test_B.calibration_res = motor_Test_DW.obj.calibrated;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.005s, 0.0s] */
    rtExtModeUpload(0, (real_T)motor_Test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(motor_Test_M)!=-1) &&
        !((rtmGetTFinal(motor_Test_M)-motor_Test_M->Timing.taskTime0) >
          motor_Test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(motor_Test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(motor_Test_M)) {
      rtmSetErrorStatus(motor_Test_M, "Simulation finished");
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
  if (!(++motor_Test_M->Timing.clockTick0)) {
    ++motor_Test_M->Timing.clockTickH0;
  }

  motor_Test_M->Timing.taskTime0 = motor_Test_M->Timing.clockTick0 *
    motor_Test_M->Timing.stepSize0 + motor_Test_M->Timing.clockTickH0 *
    motor_Test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void motor_Test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor_Test_M, 0,
                sizeof(RT_MODEL_motor_Test_T));
  rtmSetTFinal(motor_Test_M, 300.0);
  motor_Test_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  motor_Test_M->Sizes.checksums[0] = (4192010471U);
  motor_Test_M->Sizes.checksums[1] = (26077025U);
  motor_Test_M->Sizes.checksums[2] = (4226899522U);
  motor_Test_M->Sizes.checksums[3] = (2443765880U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    motor_Test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_Test_M->extModeInfo,
      &motor_Test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_Test_M->extModeInfo, motor_Test_M->Sizes.checksums);
    rteiSetTPtr(motor_Test_M->extModeInfo, rtmGetTPtr(motor_Test_M));
  }

  /* block I/O */
  (void) memset(((void *) &motor_Test_B), 0,
                sizeof(B_motor_Test_T));

  /* states (dwork) */
  (void) memset((void *)&motor_Test_DW, 0,
                sizeof(DW_motor_Test_T));

  {
    int32_T i;

    /* Start for MATLABSystem: '<Root>/MATLAB System3' */
    motor_Test_DW.obj_m.offset_Num = 0.0;
    motor_Test_DW.obj_m.itr_count = 0.0;
    motor_Test_DW.objisempty = true;

    /* Start for MATLABSystem: '<Root>/MATLAB System' */
    /*  Perform one-time calculations, such as computing constants */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    motor_Test_DW.obj_d.matlabCodegenIsDeleted = false;
    motor_Test_DW.objisempty_c = true;
    motor_Test_DW.obj_d.isInitialized = 1;

    /*         %% Define output properties */
    /*  Call C-function implementing device initialization */
    canSetup();
    motor_Test_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/MATLAB System1' */
    motor_Test_DW.obj.calibrated = false;
    motor_Test_DW.obj.loop_count = 0.0;
    for (i = 0; i < 5; i++) {
      motor_Test_DW.obj.speed_prev[i] = 99.0;
    }

    motor_Test_DW.obj.sgl_angle_old = 0.0;
    motor_Test_DW.objisempty_m = true;

    /* End of Start for MATLABSystem: '<Root>/MATLAB System1' */

    /* Start for ToAsyncQueueBlock generated from: '<Root>/MATLAB System1' */
    /*  Perform one-time calculations, such as computing constants */
  }

  /*  Initialize / reset discrete-state properties */
}

/* Model terminate function */
void motor_Test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!motor_Test_DW.obj_d.matlabCodegenIsDeleted) {
    motor_Test_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((motor_Test_DW.obj_d.isInitialized == 1) &&
        motor_Test_DW.obj_d.isSetupComplete) {
      /*  Call C-function implementing device termination */
      close_port();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
}
