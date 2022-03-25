#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "can_motor_encoder.h"

int s; //socket handle

int canSetup(char* canPort)
{
    struct sockaddr_can addr;
	struct ifreq ifr;
	struct can_frame send_frame;

	struct can_frame recv_frame;

	//printf("CAN Sockets Demo\r\n one-round send test\n");

	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}

	strcpy(ifr.ifr_name, canPort );
	ioctl(s, SIOCGIFINDEX, &ifr);

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return 1;
	}

    return 0;
}

int batchMessage(int32_T* motor_canID_arry, uint8_T* motor_canRawData, uint8_T motorNum, int32_T encoder_canID, uint8_T encoder_canRawData, uint8_T encoderEN)
{
    
}