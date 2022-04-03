#ifndef _CANDRIVER_RASPI_H_
#define _CANDRIVER_RASPI_H_
#include "stdint.h"

int canSetup();
int batchMessage(int32_t* canID_arry, uint8_t* send_RawData, int32_t dev_Num, int32_t* recv_ID, uint8_t* rec_RawData);
int close_port();

#endif //_CANDRIVER_RASPI_H_