/*
 * motor_Test.c
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

/* Block states (default storage) */
DW_motor_Test_T motor_Test_DW;

/* Real-time model */
static RT_MODEL_motor_Test_T motor_Test_M_;
RT_MODEL_motor_Test_T *const motor_Test_M = &motor_Test_M_;
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void motor_Test_step(void)
{
  int32_T i;
  char_T b[5];
  static const char_T tmp[5] = "none";

  /* MATLABSystem: '<Root>/LED' incorporates:
   *  Constant: '<Root>/Threshold '
   *  Product: '<Root>/Multiply'
   *  RandomNumber: '<Root>/Random Number'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  UnitDelay: '<S1>/Output'
   */
  for (i = 0; i < 5; i++) {
    b[i] = tmp[i];
  }

  EXT_LED_setTrigger(0U, &b[0]);
  EXT_LED_write(0U, (uint8_T)((real_T)motor_Test_DW.Output_DSTATE *
    motor_Test_DW.NextOutput > motor_Test_P.Threshold_Value));

  /* End of MATLABSystem: '<Root>/LED' */

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  Constant: '<S2>/FixPt Constant'
   *  UnitDelay: '<S1>/Output'
   */
  motor_Test_DW.Output_DSTATE = (uint8_T)((uint32_T)motor_Test_DW.Output_DSTATE
    + motor_Test_P.FixPtConstant_Value);

  /* Switch: '<S3>/FixPt Switch' */
  if (motor_Test_DW.Output_DSTATE > motor_Test_P.CounterLimited_uplimit) {
    /* Sum: '<S2>/FixPt Sum1' incorporates:
     *  Constant: '<S3>/Constant'
     *  UnitDelay: '<S1>/Output'
     */
    motor_Test_DW.Output_DSTATE = motor_Test_P.Constant_Value;
  }

  /* End of Switch: '<S3>/FixPt Switch' */

  /* Update for RandomNumber: '<Root>/Random Number' */
  motor_Test_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&motor_Test_DW.RandSeed)
    * motor_Test_P.RandomNumber_StdDev + motor_Test_P.RandomNumber_Mean;
}

/* Model initialize function */
void motor_Test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(motor_Test_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&motor_Test_DW, 0,
                sizeof(DW_motor_Test_T));

  {
    int32_T i;
    char_T b[5];
    static const char_T tmp[5] = "none";

    /* Start for MATLABSystem: '<Root>/LED' */
    motor_Test_DW.obj.matlabCodegenIsDeleted = false;
    motor_Test_DW.objisempty = true;
    motor_Test_DW.obj.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b[i] = tmp[i];
    }

    EXT_LED_setTrigger(0U, &b[0]);
    motor_Test_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/LED' */
  }

  {
    real_T tmp;
    int32_T r;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for Sum: '<S2>/FixPt Sum1' incorporates:
     *  UnitDelay: '<S1>/Output'
     */
    motor_Test_DW.Output_DSTATE = motor_Test_P.Output_InitialCondition;

    /* InitializeConditions for RandomNumber: '<Root>/Random Number' */
    tmp = floor(motor_Test_P.RandomNumber_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    motor_Test_DW.RandSeed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t)
      + r;
    if (motor_Test_DW.RandSeed < 1U) {
      motor_Test_DW.RandSeed = 1144108930U;
    } else if (motor_Test_DW.RandSeed > 2147483646U) {
      motor_Test_DW.RandSeed = 2147483646U;
    }

    motor_Test_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&motor_Test_DW.RandSeed) * motor_Test_P.RandomNumber_StdDev +
      motor_Test_P.RandomNumber_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Random Number' */
  }
}

/* Model terminate function */
void motor_Test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/LED' */
  if (!motor_Test_DW.obj.matlabCodegenIsDeleted) {
    motor_Test_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED' */
}
