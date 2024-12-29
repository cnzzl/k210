
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

int main(void)
{
    
    
    
}