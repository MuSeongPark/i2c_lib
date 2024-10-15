#ifndef I2C_LIB_H
#define I2C_LIB_H

#include "i2c_lib.h"
#include "cfe.h"

int32 I2C_LibInit(void);
int32 I2C_DeviceInit(uint8 adapter_num, uint8 devAddr);
uint8 I2C_ReadReg8(int32 fd, uint8 regAddr);
int32 I2C_WriteReg8(int32 fd, uint8 regAddr, uint8 value);


#endif