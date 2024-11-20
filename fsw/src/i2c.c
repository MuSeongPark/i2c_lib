/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                     		<< I2C Source File >>                      	     */
/*				  Purpose: I2C Communication using read&write		         */
/*                          Developer: Museong Park                          */
/*                        Revision Date: 2024 11 20                          */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <stdio.h> // printf
#include <stdint.h> // uint8_t
#include <fcntl.h> // open
#include <unistd.h> // read, write
#include <string.h> // memcpy, strcmp
#include <sys/ioctl.h> // ioctl
#include <linux/i2c-dev.h> // I2C_SLAVE
#include <errno.h>

#include "i2c.h"

static int32_t i2c_fd_0;

void I2C_Init(void)
{
    i2c_fd_0 = open(I2C_BUS_0, O_RDWR);
	if (i2c_fd_0 < 0)
    {
		fprintf(stderr, "I2C Error: I2C_BUS_0 Open Error, %s (Error code : %d)\n", strerror(errno), IO_I2C_ERROR_INIT);
        return;
    }
}

int32_t I2C_Read_ADCS(uint8_t address, uint8_t reg, void *rx_buffer, uint8_t len)
{
	uint8_t reg_buffer[1] = {reg};
    if(i2c_fd_0 < 0)
    {
        return IO_I2C_ERROR_INIT;
    }
    if (ioctl(i2c_fd_0, I2C_SLAVE, address) < 0)
    {
        return IO_I2C_ERROR_IOCTL;
    }
    if (write(i2c_fd_0, reg_buffer, 1) < 0)
    {
        return IO_I2C_ERROR_WRITE;
    }
    if (read(i2c_fd_0, rx_buffer, len) < 0)
    {
        return IO_I2C_ERROR_READ;
    }

    return IO_I2C_SUCCESS;
}

int32_t I2C_Write_ADCS(uint8_t address, uint8_t reg, void *tx_buffer, uint8_t len)
{
	uint8_t reg_buffer[len+1];
	reg_buffer[0] = reg;

	memcpy(&reg_buffer[1], tx_buffer, len);
    if(i2c_fd_0 < 0)
    {
        return IO_I2C_ERROR_INIT;
    }
	if(ioctl(i2c_fd_0, I2C_SLAVE, address) < 0)
	{
		return IO_I2C_ERROR_IOCTL;
	}
	if(write(i2c_fd_0, reg_buffer, len+1) < 0)
	{
		return IO_I2C_ERROR_WRITE;
	}

	return IO_I2C_SUCCESS;
}