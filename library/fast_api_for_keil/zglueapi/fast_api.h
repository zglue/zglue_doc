/*!  ************************************************************************
 * @file include/fast_api.h
 * @brief Details the functions, structures, enums and macros
 *        implemented in the smart fabric driver
 *
 * @internal
 *   Copyright (C) 2017 Zglue  Inc. All rights reserved.
 *   author: Arjun Hary
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * @endinternal
 *
 *****************************************************************************/

#ifndef FAST_API_H
#define FAST_API_H

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

#include <stdint.h>
#include <stdbool.h>

/****************************************************************************
 * Public Definitions
 ****************************************************************************/

/*
 * FAST VERSION Definition
 */
#define FAST_VERSION_MAJOR        1
#define FAST_VERSION_MINOR        0

/*!
 * @endinternal
 */
#define CHIP_DESCRIPTOR_SIZE 10
#define FAST_I2C_ADDR 0x72
#define FAST_CHIP_ID_SIZE 8 /*8 bytes*/

/*!
 * @brief .
 *
 *
 */
typedef enum
{
  FAST_OK                               = 0,    /*!< 0000 */

  /* General failure codes */
  FAST_FAILURE                          = 1000, /*!< 1000 */
  FAST_NULL_POINTER,                            /*!< 1001 */
  FAST_PERMISSION_DENIED,                       /*!< 1002 */
  FAST_INVALID_ARGUMENT,                        /*!< 1003 */
  FAST_INVALID_OPERATION,                       /*!< 1004 */
  FAST_INVALID_OTP_ADDRESS,                     /*!< 1005 */
  FAST_OTP_OPERATION_FAILURE,                   /*!< 1006 */
  FAST_SYSTEM_ID_MISTMATCH,                     /*!< 1007 */
  FAST_OPERATION_TIMED_OUT,                     /*!< 1008 */
  FAST_API_INIT_FAIL,                           /*!< 1009 */
  FAST_MALLOC_FAIL,                             /*!< 1010 */
  FAST_INVALID_OPERATION_CHIP_IN_LPM,           /*!< 1011 */
  FAST_INVALID_OPERATION_CHIP_IN_ULPM,          /*!< 1012 */
  FAST_INVALID_OPERATION_CHIP_IN_RCM,           /*!< 1013 */
  FAST_CRC_CHECK_FAIL,                          /*!< 1014 */
  FAST_FILE_OPEN_FAIL,                          /*!< 1015 */

  /* Hardware failure status */
  FAST_POWERON_FAILURE                  = 2000, /*!< 2000 */
  FAST_CHECKSUM_FAILURE,                        /*!< 2001 */
  FAST_BOOT_CONFIG_INVALID,                     /*!< 2002 */
  FAST_INVALID_ID,                              /*!< 2003 */
  FAST_RDY_FAILURE,                             /*!< 2004 */
  FAST_HVLDO_OVER_CURRENT_FAILURE,              /*!< 2005 */
  FAST_VRAIL1_OVER_CURRENT_FAILURE,             /*!< 2006 */
  FAST_VRAIL2_OVER_CURRENT_FAILURE,             /*!< 2007 */
  FAST_VRAIL3_OVER_CURRENT_FAILURE,             /*!< 2008 */
  FAST_BOOST_CURRENT_LIMIT_FAILURE,             /*!< 2009 */
  FAST_BOOST_UVLO_FAILURE,                      /*!< 2010 */
  FAST_THERMAL_ALARM_FAILURE,                   /*!< 2011 */
  FAST_MCU_IS_ON_FAST_FAIL,                     /*!< 2012 */


  /* Power state failure codes */
  FAST_INVALID_POWER_STATE              = 3000, /*!< 3000 */
  FAST_INVALID_POWER_STATE_TRANSITION,          /*!< 3001 */
  FAST_POWER_MANAGEMENT_TIMEOUT,                /*!< 3002 */
  FAST_ALREADY_IN_SAME_POWER_STATE,             /*!< 3003 */
  FAST_INVALID_POWER_STATE_OPERATION,           /*!< 3004 */
  FAST_ULPM_WAKEUP_ERROR,                       /*!< 3005 */
  FAST_LPM_FSM_NOT_ENABLED,                     /*!< 3006 */
  FAST_LPM_FSM_ALREADY_ENABLED,                 /*!< 3007 */

  /* Configuration error codes */
  FAST_NO_CONFIG_FILE_PRESENT           = 4000, /*!< 4000 */
  FAST_INVALID_CONFIG_FILE,                     /*!< 4001 */
  FAST_CONFIG_FILE_READ_FAILURE,                /*!< 4002 */
  FAST_CONFIG_FILE_WRITE_FAILURE,               /*!< 4003 */
  FAST_INVALID_CONFIG_FILE_ID,                  /*!< 4004 */
  FAST_INVALID_CHIP_ID,                         /*!< 4005 */
  FAST_CHIP_CONNECT_FAILURE,                    /*!< 4006 */
  FAST_SYSTEM_CONNECT_FAILURE,                  /*!< 4007 */
  FAST_CHIP_DISCONNECT_FAILURE,                 /*!< 4008 */
  FAST_SYSTEM_DISCONNECT_FAILURE,               /*!< 4009 */


  /* Register operation error codes */
  FAST_INVALID_REGISTER_ADDRESS         = 5000, /*!< 5000 */
  FAST_REG_WRITE_FAILURE,                       /*!< 5001 */
  FAST_REG_READ_FAILURE,                        /*!< 5002 */

  /* GPIO expander error and SPI configuration codes */
  FAST_INVALID_GPIO_PORT                = 6000, /*!< 6000 */
  FAST_INVALID_GPIO_PIN,                        /*!< 6001 */
  FAST_INVALID_PIN_FUNCTION,                    /*!< 6002 */
  FAST_INVALID_PIN_LEVEL,                       /*!< 6003 */
  FAST_PIN_WRONG_CONFIGURATION,                 /*!< 6004 */
  FAST_SPI_CONFIG_INVALID_BIT_ORDER,            /*!< 6005 */
  FAST_SPI_CONFIG_INVALID_BIT_MODE,             /*!< 6006 */
  FAST_SPI_CONFIG_INVALID_POLARITY,             /*!< 6007 */
  FAST_SPI_CONFIG_INVALID_PHASE,                /*!< 6008 */

  /* PMIC/Analog error codes */
  FAST_INVALID_BOOST_VOLTAGE_OUT        = 7000, /*!< 7000 */
  FAST_INVALID_BOOST_BYPASS_MODE,               /*!< 7001 */
  FAST_INVALID_BOOST_CURRENT_LIMIT,             /*!< 7002 */
  FAST_INVALID_HVLDO_VOLTAGE_OUT,               /*!< 7003 */
  FAST_INVALID_HVLDO_BYPASS_MODE,               /*!< 7004 */
  FAST_INVALID_VRAIL_VOLTAGE_OUT,               /*!< 7005 */
  FAST_INVALID_VRAIL_NUMBER,                    /*!< 7006 */
  FAST_INVALID_THERMAL_MONITOR_ALARM_TEMP,      /*!< 7007 */
  FAST_INVALID_THERMAL_MONITOR_SHUTDOWN_TEMP,   /*!< 7008 */

  /* LED driver error codes */
  FAST_INVALID_LED_ID                   = 8000, /*!< 8000 */
  FAST_INVALID_DUTY_CYCLE,                      /*!< 8001 */
  FAST_INVALID_PERIOD,                          /*!< 8002 */
  FAST_INVALID_INTENSITY,                       /*!< 8003 */
  FAST_INVALID_BRIGHTNESS,                      /*!< 8004 */
} fast_status_e;

/*!
 *
 * @brief .
 *
 * Please refer to the Smartfabric data sheet Table 14
 *
 * FULL_PROGRAMMABLE_MODE:
 *                      The fully powered state. All of the smart fabric and its
 *                      peripherals are programmable in this state
 *
 * LIMITED_PROGRAMMABLE_MODE:
 *                      All the peripherals are programmable and enabled in this mode
 *                      but the routing cannot be changed and the chips/system cannot
 *                      be connected or disconnected
 *
 * LPM:
 *                      All the peripherals are enabled but not programmable. Slave
 *                      interface is turned on. Only operation in this state is to
 *                      go back to limited programming mode
 *
 * ULPM:
 *                      All parts of the FAST including the slave interfaces are powered
 *                      down. No I2C/SPI communication is possible . Wakeup from this mode
 *                      is by toggling the ULPM_Wake pin of the FAST
 *
 */
enum fast_power_state_e
{
  FAST_FULL_PROGRAMMABLE_MODE   = 0,    /*!< 0  */
  FAST_LIMITED_PROGRAMMABLE_MODE,       /*!< 1  */
  FAST_LPM,                             /*!< 2  */
  FAST_ULPM,                            /*!< 3  */
};


/*!
 *
 * @brief .
 *
 * FAST_DEBUG_LEVEL_0: No information will be printed or logged
 *
 * FAST_DEBUG_LEVEL_1: Error messages with error strings will be printed
 *
 * FAST_DEBUG_LEVEL_2: Warnings and error messages will be printed
 *
 */
typedef enum fast_debug_level_e
{
  FAST_DEBUG_LEVEL_0    = 0,         /*!< 0  */
  FAST_DEBUG_LEVEL_1,                /*!< 1  */
  FAST_DEBUG_LEVEL_2,                /*!< 2  */
  FAST_DEBUG_LEVEL_3,                /*!< 3  */
} fast_debug_level_t;


/*! @enum fast_gpio_functions_e
 *
 */
enum fast_gpio_functions_e
{
  FAST_GPIO_FUNCTION_OUTPUT = 0,                /*!< 0 */
  FAST_GPIO_FUNCTION_INPUT_RISING_EDGE,         /*!< 1 */
  FAST_GPIO_FUNCTION_INPUT_FALLING_EDGE,        /*!< 2 */
  FAST_GPIO_FUNCTION_INPUT_BOTH_EDGE,           /*!< 3 */
  /*! @internal use only */
  FAST_GPIO_INVALID_FUNCTION,                   /*!< 4 */
  /*! @endinternal */
};


/*!  @enum fast_gpio_port_e
 *
 */
typedef enum fast_gpio_port_e
{
  FAST_GPIO_PORT0 = 0,          /*!< 0 */
} fast_gpio_port_t;


/*! @enum fast_gpio_pin_e
 *
 */
typedef enum fast_gpio_pin_e
{
  FAST_GPIO_PIN0  = 0,          /*!< 0 */
  FAST_GPIO_PIN1,               /*!< 1 */
  FAST_GPIO_PIN2,               /*!< 2 */
  FAST_GPIO_PIN3,               /*!< 3 */
  FAST_GPIO_PIN4,               /*!< 4 */
  FAST_GPIO_PIN5,               /*!< 5 */
  FAST_GPIO_PIN6,               /*!< 6 */
  FAST_GPIO_PIN7,               /*!< 7 */
} fast_gpio_pin_t;


/*!  @enum fast_gpio_pin_level_e
 *
 */
/* FAST GPIO pin level */
enum fast_gpio_pin_level_e
{
  FAST_GPIO_PIN_LEVEL_LOW   = 0,        /*!< 0 */
  FAST_GPIO_PIN_LEVEL_HIGH,             /*!< 1 */
};

/*! @brief . */
typedef enum fast_gpio_pin_level_e fast_gpio_pin_level_t;

/*!  @union fast_gpio_interrupt_status_u;
 *
 */
typedef union __attribute__((packed))
{
  /*!
   *
   *
   */
  struct __attribute__((packed))
  {
    uint8_t    pin0_lvl_sts     : 1;    /*!< @brief . */
    uint8_t    pin1_lvl_sts     : 1;    /*!< @brief . */
    uint8_t    pin2_lvl_sts     : 1;    /*!< @brief . */
    uint8_t    pin3_lvl_sts     : 1;    /*!< @brief . */
    uint8_t    pin4_lvl_sts     : 1;    /*!< @brief . */
    uint8_t    pin5_lvl_sts     : 1;    /*!< @brief . */
    uint8_t    pin6_lvl_sts     : 1;    /*!< @brief . */
    uint8_t    pin7_lvl_sts     : 1;    /*!< @brief . */
  }
  mbits;                              /*!< @brief . */
  uint16_t data_uint16_t;               /*!< @brief . */
}
fast_gpio_interrupt_status_u;

/*!
 *
 * @brief .
 *
 */
typedef enum fast_led_id_e
{
  FAST_LED1   = 1,      /*!< 1 */
  FAST_LED2,            /*!< 2 */
  FAST_LED3,            /*!< 3 */
} fast_led_id_t;

/*!  @union fast_led_mask_u;
 *
 */
typedef union __attribute__((packed))
{
  /*!
   * @brief .
   */
  struct __attribute__((packed))
  {
    uint8_t    fast_led1             : 1; /*!< @brief . */
    uint8_t    fast_led2             : 1; /*!< @brief . */
    uint8_t    fast_led3             : 1; /*!< @brief . */
    uint8_t    reserved              : 5; /*!< @brief . */
  }
  mbits;                                /*!< @brief . */
  uint8_t data_uint8_t;                   /*!< @brief . */
}
fast_led_mask_u;

/* FAST LED brightness */
/*!
 *
 * @enum fast_led_brightness_range_control_e
 *
 */
typedef enum
{
  FAST_LED_BRIGHTNESS_3_125  = 0,       /*!<  0 */
  FAST_LED_BRIGHTNESS_6_25,             /*!<  1 */
  FAST_LED_BRIGHTNESS_9_375,            /*!<  2 */
  FAST_LED_BRIGHTNESS_12_5,             /*!<  3 */
  FAST_LED_BRIGHTNESS_15_625,           /*!<  4 */
  FAST_LED_BRIGHTNESS_18_75,            /*!<  5 */
  FAST_LED_BRIGHTNESS_21_875,           /*!<  6 */
  FAST_LED_BRIGHTNESS_25,               /*!<  7 */
  FAST_LED_BRIGHTNESS_28_125,           /*!<  8 */
  FAST_LED_BRIGHTNESS_31_25,            /*!<  9 */
  FAST_LED_BRIGHTNESS_34_375,           /*!< 10 */
  FAST_LED_BRIGHTNESS_37_5,             /*!< 11 */
  FAST_LED_BRIGHTNESS_40_625,           /*!< 12 */
  FAST_LED_BRIGHTNESS_43_75,            /*!< 13 */
  FAST_LED_BRIGHTNESS_46_875,           /*!< 14 */
  FAST_LED_BRIGHTNESS_50,               /*!< 15 */
  FAST_LED_BRIGHTNESS_53_125,           /*!< 16 */
  FAST_LED_BRIGHTNESS_56_25,            /*!< 17 */
  FAST_LED_BRIGHTNESS_59_375,           /*!< 18 */
  FAST_LED_BRIGHTNESS_62_5,             /*!< 19 */
  FAST_LED_BRIGHTNESS_65_625,           /*!< 20 */
  FAST_LED_BRIGHTNESS_68_75,            /*!< 21 */
  FAST_LED_BRIGHTNESS_71_875,           /*!< 22 */
  FAST_LED_BRIGHTNESS_75,               /*!< 23 */
  FAST_LED_BRIGHTNESS_78_125,           /*!< 24 */
  FAST_LED_BRIGHTNESS_81_25,            /*!< 25 */
  FAST_LED_BRIGHTNESS_84_375,           /*!< 26 */
  FAST_LED_BRIGHTNESS_87_5,             /*!< 27 */
  FAST_LED_BRIGHTNESS_90_625,           /*!< 28 */
  FAST_LED_BRIGHTNESS_93_75,            /*!< 29 */
  FAST_LED_BRIGHTNESS_96_875,           /*!< 20 */
  FAST_LED_BRIGHTNESS_100,              /*!< 31 */
} fast_led_brightness_range_control_t;

/*!
 *
 * @enum fast_led_intensity_control_e
 *
 */
typedef enum
{
  FAST_LED_SCALE_DISABLED  = 0, /*!< 0 */
  FAST_LED_SCALE_3_2_mA,        /*!< 1 */
  FAST_LED_SCALE_6_4_mA,        /*!< 2 */
  FAST_LED_SCALE_12_8_mA,       /*!< 3 */
} fast_led_intensity_control_t;

/*!
 *
 * @enum fast_led_duty_cycle_e
 *
 */
typedef enum
{
  FAST_LED_DUTY_CYCLE_6_25  = 0,        /*!<  0 */
  FAST_LED_DUTY_CYCLE_12_5,             /*!<  1 */
  FAST_LED_DUTY_CYCLE_18_75,            /*!<  2 */
  FAST_LED_DUTY_CYCLE_25_0,             /*!<  3 */
  FAST_LED_DUTY_CYCLE_31_25,            /*!<  4 */
  FAST_LED_DUTY_CYCLE_37_5,             /*!<  5 */
  FAST_LED_DUTY_CYCLE_43_75,            /*!<  6 */
  FAST_LED_DUTY_CYCLE_50_0,             /*!<  7 */
  FAST_LED_DUTY_CYCLE_56_25,            /*!<  8 */
  FAST_LED_DUTY_CYCLE_62_5,             /*!<  9 */
  FAST_LED_DUTY_CYCLE_68_75,            /*!< 10 */
  FAST_LED_DUTY_CYCLE_75_0,             /*!< 11 */
  FAST_LED_DUTY_CYCLE_81_25,            /*!< 12 */
  FAST_LED_DUTY_CYCLE_87_5,             /*!< 13 */
  FAST_LED_DUTY_CYCLE_93_75,            /*!< 14 */
  FAST_LED_DUTY_CYCLE_100,              /*!< 15 */
} fast_led_duty_cycle_t;

/*!
 *
 * @enum fast_led_period_e
 *
 */
typedef enum
{
  FAST_LED_PERIOD_0_5_S = 0,            /*!<  0 */
  FAST_LED_PERIOD_1_0_S,                /*!<  1 */
  FAST_LED_PERIOD_1_5_S,                /*!<  2 */
  FAST_LED_PERIOD_2_0_S,                /*!<  3 */
  FAST_LED_PERIOD_2_5_S,                /*!<  4 */
  FAST_LED_PERIOD_3_0_S,                /*!<  5 */
  FAST_LED_PERIOD_3_5_S,                /*!<  6 */
  FAST_LED_PERIOD_4_0_S,                /*!<  7 */
  FAST_LED_PERIOD_4_5_S,                /*!<  8 */
  FAST_LED_PERIOD_5_0_S,                /*!<  9 */
  FAST_LED_PERIOD_5_5_S,                /*!< 10 */
  FAST_LED_PERIOD_6_0_S,                /*!< 11 */
  FAST_LED_PERIOD_6_5_S,                /*!< 12 */
  FAST_LED_PERIOD_7_0_S,                /*!< 13 */
  FAST_LED_PERIOD_7_5_S,                /*!< 14 */
  FAST_LED_PERIOD_8_0_S,                /*!< 15 */
} fast_led_period_t;

/*!  @enum fast_pmic_boost_voltage_out_e */
enum fast_pmic_boost_voltage_out_e
{
  FAST_PMIC_BOOST_VOUT_2_5V = 0,        /*!<  0 */
  FAST_PMIC_BOOST_VOUT_2_8V,            /*!<  1 */
  FAST_PMIC_BOOST_VOUT_2_9V,            /*!<  2 */
  FAST_PMIC_BOOST_VOUT_3_0V,            /*!<  3 */
  FAST_PMIC_BOOST_VOUT_3_3V,            /*!<  4 */
  FAST_PMIC_BOOST_VOUT_3_4V,            /*!<  5 */
  FAST_PMIC_BOOST_VOUT_3_5V,            /*!<  6 */
  FAST_PMIC_BOOST_VOUT_3_6V,            /*!<  7 */
  FAST_PMIC_BOOST_VOUT_3_7V,            /*!<  8 */
  FAST_PMIC_BOOST_VOUT_3_8V,            /*!<  9 */
  FAST_PMIC_BOOST_VOUT_3_9V,            /*!< 10 */
  FAST_PMIC_BOOST_VOUT_4_0V,            /*!< 11 */
  FAST_PMIC_BOOST_VOUT_4_2V,            /*!< 12 */
  FAST_PMIC_BOOST_VOUT_4_3V,            /*!< 13 */
  FAST_PMIC_BOOST_VOUT_4_4V,            /*!< 14 */
  FAST_PMIC_BOOST_VOUT_4_5V,            /*!< 15 */
};

/*! @brief . */
typedef enum fast_pmic_boost_voltage_out_e fast_pmic_boost_voltage_out_t;

/*!  @brief .  */
typedef enum
{
  FAST_PMIC_BYPASS_DISABLED  = 0,       /*!< 0 */
  FAST_PMIC_BYPASS_FORCE_BYPASS,        /*!< 1 */
  FAST_PMIC_BYPASS_AUTO_BYPASS,         /*!< 2 */
} fast_pmic_bypass_mode_t;

/*!  @enum fast_pmic_boost_current_limit_t */
typedef enum
{
  FAST_PMIC_CURRENT_LIMIT_200mA  = 0,   /*!< 0 */
  FAST_PMIC_CURRENT_LIMIT_300mA,        /*!< 2 */
  FAST_PMIC_CURRENT_LIMIT_400mA,        /*!< 2 */
  FAST_PMIC_CURRENT_LIMIT_500mA,        /*!< 3 */
} fast_pmic_boost_current_limit_t;

/*!  @enum fast_pmic_vrail_id_e */
typedef enum
{
  FAST_PMIC_VRAIL1  = 1,                /*!< 1 */
  FAST_PMIC_VRAIL2,                     /*!< 2 */
  FAST_PMIC_VRAIL3,                     /*!< 3 */
} fast_pmic_ldo_id_t;

/*!  @union fast_ldo_mask_u;
 *
 */
typedef union __attribute__((packed))
{
  /*!
   * @brief .
   */
  struct __attribute__((packed))
  {
    uint8_t    fast_ldo1             : 1; /*!< @brief . */
    uint8_t    fast_ldo2             : 1; /*!< @brief . */
    uint8_t    fast_ldo3             : 1; /*!< @brief . */
    uint8_t    reserved              : 5; /*!< @brief . */
  }
  mbits;                                /*!< @brief . */
  uint8_t data_uint8_t;                   /*!< @brief . */
}
fast_ldo_mask_u;

/*!
 *
 * @enum fast_pmic_voltage_out_e
 *
 */
enum fast_pmic_voltage_out_e
{
  FAST_PMIC_VOLTAGE_OUT_0_5V  = 0,      /*!<  0 */
  FAST_PMIC_VOLTAGE_OUT_0_6V,           /*!<  1 */
  FAST_PMIC_VOLTAGE_OUT_0_7V,           /*!<  2 */
  FAST_PMIC_VOLTAGE_OUT_0_8V,           /*!<  3 */
  FAST_PMIC_VOLTAGE_OUT_0_9V,           /*!<  4 */
  FAST_PMIC_VOLTAGE_OUT_1_0V,           /*!<  5 */
  FAST_PMIC_VOLTAGE_OUT_1_1V,           /*!<  6 */
  FAST_PMIC_VOLTAGE_OUT_1_2V,           /*!<  7 */
  FAST_PMIC_VOLTAGE_OUT_1_3V,           /*!<  8 */
  FAST_PMIC_VOLTAGE_OUT_1_4V,           /*!<  9 */
  FAST_PMIC_VOLTAGE_OUT_1_5V,           /*!< 10 */
  FAST_PMIC_VOLTAGE_OUT_1_6V,           /*!< 11 */
  FAST_PMIC_VOLTAGE_OUT_1_7V,           /*!< 12 */
  FAST_PMIC_VOLTAGE_OUT_1_8V,           /*!< 13 */
  FAST_PMIC_VOLTAGE_OUT_1_9V,           /*!< 14 */
  FAST_PMIC_VOLTAGE_OUT_2_0V,           /*!< 15 */
  FAST_PMIC_VOLTAGE_OUT_2_1V,           /*!< 16 */
  FAST_PMIC_VOLTAGE_OUT_2_2V,           /*!< 17 */
  FAST_PMIC_VOLTAGE_OUT_2_3V,           /*!< 18 */
  FAST_PMIC_VOLTAGE_OUT_2_4V,           /*!< 19 */
  FAST_PMIC_VOLTAGE_OUT_2_5V,           /*!< 20 */
  FAST_PMIC_VOLTAGE_OUT_2_6V,           /*!< 21 */
  FAST_PMIC_VOLTAGE_OUT_2_7V,           /*!< 22 */
  FAST_PMIC_VOLTAGE_OUT_2_8V,           /*!< 23 */
  FAST_PMIC_VOLTAGE_OUT_2_9V,           /*!< 24 */
  FAST_PMIC_VOLTAGE_OUT_3_0V,           /*!< 25 */
  FAST_PMIC_VOLTAGE_OUT_3_1V,           /*!< 26 */
  FAST_PMIC_VOLTAGE_OUT_3_2V,           /*!< 27 */
  FAST_PMIC_VOLTAGE_OUT_3_3V,           /*!< 28 */
  FAST_PMIC_VOLTAGE_OUT_3_4V,           /*!< 29 */
  FAST_PMIC_VOLTAGE_OUT_3_5V,           /*!< 30 */
  FAST_PMIC_VOLTAGE_OUT_3_6V,           /*!< 31 */
};

/*! @brief . */
typedef enum fast_pmic_voltage_out_e fast_pmic_voltage_out_t;

/*!
 *
 * @brief .
 */
enum fast_pmic_thermal_alarm_temp_e
{
  FAST_PMIC_THERMAL_ALARM_TEMP_45C  = 0,        /*!< 0 */
  FAST_PMIC_THERMAL_ALARM_TEMP_65C,             /*!< 2 */
  FAST_PMIC_THERMAL_ALARM_TEMP_85C,             /*!< 3 */
  FAST_PMIC_THERMAL_ALARM_TEMP_105C,            /*!< 4 */
  FAST_PMIC_THERMAL_ALARM_TEMP_125C,            /*!< 5 */
  FAST_PMIC_THERMAL_ALARM_TEMP_145C,            /*!< 6 */
  FAST_PMIC_THERMAL_ALARM_TEMP_165C,            /*!< 7 */
};


/*!
 *
 * @brief .
 *
 */
typedef enum
{
  FAST_PMIC_THERMAL_SHUTDOWN_TEMP_110C  = 0,    /*!< 0 */
  FAST_PMIC_THERMAL_SHUTDOWN_TEMP_135C,         /*!< 1 */
  FAST_PMIC_THERMAL_SHUTDOWN_TEMP_150C,         /*!< 2 */
  FAST_PMIC_THERMAL_SHUTDOWN_TEMP_165C,         /*!< 3 */
} fast_pmic_thermal_shutdown_temp_t;

/*!  @union fast_fault_status_mask_u;
 *
 */
typedef union
{
  /*!
   *
   * @brief .
   *
   */
  struct __attribute__((packed))
  {
    uint16_t    thermal_alarm_trig      : 1; /*!< @brief . */
    uint16_t    boost_uvlo_trig         : 1; /*!< @brief . */
    uint16_t    boost_ilim_trig         : 1; /*!< @brief . */
    uint16_t    vrail3_ovc_trig         : 1; /*!< @brief . */
    uint16_t    vrail2_ovc_trig         : 1; /*!< @brief . */
    uint16_t    vrail1_ovc_trig         : 1; /*!< @brief . */
    uint16_t    hvldo_ovc_trig          : 1; /*!< @brief . */
    uint16_t    reserved                : 9; /*!< @brief . */
  } mbits; /*!< @brief . */
  uint16_t data_uint16_t; /*!< @brief . */
} fast_fault_status_mask_u;

/*!
 * @brief FAST SPI bit mode configuration
 */
typedef enum
{
  FAST_SPI_8_BIT_MODE  = 0,     /*!< 0 */
  FAST_SPI_16_BIT_MODE,         /*!< 1 */
  FAST_SPI_32_BIT_MODE,         /*!< 2 */
} fast_spi_bit_mode_t;

/*!
 * @brief FAST SPI bit order configuration
 */
enum fast_spi_bit_order_e
{
  FAST_SPI_MSB_FIRST  = 0,      /*!< 0 */
  FAST_SPI_LSB_FIRST,           /*!< 1 */
};

/*!
 * @brief .
 */
typedef enum fast_spi_bit_order_e fast_spi_bit_order_t;

/*!
 * @brief FAST SPI phase configuration
 */
enum fast_spi_cpha_e
{
  FAST_SPI_CPHA_0  = 0, /*!< 0 */
  FAST_SPI_CPHA_1,      /*!< 1 */
};
/*!
 * @brief .
 */
typedef enum fast_spi_cpha_e fast_spi_cpha_t;


/*!  @enum fast_spi_cpol_e
 *
 * @brief FAST SPI polarity configuration
 *
 */
enum fast_spi_cpol_e
{
  FAST_SPI_CPOL_0  = 0, /*!< 0 */
  FAST_SPI_CPOL_1,      /*!< 1 */
};
/*!
 * @brief .
 */
typedef enum fast_spi_cpol_e fast_spi_cpol_t;

/*!  @brief . */
typedef enum fast_power_state_e fast_power_state_t;
/*!  @brief . */
typedef  enum fast_debug_level_e fast_debug_level_t;
/*!  @brief . */
typedef enum fast_gpio_functions_e fast_gpio_functions_t;
/*!  @brief . */
typedef enum fast_gpio_port_e fast_gpio_port_t;
/*!  @brief . */
typedef enum fast_gpio_pin_e fast_gpio_pin_t;
/*!  @brief .  */
typedef enum fast_pmic_thermal_alarm_temp_e fast_pmic_thermal_alarm_temp_t;

/*!
 * @brief .
 */
typedef struct fast_system_information_s fast_system_information_t;

/*!  @struct fast_system_information_s;
 *
 */
struct __attribute__((packed)) fast_system_information_s
{
  /*<! LSB */
  uint32_t    config_file_id                    : 8; /*!< @brief . */
  uint32_t    config_file_version               : 4; /*!< @brief . */
  uint16_t    number_of_chiplets_on_fast        : 8; /*!< @brief . */
  uint16_t    supported_zeus                    : 4; /*!< @brief . */
  uint32_t    system_id;                         /*!< @brief . */
  uint32_t    system_version;                    /*!< @brief . */
};

/*!
 * @brief .
 */
typedef struct fast_system_chips_information_s fast_system_chips_information_t;

/*!  @struct fast_system_chips_information_s
 *   @brief .
 */
struct __attribute__((packed)) fast_system_chips_information_s
{
  /*<! LSB */
  uint16_t    chip_global_id;                                   /*!< @brief . */
  uint8_t     chip_description[CHIP_DESCRIPTOR_SIZE * 2];       /*!< @brief . */
};

/****************************************************************************
 * Function declarations
 ****************************************************************************/

/*!
 *
 * @brief .
 */
fast_status_e fast_api_init(uint8_t mcu_on_fast_local);

/*!
 * @brief get FAST API version information
 */
fast_status_e fast_api_version(uint32_t *major, uint32_t *minor, const char *version);

/*!
 * @brief Get the building information
 */
fast_status_e fast_api_build_info(const char *description);

/*!
 * @brief Sets the operation timeout. Default is 50ms. Range can be from 0-100ms
 */
fast_status_e fast_set_timeout(uint16_t time_ms);

/*! @brief Returns the ID of the system */
fast_status_e fast_read_id(uint8_t *data_ptr, uint8_t number_of_bytes);

/** @name Power Management functions
 */
///@{
/*! @brief Transition to specified smart fabric power state */
fast_status_e fast_power_state_enter(fast_power_state_t power_state);

/*! @brief Return the current power state of the smart fabric */
fast_status_e fast_power_state_get(fast_power_state_t *power_state);
///@}


/** @name LED control functions
 */
///@{
/*! @brief Configure the duty cycle, brightness, period , internsity and invert settings for the LEDs*/
fast_status_e fast_led_configure(fast_led_id_t led_id, fast_led_duty_cycle_t duty_cycle, fast_led_period_t led_period,
                                 fast_led_intensity_control_t intensity, fast_led_brightness_range_control_t brightness, bool invert_pwm);
/*! @brief Enable the LEDs. Multiple LEDs can be enabled with the mask */
fast_status_e fast_led_enable(fast_led_mask_u led_mask);
/*! @brief Disable the LEDs. Multiple LEDs can be enabled with the mask */
fast_status_e fast_led_disable(fast_led_mask_u led_mask);
///@}

/*! @brief  Read the 4K of OTP reserved for customers */
fast_status_e fast_read_customer_otp(uint32_t start_addr, uint16_t *data_ptr, uint32_t number_of_words);

/** @name PMIC/Analog block management functions
 */
///@{
/*! @brief PMIC/Analog APIs */
fast_status_e fast_pmic_boost_configure(fast_pmic_boost_voltage_out_t boost_voltage, fast_pmic_bypass_mode_t bypass_mode,
                                        fast_pmic_boost_current_limit_t current_limit);
/*! @brief . */
fast_status_e fast_pmic_sysldo_configure(fast_pmic_voltage_out_t voltage_out, fast_pmic_bypass_mode_t bypass_mode,
                                         bool current_limit_enable);
/*! @brief . */
fast_status_e fast_pmic_ldo_configure(fast_pmic_ldo_id_t ldo_number, bool bypass_enable,
                                      bool current_limit_enable);
/*! @brief . */
fast_status_e fast_pmic_ldo_enable(fast_ldo_mask_u ldo_mask);

/*! @brief . */
fast_status_e fast_pmic_ldo_disable(fast_ldo_mask_u ldo_mask);

/*! @brief . Set the voltage output of LDOx*/
fast_status_e fast_pmic_ldo_vout(fast_pmic_ldo_id_t ldo_number, fast_pmic_voltage_out_t voltage_out);
/*! @brief . Get the voltage output of LDOx*/
fast_status_e fast_pmic_ldo_vout_get(fast_pmic_ldo_id_t ldo_number, fast_pmic_voltage_out_t *voltage_out);
/*! @brief . */
fast_status_e fast_pmic_thermal_monitor_configure(fast_pmic_thermal_alarm_temp_t alarm_temperature,
                                                  fast_pmic_thermal_shutdown_temp_t shutdown_temperature);
/*! @brief . */
fast_status_e fast_pmic_thermal_monitor_enable(void);
/*! @brief . */
fast_status_e fast_pmic_thermal_monitor_disable(void);
///@}

/** @name Fault interrupt and handling functions
 */
///@{
/*! @brief FAST faults and status */
fast_status_e fast_fault_clear_interrupt(fast_fault_status_mask_u *data_ptr);
/*! @brief . */
fast_status_e fast_fault_get_status(fast_fault_status_mask_u *data_ptr);
/*! @brief . */
fast_status_e fast_fault_enable_interrupt(fast_fault_status_mask_u fault_status_mask);
///@}

/** @name GPIO expander functions
 */
///@{
/*! @brief FAST GPIO expander API */
fast_status_e fast_gpio_exp_configure_pin(fast_gpio_port_t gpio_port, fast_gpio_pin_t gpio_pin, fast_gpio_functions_t gpio_function,
                                          fast_gpio_pin_level_t gpio_pin_level);
/*! @brief . */
fast_status_e fast_gpio_exp_set_pin(fast_gpio_port_t gpio_port, fast_gpio_pin_t gpio_pin, fast_gpio_pin_level_t gpio_level);
/*! @brief . */
fast_status_e fast_gpio_exp_get_pin(fast_gpio_port_t gpio_port, fast_gpio_pin_t gpio_pin, fast_gpio_pin_level_t *gpio_level);
/*! @brief . */
fast_status_e fast_gpio_exp_clear_irq(fast_gpio_interrupt_status_u *fast_int_mask);
/*! @brief . */
fast_status_e fast_gpio_exp_disable_pin(fast_gpio_port_t gpio_port, fast_gpio_pin_t gpio_pin);
///@}

/** @name System configuration functions
 */
///@{
/*! @brief FAST configuration API */
fast_status_e fast_system_get_information(fast_system_information_t *data_ptr);
/*! @brief . */
fast_status_e fast_system_get_chips_information(fast_system_chips_information_t *system_chips_data);
/*! @brief . */
fast_status_e fast_system_connect(uint8_t config_file_id);
/*! @brief . */
fast_status_e fast_system_disconnect(uint8_t config_file_id);
/*! @brief . */
fast_status_e fast_chip_connect(uint8_t config_file_id, uint16_t chip_id);
/*! @brief . */
fast_status_e fast_chip_disconnect(uint8_t config_file_id, uint16_t chip_id);
/*! @brief . */
fast_status_e fast_chip_vrail_connect(uint8_t config_file_id, uint16_t chip_id, int16_t vrail_id);
///@}

/*!
 * @brief .
 *
 */
fast_status_e fast_set_debug_level(fast_debug_level_t fast_new_debug_level);

/*! @brief FAST SPI configuration */
fast_status_e fast_spi_configure(fast_spi_bit_order_t bit_order, fast_spi_bit_mode_t bit_mode, fast_spi_cpol_t cpol,
                                 fast_spi_cpha_t cpha);
/*! @brief FAST API close */
fast_status_e fast_api_close(uint8_t config_file_id);

//MinYang++
void fast_test(void);
//MinYang--

#undef EXTERN
#if defined(__cplusplus)
}
#endif


#endif /*End of FAST_API_H*/

