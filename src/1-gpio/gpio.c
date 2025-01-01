#ifndef _pin_config_h_
#define _pin_config_h_

#include "fpioa.h"
#include "gpio.h"
#include "unistd.h"


//硬件IO，，，，，
#define pinLED0 (0)
#define pinLED1 (17)
//软件IO
#define LEDGPIO0 (0)
#define LEDGPIO1 (1)
//GPIO口绑定到硬件IO
#define FUNCLED0 (FUNC_GPIO0 + LEDGPIO0)
#define FUNCLED1 (FUNC_GPIO0 + LEDGPIO1)
#endif
void hardware_init(void)
{
    fpioa_set_function(pinLED0,FUNCLED0);
    fpioa_set_function(pinLED1,FUNCLED1);
}


int main(void)
{
    //引脚初始化
    hardware_init();
    //GPIO时钟
    gpio_init();
    //设置GPIO模式为输出
    gpio_set_drive_mode(LEDGPIO0,GPIO_DM_OUTPUT);
    gpio_set_drive_mode(LEDGPIO1,GPIO_DM_OUTPUT);
    //关闭LED0,LED1
    gpio_pin_value_t value = GPIO_PV_HIGH;
    gpio_set_pin(LEDGPIO0,value);
    gpio_set_pin(LEDGPIO1,value);

    while (1)
    {
        sleep(2);
        gpio_set_pin(LEDGPIO0,value);
        gpio_set_pin(LEDGPIO1,value = !value);
    }
    
}
