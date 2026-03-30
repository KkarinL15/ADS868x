/**
 * @file    rtos_tasks.c
 * @author  Deadline039
 * @brief   RTOS tasks.
 * @version 1.0
 * @date    2024-01-31
 */

#include "includes.h"


static TaskHandle_t start_task_handle;
void start_task(void *pvParameters);

static TaskHandle_t message_polling_task_handle;
void message_polling_task(void *pvParameters);

/*****************************************************************************/

/**
 * @brief FreeRTOS start up.
 *
 */
void freertos_start(void) {
    xTaskCreate(start_task, "start_task", 128, NULL, 2, &start_task_handle);
    vTaskStartScheduler();
}

/**
 * @brief Start up task.
 *
 * @param pvParameters Start parameters.
 */
void start_task(void *pvParameters) {
    UNUSED(pvParameters);

    // LED0_ON();
    // LED1_ON();
    // LED2_ON();
    LED3_ON();
    BEEP_ON();
    delay_ms(40);
    BEEP_OFF();
    remote_send_init(&uart4_handle); /* 创建 */
    message_register_polling_uart(MSG_TO_MASTER, &uart4_handle, 100, 512);
    message_register_recv_callback(MSG_TO_MASTER, remote_report_msg_callback);
    taskENTER_CRITICAL();
    xTaskCreate(message_polling_task, "message_polling_task", 512, NULL, 2,
                &message_polling_task_handle);

    vTaskDelete(start_task_handle);
    taskEXIT_CRITICAL();
}

/**
 * @brief message_polling_task 指定串口轮询数据函数
 *
 * @param pvParameters
 */
void message_polling_task(void *pvParameters) {
    UNUSED(pvParameters);

    while (1) {

        message_polling_data();
        vTaskDelay(5);
    }
}


#ifdef configASSERT

/**
 * @brief FreeRTOS assert failed function. 
 * 
 * @param pcFile File name
 * @param ulLine File line
 */
void vAssertCalled(const char *pcFile, unsigned int ulLine) {
    fprintf(stderr, "FreeRTOS assert failed. File: %s, line: %u. \n", pcFile,
            ulLine);
}
#endif /* configASSERT */

#if configCHECK_FOR_STACK_OVERFLOW

/**
 * @brief The application stack overflow hook is called when a stack overflow is detected for a task.
 *
 * @param xTask the task that just exceeded its stack boundaries.
 * @param pcTaskName A character string containing the name of the offending task.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    UNUSED(xTask);
    fprintf(stderr, "Stack overflow! Taskname: %s. \n", pcTaskName);
}

#endif /* configCHECK_FOR_STACK_OVERFLOW */

#if configUSE_MALLOC_FAILED_HOOK

/**
 * @brief This hook function is called when allocation failed.
 * 
 */
void vApplicationMallocFailedHook(void) {
    fprintf(stderr, "FreeRTOS malloc failed! \n");
}

#endif /* configUSE_MALLOC_FAILED_HOOK */