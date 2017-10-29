#include "baremetal.h"
#include "aarch64.h"

#define GPFSEL1 0x3F200004
#define GPSET0  0x3F20001C

int main(void)
{
    volatile unsigned int tmp;

    tmp = *((const volatile unsigned int *)GPFSEL1);
    tmp &= ~(0x7 << (3 * 6));
    tmp |= (0x01 << (3 * 6));
    *(volatile unsigned int *)GPFSEL1 = tmp;

    *(volatile unsigned int *)GPSET0 = 0x01 << 16;

    for ( ; ; );

    return 0;
}
