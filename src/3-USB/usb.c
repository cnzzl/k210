#include "unistd.h"
#include "fpioa.h"
#include <string.h> // 包含strlen函数的头文件

#include "uart.h"
#include "uarths.h"

//*****************硬件IO**********************
#define pin_usb_rx (4)
#define pin_usb_tx (5)
//*****************软件IO*******************
#define uart_usb_num UART_DEVICE_3

//GPIO口绑定到硬件IO
#define FUNC_USB_RX (FUNC_UART1_RX + uart_usb_num*2)
#define FUNC_USB_TX (FUNC_UART1_TX + uart_usb_num*2)
//
void hardware_init(void)
{
    //fpioa映射
    fpioa_set_function(pin_usb_rx,FUNC_USB_RX);
    fpioa_set_function(pin_usb_tx,FUNC_USB_TX);
}


int main(void)
{
   uart_init(uart_usb_num);
   uart_configure(uart_usb_num,115200,UART_BITWIDTH_8BIT,UART_STOP_1,UART_PARITY_NONE);

   char *hello = {"good\n"};
   uart_send_data(uart_usb_num,hello,strlen(hello));
    char recv = 0;
   while (1)
   {
        while (uart_receive_data(uart_usb_num,&recv,1))
        {
            uart_send_data(uart_usb_num,&recv,1);
        }
   }
   
    
}
