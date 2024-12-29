#include "unistd.h"
#include "uart.h"
#include "uarths.h"
//硬件IO，，，，，
#define pin_usb_rx (4)
#define pin_usb_tx (5)
//软件IO
#define uart_usb_num UART_DEVICE_3

//GPIO口绑定到硬件IO
#define FUNC_USB_RX (FUNC_UART1_RX + pin_usb_rx)
#define FUNC_USB_TX (FUNC_UART1_TX + pin_usb_tx)

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
