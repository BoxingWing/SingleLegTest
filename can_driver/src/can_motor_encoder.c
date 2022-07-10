#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/sockios.h>
#include <sys/time.h>
#include <fcntl.h>

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
    //struct timeval tv;
    //tv.tv_sec = 1;
    //tv.tv_usec = 0;

	//printf("CAN Sockets Demo\r\n one-round send test\n");

	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		//perror("Socket");
		return 1;
	}
    
	strcpy(ifr.ifr_name, "can1" );
	ioctl(s, SIOCGIFINDEX, &ifr);
    fcntl(s, F_SETFL, O_NONBLOCK); // non-blocking mode
    // set timeout for blocking mmode
    //setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    int bufsize = 128;
    setsockopt(s, SOL_SOCKET, SO_RCVBUF, &bufsize, sizeof(bufsize));

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
    int ii;
	int nbytes;
    int errFlag[dev_Num];
    for (i=0;i<dev_Num;i++)
        errFlag[i]=0;
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    struct timeval tvOld;
    tvOld.tv_sec = 1;
    tvOld.tv_usec = 0;

    int32_t recIDtmp[dev_Num];
    int32_t recDatatmp[dev_Num*8];
    for (i=0;i<dev_Num*8;i++)
        recDatatmp[i]=0;
	for (i=0;i<dev_Num;i++)
	{
        errFlag[i]=0;
        struct can_frame recv_frame_tmp;
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
        //lseek(s, 0, SEEK_SET);
        //read(s, &recv_frame_tmp, sizeof(struct can_frame));
		if (write(s, &send_frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) 
		{
			errFlag[i]=2;
		}
        //ioctl(s, SIOCGSTAMP, &tvOld);
        usleep(100);

        //do{
		nbytes = read(s, &recv_frame_tmp, sizeof(struct can_frame));
        //ioctl(s, SIOCGSTAMP, &tv);}
        //while((tv.tv_sec>tvOld.tv_sec || tv.tv_usec>tvOld.tv_usec));

 		if (nbytes < 0) 
        {
            errFlag[i]=3;}

        /*if (errFlag[i]>1)
        {
        for (ii=0;ii<8;ii++)
			    rec_RawData[i*8+ii]=0xee;
        }
        else*/
        {for (ii=0;ii<8;ii++)
			    recDatatmp[i*8+ii]=recv_frame_tmp.data[ii];
        }
        recIDtmp[i]=recv_frame_tmp.can_id;
	}
    int matchIdx=0;
    for (i=0;i<dev_Num;i++)
    {
        recv_ID[i]=canID_arry[i];
        matchIdx=-1;
        for (ii=0;ii<dev_Num;ii++)
        {
            if (recv_ID[i]==recIDtmp[ii])
            {matchIdx=ii;break;}
        }
        if (matchIdx==-1)
        {
            for (ii=0;ii<8;ii++)
                rec_RawData[i*8+ii]=0xee;
        }
        else
        {
            for (ii=0;ii<8;ii++)
                rec_RawData[i*8+ii]=recDatatmp[matchIdx*8+ii];
        }
    }

    int sum=0;
    for (i=0;i<dev_Num;i++)
        sum+=errFlag[i];
	return sum;
}


/*
int batchMessage(int32_t* canID_arry, uint8_t* send_RawData, int32_t dev_Num, int32_t* recv_ID, uint8_t* rec_RawData)
{
    int i;
	int nbytes;
    int errFlag[4];
    for (i=0;i<4;i++)
        errFlag[i]=0;
    int32_t recvID_tmp[4];
    int32_t recData_tmp[32];

	for (i=0;i<dev_Num;i++)
	{
        errFlag[i]=0;
        struct can_frame recv_frame_tmp;
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
        //lseek(s, 0, SEEK_SET);
        //read(s, &recv_frame_tmp, sizeof(struct can_frame));
		if (write(s, &send_frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) 
		{
			errFlag[i]=2;
		}
    }

    for (i=0;i<dev_Num;i++)
    {
        //ioctl(s, SIOCGSTAMP, &tvOld);
        //usleep(100);

        //do{
		nbytes = read(s, &recv_frame_tmp, sizeof(struct can_frame));
        //ioctl(s, SIOCGSTAMP, &tv);}
        //while((tv.tv_sec>tvOld.tv_sec || tv.tv_usec>tvOld.tv_usec));

 		if (nbytes < 0) 
        {
            errFlag[i]=3;}

		int ii;
        if (errFlag[i]>1)
        {
        for (ii=0;ii<8;ii++)
			    recData_tmp[i*8+ii]=0xee;
        }
        else
        {for (ii=0;ii<8;ii++)
			   recData_tmp[i*8+ii]=recv_frame_tmp.data[ii];
        }
        recvID_tmp[i]=recv_frame_tmp.can_id;
	}


    int sum=0;
    for (i=0;i<5;i++)
        sum+=errFlag[i];
	return sum;
}*/



int close_port()
{
	if (close(s) < 0) {
		//sperror("Close");
		return 1;
	}

	return 0;
}