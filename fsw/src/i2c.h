#ifndef i2c_h
#define i2c_h

//include header files
#include <stdint.h>

//MSGs for Error Handling
#define IO_I2C_SUCCESS                      0
#define IO_I2C_ERROR                       -1
#define IO_I2C_ERROR_INIT                  -2
#define IO_I2C_ERROR_IOCTL                 -3
#define IO_I2C_ERROR_WRITE                 -4
#define IO_I2C_ERROR_READ                  -5

//I2C Bus Name definition
#define I2C_BUS_0 "/dev/i2c-0"

//Functions
void I2C_Init(void);
int32_t I2C_Read_ADCS(uint8_t address, uint8_t reg, void *rx_buffer, uint8_t len);
int32_t I2C_Write_ADCS(uint8_t address, uint8_t reg, void *tx_buffer, uint8_t len);

#endif