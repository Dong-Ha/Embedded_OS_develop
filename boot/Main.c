#include "/home/com/OS/Embedded_OS_develop/include/stdint.h"

#include "/home/com/OS/Embedded_OS_develop/hal/HalUart.h"

static void Hw_init(void);

void main(void)
{
    Hw_init();

    uint32_t i = 100;
    while(i--)
    {
        Hal_uart_put_char('N');
    }
}

static void Hw_init(void)
{
    Hal_uart_init();
}
