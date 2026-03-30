#ifndef __ADC_H
#define __ADC_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <CSP_Config.h>

#define LEFT_Z_GPIO_PORT       GPIOE
#define LEFT_Z_GPIO_ENABLE()   __HAL_RCC_GPIOE_CLK_ENABLE()
#define LEFT_Z_GPIO_PIN        GPIO_PIN_3

#define RIGHT_Z_GPIO_PORT      GPIOA
#define RIGHT_Z_GPIO_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define RIGHT_Z_GPIO_PIN       GPIO_PIN_15

#define LEFT_T_GPIO_PORT       GPIOB
#define LEFT_T_GPIO_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()
#define LEFT_T_GPIO_PIN        GPIO_PIN_11

#define RIGHT_T_GPIO_PORT      GPIOB
#define RIGHT_T_GPIO_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#define RIGHT_T_GPIO_PIN       GPIO_PIN_10

#define wheR_up_GPIO_PORT      GPIOE
#define wheR_up_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define wheR_up_PIN            GPIO_PIN_9

#define wheR_do_GPIO_PORT      GPIOE
#define wheR_do_GPIO_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define wheR_do_GPIO_PIN       GPIO_PIN_7

#define wheR_key_GPIO_PORT      GPIOE
#define wheR_key_GPIO_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define wheR_key_GPIO_PIN       GPIO_PIN_8

#define wheL_up_GPIO_PORT      GPIOA
#define wheL_up_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define wheL_up_PIN            GPIO_PIN_8

#define wheL_do_GPIO_PORT      GPIOC
#define wheL_do_GPIO_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define wheL_do_GPIO_PIN       GPIO_PIN_8

#define wheL_key_GPIO_PORT      GPIOC
#define wheL_key_GPIO_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define wheL_key_GPIO_PIN       GPIO_PIN_9

void rs_get_value(uint32_t *data, uint8_t dead_zone, uint8_t data_level);
uint32_t rs_get_z(void);
void adc_key_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ADC_H */

