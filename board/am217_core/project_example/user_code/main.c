/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZLG217 模板工程
 *
 * - 实验现象:
 *   模板例程:LED0以1秒的频率闪烁; demo例程入口:详见demo入口函数文件介绍
 *
 * \internal
 * \par Modification history
 * - 1.00 17-07-07  nwt, first implementation
 * \endinternal
 */

/**
 * \brief 例程入口
 */
#include "ametal.h"
#include "am_board.h"
#include "am_vdebug.h"
#include "am_delay.h"
#include "am_gpio.h"
#include "demo_am217_core_entries.h"
#include "zlg217_pin.h"
#include "am_zlg217_inst_init.h"
#include "am_boot.h"

/** \brief 固件升级引脚 */
#define __ENABLE_PIN          (PIOC_7)
/** \brief 应用代码起始地址  */
#define __APP_START_ADDR      0x0800C400

int am_main (void)
{
    AM_DBG_INFO("Start up successful!\r\n");

    am_uart_handle_t uart;
    uart = am_zlg217_uart1_inst_init();
    am_debug_init(uart, 115200);

#if 1
    am_gpio_pin_cfg(__ENABLE_PIN, AM_GPIO_INPUT | AM_GPIO_PULLUP);

    am_zlg217_std_boot_inst_init();

    if (am_gpio_get(__ENABLE_PIN)) {

        am_boot_source_release();
        am_gpio_pin_cfg(__ENABLE_PIN, AM_GPIO_INPUT | AM_GPIO_FLOAT);
        am_kprintf("bootloadr : go to application...\r\n");

        if(AM_OK != am_boot_go_application(__APP_START_ADDR)){
            while(1);
        }
    }

    am_zlg217_boot_kft_inst_init();
    am_kprintf("bootloader : running......\r\n");
    am_kprintf("bootloader : start command pump\r\n");
    while(1) {
        am_boot_kft_command_pump();
    }
#endif

    /*
     * 以下为所有demo的入口函数，需要运行哪个demo，就取消对应函数调用行的注释
     *
     * 默认运行的是LED闪烁 demo
     *
     * 注意：同一时刻只能运行一个 demo，即只能使某一行处于取消注释状态
     */

//   demo_zlg217_core_std_led_entry();
//    demo_zlg217_core_std_delay_entry();
//    demo_zlg217_core_std_adc_entry();
//    demo_zlg217_core_hw_adc_int_entry();
//    demo_zlg217_core_std_buzzer_entry();
//    demo_zlg217_core_std_crc_entry();
//    demo_zlg217_core_drv_dma_m2m_entry();
//    demo_zlg217_core_drv_flash_entry();
//    demo_zlg217_core_hw_gpio_entry();
//    demo_zlg217_core_hw_gpio_trigger_entry();
//    demo_zlg217_core_std_gpio_entry();
//    demo_zlg217_core_std_gpio_trigger_entry();
//    demo_zlg217_core_hw_i2c_master_poll_entry();
//    demo_zlg217_core_hw_i2c_slave_poll_entry();
//    demo_zlg217_core_std_i2c_lm75_entry();
//    demo_zlg217_core_std_i2c_master_async_entry();
//    demo_zlg217_core_std_i2c_master_sync_entry();
//    demo_zlg217_core_std_key_input_event_entry();
//    demo_zlg217_core_hw_iwdg_entry();
//    demo_zlg217_core_std_iwdg_entry();
//    demo_zlg217_core_std_led_entry();
//    demo_zlg217_core_microport_ds1302_entry();
//    demo_zlg217_core_microport_eeprom_entry();
//    demo_zlg217_core_microport_eeprom_nvram_entry();
//    demo_zlg217_core_microport_flash_entry();
//    demo_zlg217_core_microport_flash_ftl_entry();
//    demo_zlg217_core_microport_flash_mtd_entry();
//    demo_zlg217_core_microport_rs485_entry();
//    demo_zlg217_core_microport_rtc_entry();
//    demo_zlg217_core_microport_rx8025t_entry();
//    demo_zlg217_core_miniport_digitron_entry();
//    demo_zlg217_core_miniport_hc595_digitron_entry();
//    demo_zlg217_core_miniport_hc595_digitron_key_entry();
//    demo_zlg217_core_miniport_hc595_digitron_temp_entry();
//    demo_zlg217_core_miniport_hc595_led_entry();
//    demo_zlg217_core_miniport_key_entry();
//    demo_zlg217_core_miniport_key_digitron_entry();
//    demo_zlg217_core_miniport_led_entry();
//    demo_zlg217_core_miniport_zlg72128_entry();
//    demo_zlg217_core_std_rtc_entry();
//    demo_zlg217_core_hw_spi_master_entry();
//    demo_zlg217_core_std_spi_master_dma_entry();
//    demo_zlg217_core_std_spi_master_int_entry();
//    demo_zlg217_core_hw_tim_cap_entry();
//    demo_zlg217_core_std_tim1_cap_entry();
//    demo_zlg217_core_std_tim2_cap_entry();
//    demo_zlg217_core_std_tim3_cap_entry();
//    demo_zlg217_core_std_tim4_cap_entry();
//    demo_zlg217_core_hw_tim_cmp_toggle_entry();
//    demo_zlg217_core_hw_tim_pwm_entry();
//    demo_zlg217_core_std_tim1_pwm_entry();
//    demo_zlg217_core_std_tim2_pwm_entry();
//    demo_zlg217_core_std_tim3_pwm_entry();
//    demo_zlg217_core_std_tim4_pwm_entry();
//    demo_zlg217_core_hw_tim_timing_entry();
//    demo_zlg217_core_std_tim1_timing_entry();
//    demo_zlg217_core_std_tim2_timing_entry();
//    demo_zlg217_core_std_tim3_timing_entry();
//    demo_zlg217_core_std_tim4_timing_entry();
//    demo_zlg217_core_hw_uart_int_entry();
//    demo_zlg217_core_hw_uart_polling_entry();
//    demo_zlg217_core_hw_uart_rx_dma_entry();
//    demo_zlg217_core_hw_uart_tx_dma_entry();
//    demo_zlg217_core_std_uart_polling_entry();
//    demo_zlg217_core_std_uart_ringbuf_entry();
//    demo_zlg217_core_hw_wwdg_entry();
//    demo_zlg217_core_std_wwdg_entry();
    while (1) {
    }
}

/* end of file */
