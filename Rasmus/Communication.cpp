#include "communication.h"
#include <stdio.h>


void communication::send(int data)
{
	int fd;

	fd = open("/dev/spi_driver", O_RDWR);
	write(fd, data, 1);
	close(fd);

}



void communication::dataSent()
{
	int fd;
	int dataSentbyte = 0b11111111

	fd = open("/dev/spi_driver", O_RDWR);
	write(fd, dataSentByte, 1);
	close(fd);

}



void communication::sendPayout(int symbolNumber)
{
	int fd, payoutData;
	switch (symbolNumber)
	{
	case 1:
		payoutData = 0b10100001
		break;
	case 2:
		payoutData = 0b10100010
		break;
	case 3:
		payoutData = 0b10100011
		break;
	case 4:
		payoutData = 0b10100100
		break;
	case 5:
		payoutData = 0b10100101
		break;
	case 6:
		payoutData = 0b10100111
		break;
	case 7:
		payoutData = 0b10101000
		break;
	case 8:
		payoutData = 0b10101001
		break;
	case 9:
		payoutData = 0b10101010
		break;
	case 10:
		payoutData = 0b10101011
		break;
	case 11:
		payoutData = 0b10101100
		break;
	case 12:
		payoutData = 0b10101101
		break;
	default:
		break;
	}

	fd = open("/dev/spi_driver", O_RDWR);
	write(fd, payoutData, 1);
	close(fd);

}

