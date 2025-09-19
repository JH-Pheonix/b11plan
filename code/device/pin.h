#ifndef _DEVICE_PIN_H_
#define _DEVICE_PIN_H_

#include "zf_common_headfile.h"

// IMU pin
#define IMU_SPI_INDEX (SPI_0)
#define IMU_CS_PIN (P20_13)
#define IMU_SPC_PIN (SPI0_SCLK_P20_11)
#define IMU_MOSI_PIN (SPI0_MOSI_P20_14)
#define IMU_MISO_PIN (SPI0_MISO_P20_12)

#define IMU_RST_PIN (P20_12)
#define IMU_SPEED (2 * 1000 * 1000)

// tft180 pin
#define LCD_SPI (SPI_2)
#define LCD_SCL_PIN (SPI2_SCLK_P15_3)
#define LCD_SDA_PIN (SPI2_MOSI_P15_5)
#define LCD_SDA_PIN_IN (SPI2_MISO_P15_4) // TFT没有MISO引脚，但是这里任然需要定义，在spi的初始化时需要使用
#define LCD_RES_PIN (P15_1)              // 复位引脚
#define LCD_DC_PIN (P15_0)               // 数据/命令引脚
#define LCD_CS_PIN (P15_2)               // 片选引脚
#define LCD_BL_PIN (P15_4)               // 背光引脚

// key pin
//                A    , C    , B    , D    , CENTER
#define MKEY_NAME KEY_U, KEY_D, KEY_L, KEY_R, KEY_B
#define MKEY_LIST P11_6, P11_9, P11_3, P11_10, P11_11

#endif