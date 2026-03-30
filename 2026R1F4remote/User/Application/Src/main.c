/**
 * @file    main.c
 * @author  Deadline039
 * @brief   Main function files.
 * @version 1.0
 * @date    2024-07-29
 */

#include "includes.h"

/**
 * @brief The program entrance.
 *
 * @return Exit code.
 */
int main(void) {
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    bsp_init();
    ST77xx_DrawLine(0, 39, 320, 39, ST77xx_BLUE);
    ST77xx_DrawLine(0, 40, 320, 40, ST77xx_BLUE);
    ST77xx_DrawLine(0, 41, 320, 41, ST77xx_BLUE);
    ST77xx_DrawLine(160, 40, 160, 118, ST77xx_BLUE);
    ST77xx_DrawLine(159, 40, 159, 118, ST77xx_BLUE);
    ST77xx_DrawLine(161, 40, 161, 118, ST77xx_BLUE);
    ST77xx_DrawString(10, 20, "Battery:", ST77xx_BLACK, ST77xx_GREEN, &Font_11x18);
    ST77xx_DrawString(180, 20, "KEY:", ST77xx_MAGENTA, ST77xx_WHITE, &Font_11x18);
    ST77xx_DrawString(10, 60, "L_X:", ST77xx_BLACK, ST77xx_CYAN, &Font_11x18);
    ST77xx_DrawString(170, 60, "R_X:", ST77xx_BLACK, ST77xx_CYAN, &Font_11x18);
    ST77xx_DrawString(10, 100, "L_Y:", ST77xx_BLACK, ST77xx_CYAN, &Font_11x18);
    ST77xx_DrawString(170, 100, "R_Y:", ST77xx_BLACK, ST77xx_CYAN, &Font_11x18);
    freertos_start();

    return 0;
}
