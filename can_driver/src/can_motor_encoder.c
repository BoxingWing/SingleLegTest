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
struct can_frame send_frame;
struct can_frame recv_frame;

int canSetup()
{
    struct sockaddr_can addr;
	struct ifreq ifr;


	//printf("CAN Sockets Demo\r\n one-round send test\n");

	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		//perror("Socket");
		return 1;
	}

	strcpy(ifr.ifr_name, "can1" );
	ioctl(s, SIOCGIFINDEX, &ifr);

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		//perror("Bind");
		return 1;
	}

    return 0;
}

int batchMessage(int32_t* canID_arry, uint8_t* send_RawData, int32_t dev_Num, int32_t* recv_ID, uint8_t* rec_RawData)
{
    int i;
	int nbytes;
	for (i=0;i<dev_Num;i++)
	{
		send_frame.can_id = canID_arry[i];
		send_frame.can_dlc = 8;
        send_frame.data[0] = send_RawData[i*8];
		send_frame.data[1] = send_RawData[i*8+1];
		send_frame.data[2] = send_RawData[i*8+2];
		send_frame.data[3] = send_RawData[i*8+3];
		send_frame.data[4] = send_RawData[i*8+4];
		send_frame.data[5] = send_RawData[i*8+5];
		send_frame.data[6] = send_RawData[i*8+6];
		send_frame.data[7] = send_RawData[i*8+7];
		if (write(s, &send_frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) 
		{
			//perror("Write");
			return i+1;
		}
		
		nbytes = read(s, &recv_frame, sizeof(struct can_frame));

 		if (nbytes < 0) {
			//perror("Read");
			return i+11;
		}
		int ii;
		for (ii=0;ii<recv_frame.can_dlc;ii++)
			rec_RawData[i*8+ii]=recv_frame.data[ii];

		recv_ID[i]=recv_frame.can_id;
	}
	return 0;
}
	

int close_port()
{
	if (close(s) < 0) {
		//sperror("Close");
		return 1;
	}

	return 0;
}