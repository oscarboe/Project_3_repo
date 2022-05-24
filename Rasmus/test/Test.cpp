#include <stdio.h>

int main()
{

	int fd;
	int dataSentbyte = 0b11111111

	fd = open("/dev/spi_driver", O_RDWR);
	write(fd, &dataSentByte, 1);
	int dataSentbyte = 0b10000001
	write(fd, &dataSentByte, 1);
	int dataSentbyte = 0b00011000
	write(fd, &dataSentByte, 1);

	close(fd);

	return 0;
}