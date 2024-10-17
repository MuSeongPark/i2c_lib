# core Flight System (cFS) I2C Library

## Introduction
본 cFS Library는 리눅스 디바이스 드라이버를 바탕으로 구현된 i2c 라이브러리이다. <br>
초기화 함수인 I2C_LibInit로 라이브러리가 초기화 된다.


```C

int32 I2C_LibInit(void) //라이브러리 초기화
int32 I2C_DeviceInit(uint8 adapter_num, uint8 devAddr) //I2C 장치 초기화
uint8 I2C_ReadReg8(int32 fd, uint8 regAddr) //1byte 읽기
int32 I2C_WriteReg8(int32 fd, uint8 regAddr, uint8 value) //1byte 쓰기

```

## Required Software
cFS Framework (cFE, OSAL, PSP)를 요구합니다.<br>
cFE, OSAL, PSP를 포함한 통합 번들은 다음을 참고하세요.<br>
[core Flight System](https://github.com/nasa/cFS)

## About cFS
cFS는 나사 고다드 우주 비행 센터(NASA Goddard Space Flight Center)에서 개발된 소프트웨어 프레임 워크로, 기본적으로 인공위성의 비행 소프트웨어(FSW) 또는 다른 임베디드 시스템 계열에 사용이 가능합니다.<br>
cFS는 재사용 가능한 소프트웨어 프레임워크로, 여러 애플리케이션과 cFE, 추상화계층 등을 포함하고 있습니다.<br>
cFS와 관련된 상세 설명은 다음을 참고하세요.<br>
[Details about cFS](http://cfs.gsfc.nasa.gov)
