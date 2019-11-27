#include <stdio.h>
#include <stdlib.h>
#include "fast_api.h"
#include "nrf_drv_twi.h"
#include "sdk_config.h"
#include "config.h"
#include "nrf_delay.h"

#define FAST_IDLEN   32
#define ZEUS2_REG_LEN 4  /* 4 bytes for the data*/

const nrf_drv_twi_t m_twi_master = NRF_DRV_TWI_INSTANCE(MASTER_TWI_INST);

extern const unsigned char FastConfigFileImg[];

fast_status_e fast_read_register(uint8_t dev_id, uint32_t reg_addr, uint8_t *data_r, uint16_t len)
{
	  int ret=0;
	  uint8_t data[ZEUS2_REG_LEN];
	
	  /*FAST Slave i2c protocal expect MSB byte first while NRF sends LSB first. So here we swap the byte order*/
		data[0] = (reg_addr & 0xff000000) >> 24;
		data[1] = (reg_addr & 0xff0000) >> 16;
		data[2] = (reg_addr & 0xff00) >> 8;
		data[3] = reg_addr & 0xff; 	
	  ret=nrf_drv_twi_tx(&m_twi_master, dev_id, data, ZEUS2_REG_LEN, false);
		if (ret < 0)
		{
			printf("ERROR: i2c_write failed: %d\n", ret);
			return FAST_REG_WRITE_FAILURE;
		}
	  for (int i = 0; i < ZEUS2_REG_LEN; i++)
		{
			data[i] = 0;
		}
	  ret=nrf_drv_twi_rx(&m_twi_master, dev_id, data, ZEUS2_REG_LEN);
		if (ret < 0)
		{
			printf("ERROR: i2c_read failed: %d\n", ret);
			return FAST_REG_READ_FAILURE;
		}
	  for (int i = 0; i < ZEUS2_REG_LEN; i++)
    {
      data_r[i] = data[ZEUS2_REG_LEN - 1 - i];
    }

    return FAST_OK;
}

fast_status_e fast_write_register(uint8_t dev_id, uint32_t reg_addr, uint8_t *data_w, uint16_t len)
{
	  int ret=0;
		uint8_t data[ZEUS2_REG_LEN * 2];
	
	  /*FAST Slave i2c protocal expect MSB byte first while NRF sends LSB first. So here we swap the byte order*/
		data[0] = (reg_addr & 0xff000000) >> 24;
		data[1] = (reg_addr & 0xff0000) >> 16;
		data[2] = (reg_addr & 0xff00) >> 8;
		data[3] = reg_addr & 0xff; 	
		data[4] = data_w[3];
		data[5] = data_w[2];
		data[6] = data_w[1];
		data[7] = data_w[0];
		
		ret=nrf_drv_twi_tx(&m_twi_master, dev_id, data, ZEUS2_REG_LEN * 2, false);
		if (ret < 0)
		{
			printf("ERROR: i2c_write failed: %d\n", ret);
			return FAST_REG_WRITE_FAILURE;
		}
    return FAST_OK;
		
}

/* Read the configuration file from specific place in memory of the HOST system */
/*! @brief . */
fast_status_e fast_config_file_read(uint32_t offset, uint32_t length, uint16_t *buffer)
{
	  for (uint32_t i = 0 ; i < length ; i++)
    {
			buffer[i] = FastConfigFileImg[offset * 2 + i * 2] | (FastConfigFileImg[offset * 2 + i * 2 + 1] << 8) ;
    }
    return FAST_OK;
}

/* Toggle the ULPM Wake up pin of the fast */
/*! @brief . */
fast_status_e fast_toggle_ulpm_wake(void)
{
	  #ifdef CONFIG_FAST_ULPM_WAKEUP_PIN
		gpio_pin_write(BOARD_ULPM_WAKEUP_PIN, 1);
		nrf_delay_us(4000);  /*Delay 4ms*/
		gpio_pin_write(BOARD_ULPM_WAKEUP_PIN, 0);
		#endif
    return FAST_OK;
}

/* Sleep in uS */
/*! @brief . */
void fast_sleep(uint32_t time_us)
{
	nrf_delay_us(time_us);
}
