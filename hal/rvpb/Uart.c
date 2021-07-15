#include "/home/com/OS/Embedded_OS_develop/include/stdint.h"
#include "/home/com/OS/Embedded_OS_develop/hal/rvpb/Uart.h"
#include "/home/com/OS/Embedded_OS_develop/hal/HalUart.h"

extern volatile PL011_t* Uart;

void Hal_uart_init(void)
{
    // Enable UART
    Uart->uartcr.bits.UARTEN = 0;
    Uart->uartcr.bits.TXE = 1;
    Uart->uartcr.bits.RXE = 1;
    Uart->uartcr.bits.UARTEN = 1;
}

void Hal_uart_put_char(uint8_t ch)
{
    while(Uart->uartfr.bits.TXFF);
    Uart->uartdr.all = (ch & 0xFF);
}