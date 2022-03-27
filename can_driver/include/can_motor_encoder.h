#ifndef _CANDRIVER_RASPI_H_
#define _CANDRIVER_RASPI_H_
#include "rtwtypes.h"

int canSetup(char* canPort);
int batchMessage(int32_T* canID_arry, uint8_T* send_RawData, uint8_T dev_Num, int32_T* recv_ID, uint8_T* rec_RawData);
int close_port();

#endif //_CANDRIVER_RASPI_H_