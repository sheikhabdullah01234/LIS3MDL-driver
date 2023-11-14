
/**
  ******************************************************************************
  * @file    lis3mdl.h
  * @author  Sheikh Talha
  * @brief   lis3mdl.c driver file.
  *          
  ******************************************************************************
  *
  * Already available API functions
  * i2c_read (uint8_t bus_address, uint8_t register_address, uint8_t *buffer, uint16_t length) 
  * return zero on success
  *
  * i2c_write(uint8_t bus_address, uint8_t register_address, uint8_t *data, uint16_t length)
  * return zero on success
  *
  * Retrieve the device’s full-scale configuration
  * device_full_scale_config_get(reg_value *)
  *
  * Retrieve the device’s output data rate
  * device_data_rate_get(reg_value *)
  *
  * Set the device’s output data rate
  * device_data_rate_set(reg_value *)
  *
  *	Enable or disable the device’s interrupt pin
  *	int32_t device_interrupt_pin_config_set(reg_value *val)
  *
  * Read the output data of a specific axis
  * device_data_rate_get(axis_value *val, uint8_t axis_register_low, uint8_t axis_register_high)
  *
  ******************************************************************************
  */
  
  #include "lis3mdl.h"
  
  
  /**
  * @brief  Full-scale configuration[set]
  *
  * 
  * @param  val      change the values of fs in reg CTRL_REG2
  * @retval          ret
  *
  */
int32_t device_full_scale_config_get(reg_value *val)
{
  reg_lis3dl_cnt_2 reg2;
  int32_t ret;

  ret = i2c_read (LIS3MDL_I2C_ADD_R, LIS3MDL_CTRL_REG2, (uint8_t *)&reg2, 1);

  switch (reg2.fs)
  {
    case LIS3MDL_4_GAUSS:
      *val = LIS3MDL_4_GAUSS;
      break;

    case LIS3MDL_8_GAUSS:
      *val = LIS3MDL_8_GAUSS;
      break;

    case LIS3MDL_12_GAUSS:
      *val = LIS3MDL_12_GAUSS;
      break;

    case LIS3MDL_16_GAUSS:
      *val = LIS3MDL_16_GAUSS;
      break;

    default:
      *val = LIS3MDL_4_GAUSS;
      break;
  }

  return ret;
}

/**
  * @brief  Output data rate selection[get]
  *
  * 
  * @param  val      Get the values of om in reg CTRL_REG1(ptr)
  * @retval          
  *
  */
int32_t device_data_rate_get(reg_value *)
{
  reg_lis3dl_cnt_1 reg1;
  int32_t ret;

  ret = i2c_read (LIS3MDL_I2C_ADD_R, LIS3MDL_CTRL_REG1, (uint8_t *)&reg1, 1);

  switch (reg1.om)
  {
    case LIS3MDL_LP_Hz625:
      *val = LIS3MDL_LP_Hz625;
      break;

    case LIS3MDL_LP_1kHz:
      *val = LIS3MDL_LP_1kHz;
      break;

    case LIS3MDL_MP_560Hz:
      *val = LIS3MDL_MP_560Hz;
      break;

    case LIS3MDL_HP_300Hz:
      *val = LIS3MDL_HP_300Hz;
      break;

    case LIS3MDL_UHP_155Hz:
      *val = LIS3MDL_UHP_155Hz;
      break;

    case LIS3MDL_LP_1Hz25:
      *val = LIS3MDL_LP_1Hz25;
      break;

    case LIS3MDL_LP_2Hz5:
      *val = LIS3MDL_LP_2Hz5;
      break;

    case LIS3MDL_LP_5Hz:
      *val = LIS3MDL_LP_5Hz;
      break;

    case LIS3MDL_LP_10Hz:
      *val = LIS3MDL_LP_10Hz;
      break;

    case LIS3MDL_LP_20Hz:
      *val = LIS3MDL_LP_20Hz;
      break;

    case LIS3MDL_LP_40Hz:
      *val = LIS3MDL_LP_40Hz;
      break;

    case LIS3MDL_LP_80Hz:
      *val = LIS3MDL_LP_80Hz;
      break;

    case LIS3MDL_MP_1Hz25:
      *val = LIS3MDL_MP_1Hz25;
      break;

    case LIS3MDL_MP_2Hz5:
      *val = LIS3MDL_MP_2Hz5;
      break;

    case LIS3MDL_MP_5Hz:
      *val = LIS3MDL_MP_5Hz;
      break;

    case LIS3MDL_MP_10Hz:
      *val = LIS3MDL_MP_10Hz;
      break;

    case LIS3MDL_MP_20Hz:
      *val = LIS3MDL_MP_20Hz;
      break;

    case LIS3MDL_MP_40Hz:
      *val = LIS3MDL_MP_40Hz;
      break;

    case LIS3MDL_MP_80Hz:
      *val = LIS3MDL_MP_80Hz;
      break;

    case LIS3MDL_HP_1Hz25:
      *val = LIS3MDL_HP_1Hz25;
      break;

    case LIS3MDL_HP_2Hz5:
      *val = LIS3MDL_HP_2Hz5;
      break;

    case LIS3MDL_HP_5Hz:
      *val = LIS3MDL_HP_5Hz;
      break;

    case LIS3MDL_HP_10Hz:
      *val = LIS3MDL_HP_10Hz;
      break;

    case LIS3MDL_HP_20Hz:
      *val = LIS3MDL_HP_20Hz;
      break;

    case LIS3MDL_HP_40Hz:
      *val = LIS3MDL_HP_40Hz;
      break;

    case LIS3MDL_HP_80Hz:
      *val = LIS3MDL_HP_80Hz;
      break;

    case LIS3MDL_UHP_1Hz25:
      *val = LIS3MDL_UHP_1Hz25;
      break;

    case LIS3MDL_UHP_2Hz5:
      *val = LIS3MDL_UHP_2Hz5;
      break;

    case LIS3MDL_UHP_5Hz:
      *val = LIS3MDL_UHP_5Hz;
      break;

    case LIS3MDL_UHP_10Hz:
      *val = LIS3MDL_UHP_10Hz;
      break;

    case LIS3MDL_UHP_20Hz:
      *val = LIS3MDL_UHP_20Hz;
      break;

    case LIS3MDL_UHP_40Hz:
      *val = LIS3MDL_UHP_40Hz;
      break;

    case LIS3MDL_UHP_80Hz:
      *val = LIS3MDL_UHP_80Hz;
      break;

    default:
      *val = LIS3MDL_UHP_80Hz;
      break;
  }

  return ret;
}

/**
  * @brief  Output data rate selection.[set]
  *
  * @param  val         change the values of om in reg CTRL_REG1
  * @retval             ret
  *
  */
int32_t device_data_rate_set(reg_value *val)
{
  reg_lis3dl_cnt_4 reg4;
  reg_lis3dl_cnt_1 reg1;
  int32_t ret;

  ret = i2c_read (LIS3MDL_I2C_ADD_R, LIS3MDL_CTRL_REG1, (uint8_t *)&reg1, 1);

  if (ret == 0)
  {
    reg1.om = (uint8_t)val;
    ret = i2c_write (LIS3MDL_I2C_ADD_W, LIS3MDL_CTRL_REG1, (uint8_t *)&reg1, 1);
  }

  if (ret == 0)
  {
    ret = i2c_read (LIS3MDL_I2C_ADD_R, LIS3MDL_CTRL_REG4, (uint8_t *)&reg4, 1);
  }

  if (ret == 0)
  {
    reg4.omz = (uint8_t)(((uint8_t) val >> 4) & 0x03U);
    ret = i2c_write (LIS3MDL_I2C_ADD_W, LIS3MDL_CTRL_REG4, (uint8_t *)&reg4, 1);
  }

  return ret;
}

/**
  * @brief  Interrupt Pin set
  *
  * @param  
  * @param  val      0x9 for Enable, 0x8 for disable
  * @retval          
  *
  */
int32_t device_interrupt_pin_config_set(reg_value *val)
{
  return i2c_write (LIS3MDL_I2C_ADD_W, LIS3MDL_INT_CFG, (uint8_t *)&val, 1);
}

/**
  * @brief  axis value[get]
  *
  * 
  * @param  val      buffer that stores data read
  * @retval          
  *
  */
int32_t device_data_rate_get(axis_value *val, uint8_t axis_register_low, uint8_t axis_register_high)
{
  int8_t buff[2];
  int32_t ret;

  
  ret = i2c_read (LIS3MDL_I2C_ADD_R, axis_register_low, (int8_t *)&buff[0], 1);
  if (ret == 0)
  {
	val.value_low = (int8_t)buff[0];
  }
  ret = i2c_read (LIS3MDL_I2C_ADD_R, axis_register_high, (int8_t *)&buff[1], 1);
  if (ret == 0)
  {
	val.value_high = (val.value_low  * 256) + (int8_t)buff[1];
  }	

  return ret;