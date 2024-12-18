#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <linux/types.h>

#include <sys/ioctl.h>
#include <asm/ioctl.h>


#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include "i2c_lib.h"
#include "i2c_lib_version.h"
#include "cfe.h"


int32 I2C_LibInit(void)
{
    OS_printf("I2C LIB Initialized. Version v%d.%d\n", I2C_LIB_MAJOR_VERSION, I2C_LIB_REVISION);

    return CFE_SUCCESS;
}


int32 I2C_DeviceInit(uint8 adapter_num, uint8 devAddr)
{
    /*
    adapter_num: /dev/i2c-(THIS NUMBER)
    devAddr: device address like '0x68'
    */
    char dev[15];

    sprintf(dev, "/dev/i2c-%d", adapter_num);

    int32 fd = open(dev, O_RDWR);
    if(fd < 0)
    {
        fprintf(stderr, "Error: Can't open i2c device %s, %s\n", dev, strerror(errno));
        return -1;
    }

    if(ioctl(fd, I2C_SLAVE, devAddr) < 0)
    {
        fprintf(stderr, "Error: Can't access to i2c device address %x, %s\n", devAddr, strerror(errno));
        return -1;
    }
    return fd;
}


uint8 I2C_ReadReg8(int32 fd, uint8 regAddr)
{
    /*
    fd: file descripter
    regAddr: Register Address that you want to read
    */
    union i2c_smbus_data data;
    struct i2c_smbus_ioctl_data args; //This is defined at linux/i2c-dev.h

    args.read_write = I2C_SMBUS_READ;
    args.command = regAddr;
    args.size = I2C_SMBUS_BYTE_DATA; // 1byte
    args.data = &data;

    if (ioctl(fd, I2C_SMBUS, &args) < 0) { return -1; }

    return data.byte & 0xFF;
}


int32 I2C_WriteReg8(int32 fd, uint8 regAddr, uint8 value)
{
    /*
    fd: file descripter
    regAddr: Register Address that you want to write on
    value: The value to write in the register
    */
    union i2c_smbus_data data;
    struct i2c_smbus_ioctl_data args;
    data.byte = value;

    args.read_write = I2C_SMBUS_WRITE;
    args.command = regAddr;
    args.size = I2C_SMBUS_BYTE_DATA; // 1byte
    args.data = &data;

    if (ioctl(fd, I2C_SMBUS, &args) < 0) { return -1; }

    return CFE_SUCCESS;
    
}

int32 I2C_Close(int32 fd)
{
    int32 status = close(fd);
    if(status < 0)
    {
        fprintf(stderr, "Error: Can't close I2C Device %s\n", strerror(errno));
        return -1;
    }

    return CFE_SUCCESS;
}



