cmake_minimum_required(VERSION 2.6.4)
project(CFE_I2C_LIB C)

include_directories(fsw/public_inc)
include_directories(fsw/src)

#include_directories(${CFECORE_SOURCE_DIR}/src/inc)
#include_directories(${CFEPSP_SOURCE_DIR}/fsw/inc)

aux_source_directory(fsw/src LIB_SRC_FILES)

add_cfe_app(i2c_lib ${LIB_SRC_FILES})