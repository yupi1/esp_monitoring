#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "driver/uart.h"

void app_main(void)
{
    const uart_port_t uart_num = UART_NUM_2;
    uart_config_t u_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
    };

    uart_param_config(uart_num, &u_config);
    uart_set_pin(uart_num, NULL, GPIO_NUM_4, -1, -1);

    while(1) {
        printf("Hello1\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
