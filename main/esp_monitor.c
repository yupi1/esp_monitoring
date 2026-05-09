#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include "driver/uart.h"

void app_main(void)
{
    uint8_t data[64];
    const uart_port_t uart_port = UART_NUM_2; // Канал(порт) UART
    const int uart_buffer_size = 128 * 2;
    // QueueHandle_t uart_queue;  // Це FreeRTOS queue для UART events.(4,5 параметри метода install)

    uart_driver_install(uart_port, uart_buffer_size, uart_buffer_size, 0, NULL, 0);

    uart_config_t u_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    uart_param_config(uart_port, &u_config);
    uart_set_pin(uart_port, UART_PIN_NO_CHANGE, GPIO_NUM_4, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    while(1) {
        int len = uart_read_bytes(uart_port, data, sizeof(data), pdMS_TO_TICKS(1000));
        if(len > 0) {
            printf("RX: %.*s\n", len, data);
        }
    }
}
