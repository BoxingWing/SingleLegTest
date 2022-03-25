#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int main(int argc, char **argv)
{
	int s; 
	struct sockaddr_can addr;
	struct ifreq ifr;
	struct can_frame send_frame;

	struct can_frame recv_frame;

	printf("CAN Sockets Demo\r\n one-round send test\n");

	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}

	strcpy(ifr.ifr_name, "can1" );
	ioctl(s, SIOCGIFINDEX, &ifr);

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return 1;
	}

	send_frame.can_id = 0x141;
	send_frame.can_dlc = 8;
//	sprintf(frame.data, "Hello");
        send_frame.data[0] = 0x94;
	send_frame.data[1] = 0;
	send_frame.data[2] = 0;
	send_frame.data[3] = 0;
	send_frame.data[4] = 0;
	send_frame.data[5] = 0;
	send_frame.data[6] = 0;
	send_frame.data[7] = 0;
	// send the ask frame
	if (write(s, &send_frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
		perror("Write");
		return 1;
	}

	// get the respond frame
	int nbytes;
	nbytes = read(s, &recv_frame, sizeof(struct can_frame));

 	if (nbytes < 0) {
		perror("Read");
		return 1;
	}

	printf("0x%03X [%d] ",recv_frame.can_id, recv_frame.can_dlc);
	int i;
	for (i = 0; i < recv_frame.can_dlc; i++)
		printf("%02X ",recv_frame.data[i]);
	printf("\n");


	if (close(s) < 0) {
		perror("Close");
		return 1;
	}

	return 0;
}
