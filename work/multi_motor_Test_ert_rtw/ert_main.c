#include <stdio.h>
#include <stdlib.h>
#include "multi_motor_Test.h"
#include "multi_motor_Test_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(multi_motor_Test_M) == (NULL)) &&
    !rtmGetStopRequested(multi_motor_Test_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(multi_motor_Test_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(multi_motor_Test_M, true);
      }

      if (rtmGetStopRequested(multi_motor_Test_M) == true) {
        rtmSetErrorStatus(multi_motor_Test_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(multi_motor_Test_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(multi_motor_Test_M, true);
      }
    }

    multi_motor_Test_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(multi_motor_Test_M) == (NULL)) &&
                      !rtmGetStopRequested(multi_motor_Test_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(multi_motor_Test_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  MW_killPyserver();
  mwRaspiTerminate();

  /* Terminate model */
  multi_motor_Test_terminate();
  rtExtModeShutdown(1);
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  mwRaspiInit();
  MW_launchPyserver();
  rtmSetErrorStatus(multi_motor_Test_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  multi_motor_Test_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(multi_motor_Test_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(multi_motor_Test_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(multi_motor_Test_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  myRTOSInit(0.005, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}