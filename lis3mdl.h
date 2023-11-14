
/**
  ******************************************************************************
  * @file    lis3mdl.h
  * @author  Sheikh Talha
  * @brief   This file contains functions prototypes for the
  *          lis3mdl.c driver.
  ******************************************************************************
  *
  * Already available API functions
  * i2c_read (uint8_t bus_address, uint8_t register_address, uint8_t *buffer, uint16_t length)
  * i2c_write(uint8_t bus_address, uint8_t register_address, uint8_t *data, uint16_t length)
  *
  * Retrieve the device’s full-scale configuration
  * device_full_scale_config_get(reg_value *, reg_lis3dl *)
  *
  * Retrieve the device’s output data rate
  * device_data_rate_get(reg_value *, reg_lis3dl *)
  *
  * Set the device’s output data rate
  * device_data_rate_set(reg_value *, reg_lis3dl *)
  *
  *	Enable or disable the device’s interrupt pin
  *	device_intupt_pin_config_set(reg_value *, reg_lis3dl *)
  *
  * Read the output data of a specific axis
  * device_axis_value_get_(reg_value *, reg_lis3dl *)
  *
  ******************************************************************************
  */



#include <stdint.h>
#include <stddef.h>
#include <math.h>


#define ENDIAN 				Little


typedef union 
{
  uint8_t bit0       : 1;
  uint8_t bit1       : 1;
  uint8_t bit2       : 1;
  uint8_t bit3       : 1;
  uint8_t bit4       : 1;
  uint8_t bit5       : 1;
  uint8_t bit6       : 1;
  uint8_t bit7       : 1;
  uint8_t value;
}reg_lis3dl;

typedef union
{
  reg_lis3dl_cnt_1      reg1;
  reg_lis3dl_cnt_2      reg2;
  reg_lis3dl_cnt_4      reg4;

} lis3mdl_reg;

typedef struct 
{
  uint8_t not_used_01     : 1;
  uint8_t ble             : 1;
  uint8_t omz             : 2;
  uint8_t not_used_02     : 4;
}reg_lis3dl_cnt_4;

typedef struct 
{
  uint8_t not_used_01     : 2;
  uint8_t soft_rst        : 1;
  uint8_t reboot          : 1;
  uint8_t not_used_02     : 1;
  uint8_t fs              : 2;
  uint8_t not_used_03     : 1;
}reg_lis3dl_cnt_2;

typedef struct 
{
  uint8_t st              : 1;
  uint8_t om              : 6;
  uint8_t temp_en         : 1;
  uint8_t value;
}reg_lis3dl_cnt_1;

typedef union 
{
  uint8_t    read_8    ;
  uint8_t   write_8    ;
}reg_value;

typedef struct
{
  int8_t   value_low    ;
  int8_t   value_high   ;
}axis_value;

typedef enum
{
  LIS3MDL_LP_Hz625      = 0x00,
  LIS3MDL_LP_1kHz       = 0x01,
  LIS3MDL_MP_560Hz      = 0x11,
  LIS3MDL_HP_300Hz      = 0x21,
  LIS3MDL_UHP_155Hz     = 0x31,

  LIS3MDL_LP_1Hz25      = 0x02,
  LIS3MDL_LP_2Hz5       = 0x04,
  LIS3MDL_LP_5Hz        = 0x06,
  LIS3MDL_LP_10Hz       = 0x08,
  LIS3MDL_LP_20Hz       = 0x0A,
  LIS3MDL_LP_40Hz       = 0x0C,
  LIS3MDL_LP_80Hz       = 0x0E,

  LIS3MDL_MP_1Hz25      = 0x12,
  LIS3MDL_MP_2Hz5       = 0x14,
  LIS3MDL_MP_5Hz        = 0x16,
  LIS3MDL_MP_10Hz       = 0x18,
  LIS3MDL_MP_20Hz       = 0x1A,
  LIS3MDL_MP_40Hz       = 0x1C,
  LIS3MDL_MP_80Hz       = 0x1E,

  LIS3MDL_HP_1Hz25      = 0x22,
  LIS3MDL_HP_2Hz5       = 0x24,
  LIS3MDL_HP_5Hz        = 0x26,
  LIS3MDL_HP_10Hz       = 0x28,
  LIS3MDL_HP_20Hz       = 0x2A,
  LIS3MDL_HP_40Hz       = 0x2C,
  LIS3MDL_HP_80Hz       = 0x2E,

  LIS3MDL_UHP_1Hz25     = 0x32,
  LIS3MDL_UHP_2Hz5      = 0x34,
  LIS3MDL_UHP_5Hz       = 0x36,
  LIS3MDL_UHP_10Hz      = 0x38,
  LIS3MDL_UHP_20Hz      = 0x3A,
  LIS3MDL_UHP_40Hz      = 0x3C,
  LIS3MDL_UHP_80Hz      = 0x3E,

} data_rate_lis3mdl;

typedef enum
{
  LIS3MDL_4_GAUSS  ,
  LIS3MDL_8_GAUSS  ,
  LIS3MDL_12_GAUSS ,
  LIS3MDL_16_GAUSS ,
}fs_lis3dl;



#define LIS3MDL_I2C_ADD_R      0x39U
#define LIS3MDL_I2C_ADD_W      0x38U


#define LIS3MDL_ID             0x3DU
#define LIS3MDL_WHO_AM_I       0x0FU
#define LIS3MDL_CTRL_REG1      0x20U
#define LIS3MDL_CTRL_REG2      0x21U
#define LIS3MDL_CTRL_REG3      0x22U
#define LIS3MDL_CTRL_REG4      0x23U
#define LIS3MDL_CTRL_REG5      0x24U
#define LIS3MDL_STATUS_REG     0x27U
#define LIS3MDL_OUT_X_L        0x28U
#define LIS3MDL_OUT_X_H        0x29U
#define LIS3MDL_OUT_Y_L        0x2AU
#define LIS3MDL_OUT_Y_H        0x2BU
#define LIS3MDL_OUT_Z_L        0x2CU
#define LIS3MDL_OUT_Z_H        0x2DU
#define LIS3MDL_TEMP_OUT_L     0x2EU
#define LIS3MDL_TEMP_OUT_H     0x2FU
#define LIS3MDL_INT_CFG        0x30U
#define LIS3MDL_INT_SRC        0x31U
#define LIS3MDL_INT_THS_L      0x32U
#define LIS3MDL_INT_THS_H      0x33U


uint16_t i2c_read(uint8_t bus_address, uint8_t register_address, uint8_t *buffer, uint16_t length);
uint16_t i2c_write(uint8_t bus_address, uint8_t register_address, uint8_t *data, uint16_t length);

int32_t device_config_set(reg_value *val);
int32_t device_full_scale_config_get(reg_value *val);
int32_t device_interrupt_pin_config_set(reg_value *val);
int32_t device_axis_value_get_(reg_value *val);
int32_t device_data_rate_set(reg_value *val);
int32_t device_data_rate_get(axis_value *val, uint8_t axis_register_low, uint8_t axis_register_high);