#include <leo.h>

void app_start()
{
	unsigned char *portf_base = (unsigned char *)0x40025000;
	unsigned int *portf_gpiodata = (unsigned int *)portf_base;
	unsigned int *portf_gpiodir = (unsigned int *)(portf_base + 0x400);
	unsigned int *rcgcgpio = (unsigned int *)0x400fe608;

	*rcgcgpio |= 32;
	*portf_gpiodir |= 2;
	*portf_gpiodata |= 2;

	for (;;);
}
