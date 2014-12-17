#include <leo.h>

void app_start()
{
	unsigned char *portf_base = (unsigned char *)0x4005d000;
	unsigned int *portf_gpiodata = (unsigned int *)portf_base;
	unsigned int *portf_gpiodir = (unsigned int *)(portf_base + 0x400);
	unsigned int *portf_gpioden = (unsigned int *)(portf_base + 0x51c);
	unsigned int *gpiohbctl = (unsigned int *)0x400fe06c;
	unsigned int *rcgcgpio = (unsigned int *)0x400fe608;

	*gpiohbctl |= 1 << 5;
	*rcgcgpio |= 1 << 5;
	
	asm volatile("nop\n");
	asm volatile("nop\n");
	asm volatile("nop\n");
	asm volatile("nop\n");
	
	*portf_gpioden |= 2;
	*portf_gpiodir |= 2;
	*portf_gpiodata |= 2;

	for (;;);
}
