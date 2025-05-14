//
// Created by JasperXzy on 2025/5/14.
//

#include "stm32f1xx.h"
#include "delay.h"

// 系统时钟为72MHz，SysTick使用AHB/8（9MHz）
#define SYSTICK_CLOCK_HZ  (SystemCoreClock / 8)
#define TICKS_PER_US      (SYSTICK_CLOCK_HZ / 1000000)  // 9
#define TICKS_PER_MS      (SYSTICK_CLOCK_HZ / 1000)     // 9000

void delay_us(uint32_t nus) {
    uint32_t temp;
    uint32_t ticks = TICKS_PER_US * nus;

    // 处理24位溢出
    if (ticks > 0xFFFFFF) {
        return;
    }

    SysTick->LOAD = ticks - 1;      // 设置重载值
    SysTick->VAL = 0x00;            // 清空计数器
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk; // 启用SysTick

    do {
        temp = SysTick->CTRL;
    } while ((temp & SysTick_CTRL_ENABLE_Msk) && !(temp & SysTick_CTRL_COUNTFLAG_Msk));

    SysTick->CTRL = 0x00;           // 关闭SysTick
    SysTick->VAL = 0x00;            // 清空计数器
}

void delay_ms(uint16_t nms) {
    uint32_t temp;
    uint32_t ticks = TICKS_PER_MS * nms;

    // 处理24位溢出
    while (ticks > 0xFFFFFF) {
        delay_ms(1864);             // 分块延时最大允许值（0xFFFFFF / 9000 ≈ 1864）
        nms -= 1864;
        ticks = TICKS_PER_MS * nms;
    }

    SysTick->LOAD = ticks - 1;      // 设置重载值
    SysTick->VAL = 0x00;            // 清空计数器
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk; // 启用SysTick

    do {
        temp = SysTick->CTRL;
    } while ((temp & SysTick_CTRL_ENABLE_Msk) && !(temp & SysTick_CTRL_COUNTFLAG_Msk));

    SysTick->CTRL = 0x00;           // 关闭SysTick
    SysTick->VAL = 0x00;            // 清空计数器
}

void delay_100ns(void) {

}
