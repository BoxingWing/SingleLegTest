/*
 * motor_Test.c
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

#include "motor_Test.h"
#include "motor_Test_private.h"

/* Block signals (default storage) */
B_motor_Test_T motor_Test_B;

/* Block states (default storage) */
DW_motor_Test_T motor_Test_DW;

/* Real-time model */
static RT_MODEL_motor_Test_T motor_Test_M_;
RT_MODEL_motor_Test_T *const motor_Test_M = &motor_Test_M_;

/* Forward declaration for local functions */
static void motor_Test_SystemCore_setup(codertarget_raspi_internal_CA_T *obj,
  B_CANReceive_motor_Test_T *localB);

/* Forward declaration for local functions */
static void motor_Test_SystemCore_setup_c(codertarget_raspi_internal__c_T *obj);
static void motor_Test_SystemCore_setup(codertarget_raspi_internal_CA_T *obj,
  B_CANReceive_motor_Test_T *localB)
{
  int32_T isCANSetup;
  int32_T stat;
  char_T errString3[20];
  char_T canInterface[5];
  static const char_T tmp[19] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'u',
    'p', '.', ' ', 'S', 'e', 't', ' ', 'u', 'p', ' ' };

  static const char_T tmp_0[14] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 's',
    'e', 't', ' ', 'u', 'p' };

  static const char_T tmp_1[46] = { ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't',
    ' ', 'e', 'x', 'i', 's', 't', '.', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ',
    'a', ' ', 'v', 'a', 'l', 'i', 'd', ' ', 'C', 'A', 'N', ' ', 'i', 'n', 't',
    'e', 'r', 'f', 'a', 'c', 'e', '.' };

  static const char_T tmp_2[34] = { ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'l',
    'a', 'u', 'n', 'c', 'h', 'i', 'n', 'g', ' ', 't', 'h', 'e', ' ', 'a', 'p',
    'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', '.' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  canInterface[0] = 'c';
  canInterface[1] = 'a';
  canInterface[2] = 'n';
  canInterface[3] = '0';
  canInterface[4] = '\x00';
  stat = -1;
  isCANSetup = MW_checkIFStatus(&canInterface[0]);
  if (isCANSetup == 0) {
    MW_createSocket(&canInterface[0], &obj->sockHandleDataFrames);
    stat = MW_createSocket(&canInterface[0], &obj->sockHandleErrorFrames);
  } else if (isCANSetup == 1) {
    localB->errString1[0] = 'c';
    localB->errString1[1] = 'a';
    localB->errString1[2] = 'n';
    localB->errString1[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      localB->errString1[isCANSetup + 4] = tmp[isCANSetup];
    }

    localB->errString1[23] = 'c';
    localB->errString1[24] = 'a';
    localB->errString1[25] = 'n';
    localB->errString1[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      localB->errString1[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    localB->errString1[61] = '\x0a';
    localB->errString1[62] = '\x00';
    MW_printError(&localB->errString1[0]);
  } else if (isCANSetup == 2) {
    localB->errString2[0] = 'c';
    localB->errString2[1] = 'a';
    localB->errString2[2] = 'n';
    localB->errString2[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      localB->errString2[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    localB->errString2[50] = '\x0a';
    localB->errString2[51] = '\x00';
    MW_printError(&localB->errString2[0]);
  } else {
    errString3[0] = 'c';
    errString3[1] = 'a';
    errString3[2] = 'n';
    errString3[3] = '0';
    for (isCANSetup = 0; isCANSetup < 14; isCANSetup++) {
      errString3[isCANSetup + 4] = tmp_0[isCANSetup];
    }

    errString3[18] = '\x0a';
    errString3[19] = '\x00';
    MW_printError(&errString3[0]);
  }

  obj->Initialized = (stat == 0);
  obj->isSetupComplete = true;
}

/* Start for atomic system: */
void motor_Test_CANReceive_Start(B_CANReceive_motor_Test_T *localB,
  DW_CANReceive_motor_Test_T *localDW, P_CANReceive_motor_Test_T *localP)
{
  int32_T i;
  static const char_T tmp[28] = { 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', ' ',
    '(', '1', '1', '-', 'b', 'i', 't', ' ', 'i', 'd', 'e', 'n', 't', 'i', 'f',
    'i', 'e', 'r', ')' };

  /* Start for MATLABSystem: '<Root>/CAN Receive' */
  localDW->obj.sockHandleDataFrames = 0;
  localDW->obj.sockHandleErrorFrames = 0;
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  for (i = 0; i < 28; i++) {
    localDW->obj.IdentifierType[i] = tmp[i];
  }

  localDW->obj.SetIdentifierType = true;
  localDW->obj.SampleTime = localP->CANReceive_SampleTime;
  motor_Test_SystemCore_setup(&localDW->obj, localB);

  /* End of Start for MATLABSystem: '<Root>/CAN Receive' */
}

/* Output and update for atomic system: */
void motor_Test_CANReceive(B_CANReceive_motor_Test_T *localB,
  DW_CANReceive_motor_Test_T *localDW, P_CANReceive_motor_Test_T *localP)
{
  int32_T i;
  char_T b[28];
  char_T rxInterface[5];
  uint8_T rxData[8];
  uint8_T extended;
  uint8_T remote;
  static const char_T tmp[28] = { 'E', 'x', 't', 'e', 'n', 'd', 'e', 'd', ' ',
    '(', '2', '9', '-', 'b', 'i', 't', ' ', 'i', 'd', 'e', 'n', 't', 'i', 'f',
    'i', 'e', 'r', ')' };

  /* MATLABSystem: '<Root>/CAN Receive' */
  if (localDW->obj.SampleTime != localP->CANReceive_SampleTime) {
    localDW->obj.SampleTime = localP->CANReceive_SampleTime;
  }

  if (localDW->obj.Initialized) {
    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    for (i = 0; i < 8; i++) {
      rxData[i] = 0U;
    }

    extended = 0U;
    for (i = 0; i < 28; i++) {
      b[i] = tmp[i];
    }

    i = memcmp(&localDW->obj.IdentifierType[0], &b[0], 28);
    if (i == 0) {
      extended = 1U;
    }

    i = MW_CAN_receiveRawSimulink(&rxInterface[0], 321U, &rxData[0], 8,
      &localB->CANReceive_o2, extended, &remote, &localB->CANReceive_o3,
      localDW->obj.sockHandleDataFrames, localDW->obj.sockHandleErrorFrames);
    if (i != 0) {
      localDW->obj.Initialized = false;
    }

    for (i = 0; i < 8; i++) {
      localB->recData[i] = rxData[i];
    }
  } else {
    for (i = 0; i < 8; i++) {
      localB->recData[i] = 0U;
    }

    /* MATLABSystem: '<Root>/CAN Receive' */
    localB->CANReceive_o2 = 0U;

    /* MATLABSystem: '<Root>/CAN Receive' */
    localB->CANReceive_o3 = 0U;
  }

  /* End of MATLABSystem: '<Root>/CAN Receive' */
}

/* Termination for atomic system: */
void motor_Test_CANReceive_Term(DW_CANReceive_motor_Test_T *localDW)
{
  char_T canInterface[5];

  /* Terminate for MATLABSystem: '<Root>/CAN Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete &&
        localDW->obj.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&localDW->obj.sockHandleDataFrames, &canInterface[0]);
      MW_clearSocket(&localDW->obj.sockHandleErrorFrames, &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Receive' */
}

static void motor_Test_SystemCore_setup_c(codertarget_raspi_internal__c_T *obj)
{
  int32_T isCANSetup;
  int32_T stat1;
  int32_T stat2;
  char_T canInterface[5];
  static const char_T tmp[19] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'u',
    'p', '.', ' ', 'S', 'e', 't', ' ', 'u', 'p', ' ' };

  static const char_T tmp_0[14] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 's',
    'e', 't', ' ', 'u', 'p' };

  static const char_T tmp_1[46] = { ' ', 'd', 'o', 'e', 's', ' ', 'n', 'o', 't',
    ' ', 'e', 'x', 'i', 's', 't', '.', ' ', 'S', 'e', 'l', 'e', 'c', 't', ' ',
    'a', ' ', 'v', 'a', 'l', 'i', 'd', ' ', 'C', 'A', 'N', ' ', 'i', 'n', 't',
    'e', 'r', 'f', 'a', 'c', 'e', '.' };

  static const char_T tmp_2[34] = { ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'l',
    'a', 'u', 'n', 'c', 'h', 'i', 'n', 'g', ' ', 't', 'h', 'e', ' ', 'a', 'p',
    'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', '.' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  canInterface[0] = 'c';
  canInterface[1] = 'a';
  canInterface[2] = 'n';
  canInterface[3] = '0';
  canInterface[4] = '\x00';
  stat1 = -1;
  stat2 = -1;
  isCANSetup = MW_checkIFStatus(&canInterface[0]);
  if (isCANSetup == 0) {
    stat1 = MW_createSocket(&canInterface[0], &obj->sockHandleDataFrames);
    stat2 = MW_createSocket(&canInterface[0], &obj->sockHandleErrorFrames);
  } else if (isCANSetup == 1) {
    motor_Test_B.errString1[0] = 'c';
    motor_Test_B.errString1[1] = 'a';
    motor_Test_B.errString1[2] = 'n';
    motor_Test_B.errString1[3] = '0';
    for (isCANSetup = 0; isCANSetup < 19; isCANSetup++) {
      motor_Test_B.errString1[isCANSetup + 4] = tmp[isCANSetup];
    }

    motor_Test_B.errString1[23] = 'c';
    motor_Test_B.errString1[24] = 'a';
    motor_Test_B.errString1[25] = 'n';
    motor_Test_B.errString1[26] = '0';
    for (isCANSetup = 0; isCANSetup < 34; isCANSetup++) {
      motor_Test_B.errString1[isCANSetup + 27] = tmp_2[isCANSetup];
    }

    motor_Test_B.errString1[61] = '\x0a';
    motor_Test_B.errString1[62] = '\x00';
    MW_printError(&motor_Test_B.errString1[0]);
  } else if (isCANSetup == 2) {
    motor_Test_B.errString2[0] = 'c';
    motor_Test_B.errString2[1] = 'a';
    motor_Test_B.errString2[2] = 'n';
    motor_Test_B.errString2[3] = '0';
    for (isCANSetup = 0; isCANSetup < 46; isCANSetup++) {
      motor_Test_B.errString2[isCANSetup + 4] = tmp_1[isCANSetup];
    }

    motor_Test_B.errString2[50] = '\x0a';
    motor_Test_B.errString2[51] = '\x00';
    MW_printError(&motor_Test_B.errString2[0]);
  } else {
    motor_Test_B.errString3[0] = 'c';
    motor_Test_B.errString3[1] = 'a';
    motor_Test_B.errString3[2] = 'n';
    motor_Test_B.errString3[3] = '0';
    for (isCANSetup = 0; isCANSetup < 14; isCANSetup++) {
      motor_Test_B.errString3[isCANSetup + 4] = tmp_0[isCANSetup];
    }

    motor_Test_B.errString3[18] = '\x0a';
    motor_Test_B.errString3[19] = '\x00';
    MW_printError(&motor_Test_B.errString3[0]);
  }

  if ((stat1 == 0) && (stat2 == 0)) {
    obj->Initialized = true;
  } else {
    obj->Initialized = false;
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void motor_Test_step(void)
{
  int32_T ret;
  char_T rxInterface[5];
  uint8_T txData[8];
  static const char_T tmp[28] = { 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', ' ',
    '(', '1', '1', '-', 'b', 'i', 't', ' ', 'i', 'd', 'e', 'n', 't', 'i', 'f',
    'i', 'e', 'r', ')' };

  motor_Test_CANReceive(&motor_Test_B.CANReceive, &motor_Test_DW.CANReceive,
                        &motor_Test_P.CANReceive);
  motor_Test_CANReceive(&motor_Test_B.CANReceive1, &motor_Test_DW.CANReceive1,
                        &motor_Test_P.CANReceive1);

  /* MATLABSystem: '<Root>/CAN Transmit' */
  motor_Test_B.CANTransmit = 0U;

  /* MATLABSystem: '<Root>/CAN Transmit' incorporates:
   *  Constant: '<Root>/read single loop angle'
   */
  if (motor_Test_DW.obj.Initialized) {
    rxInterface[0] = 'c';
    rxInterface[1] = 'a';
    rxInterface[2] = 'n';
    rxInterface[3] = '0';
    rxInterface[4] = '\x00';
    for (ret = 0; ret < 8; ret++) {
      txData[ret] = motor_Test_P.readsingleloopangle_Value[ret];
    }

    for (ret = 0; ret < 28; ret++) {
      motor_Test_B.b[ret] = tmp[ret];
    }

    ret = memcmp(&motor_Test_DW.obj.IdentifierType[0], &motor_Test_B.b[0], 28);
    ret = MW_CAN_transmitRaw(&rxInterface[0], (uint8_T)(ret == 0), 321U, 8,
      &txData[0], 0, &motor_Test_B.CANTransmit, 0, 1.0,
      motor_Test_DW.obj.sockHandleDataFrames,
      motor_Test_DW.obj.sockHandleErrorFrames, (uint8_T)
      motor_Test_DW.obj.notFirstStep);
    if (ret != 0) {
      motor_Test_DW.obj.Initialized = false;
    }
  }

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
  rtmSetTFinal(motor_Test_M, 120.0);
  motor_Test_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  motor_Test_M->Sizes.checksums[0] = (3708059588U);
  motor_Test_M->Sizes.checksums[1] = (1633827381U);
  motor_Test_M->Sizes.checksums[2] = (1178269841U);
  motor_Test_M->Sizes.checksums[3] = (4142710368U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    motor_Test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
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
    static const char_T tmp[28] = { 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', ' ',
      '(', '1', '1', '-', 'b', 'i', 't', ' ', 'i', 'd', 'e', 'n', 't', 'i', 'f',
      'i', 'e', 'r', ')' };

    motor_Test_CANReceive_Start(&motor_Test_B.CANReceive,
      &motor_Test_DW.CANReceive, &motor_Test_P.CANReceive);
    motor_Test_CANReceive_Start(&motor_Test_B.CANReceive1,
      &motor_Test_DW.CANReceive1, &motor_Test_P.CANReceive1);

    /* Start for MATLABSystem: '<Root>/CAN Transmit' */
    motor_Test_DW.obj.sockHandleDataFrames = 0;
    motor_Test_DW.obj.sockHandleErrorFrames = 0;
    motor_Test_DW.obj.notFirstStep = false;
    motor_Test_DW.obj.isInitialized = 0;
    motor_Test_DW.obj.matlabCodegenIsDeleted = false;
    motor_Test_DW.objisempty = true;
    for (i = 0; i < 28; i++) {
      motor_Test_DW.obj.IdentifierType[i] = tmp[i];
    }

    motor_Test_DW.obj.SetIdentifierType = true;
    motor_Test_SystemCore_setup_c(&motor_Test_DW.obj);

    /* End of Start for MATLABSystem: '<Root>/CAN Transmit' */
  }
}

/* Model terminate function */
void motor_Test_terminate(void)
{
  char_T canInterface[5];
  motor_Test_CANReceive_Term(&motor_Test_DW.CANReceive);
  motor_Test_CANReceive_Term(&motor_Test_DW.CANReceive1);

  /* Terminate for MATLABSystem: '<Root>/CAN Transmit' */
  if (!motor_Test_DW.obj.matlabCodegenIsDeleted) {
    motor_Test_DW.obj.matlabCodegenIsDeleted = true;
    if ((motor_Test_DW.obj.isInitialized == 1) &&
        motor_Test_DW.obj.isSetupComplete && motor_Test_DW.obj.Initialized) {
      canInterface[0] = 'c';
      canInterface[1] = 'a';
      canInterface[2] = 'n';
      canInterface[3] = '0';
      canInterface[4] = '\x00';
      MW_clearSocket(&motor_Test_DW.obj.sockHandleDataFrames, &canInterface[0]);
      MW_clearSocket(&motor_Test_DW.obj.sockHandleErrorFrames, &canInterface[0]);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/CAN Transmit' */
}
