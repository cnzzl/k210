#include "fpioa.h"
#include "gpio.h"
#include "unistd.h"
#include "gpiohs.h"
//硬件IO，，，，，
#define pin_rgb_r (6)
#define pin_rgb_g (7)
#define pin_rgb_b (8)
//软件IO
#define rgb_gpi_r (0)
#define rgb_gpi_g (1)
#define rgb_gpi_b (2)
//GPIO口绑定到硬件IO
#define FUNCRGB_R (FUNC_GPIOHS0 + rgb_gpi_r)
#define FUNCRGB_G (FUNC_GPIOHS0 + rgb_gpi_g)
#define FUNCRGB_B (FUNC_GPIOHS0 + rgb_gpi_b)
//
void hardware_init(void)
{
    //fpioa映射
    fpioa_set_function(pin_rgb_r,FUNCRGB_R);
    fpioa_set_function(pin_rgb_g,FUNCRGB_G);
    fpioa_set_function(pin_rgb_b,FUNCRGB_B);
}
//关闭rgb
void rgb_all_off(void)
{
    gpiohs_set_pin(rgb_gpi_r,GPIO_PV_HIGH);
    gpiohs_set_pin(rgb_gpi_g,GPIO_PV_HIGH);
    gpiohs_set_pin(rgb_gpi_b,GPIO_PV_HIGH);

}
void init_rgb(void)
{
    //设置GPIO模式为输出
    gpiohs_set_drive_mode(rgb_gpi_r,GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(rgb_gpi_g,GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(rgb_gpi_b,GPIO_DM_OUTPUT);

    rgb_all_off();
}

int main(void)
{
    //
    int state = 0;
    //引脚初始化
    hardware_init();
    //初始化rgb灯
    init_rgb();
    while (1)
    {
        rgb_all_off();

        gpiohs_set_pin(state,GPIO_PV_LOW);
        sleep(2);
        state++;
        state = state % 3;
    }
    
}
