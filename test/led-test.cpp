#include <leo.h>

class LedTestApplication : public leo::Application
{
public:
	bool run(leo::Leo& leo)
	{
		unsigned char *portf_base = (unsigned char *)0x4005d000;
		unsigned int *portf_gpiodata = (unsigned int *)portf_base;
		unsigned int *portf_gpiodir = (unsigned int *)(portf_base + 0x400);
		unsigned int *portf_gpioden = (unsigned int *)(portf_base + 0x51c);
		unsigned int *gpiohbctl = (unsigned int *)0x400fe06c;
		unsigned int *rcgcgpio = (unsigned int *)0x400fe608;
		int i;

		*gpiohbctl |= 1 << 5;
		*rcgcgpio |= 1 << 5;

		asm volatile("nop\n");
		asm volatile("nop\n");
		asm volatile("nop\n");
		asm volatile("nop\n");

		*portf_gpioden |= 6;
		*portf_gpiodir |= 6;

		for (;;) {
			portf_gpiodata[6] = 2;
			for (i = 0; i < 1000000; i++);
			portf_gpiodata[6] = 4;
			for (i = 0; i < 1000000; i++);
		}
		
		return true;
	}
};

// Bootstrapping
LedTestApplication app;
leo::Application *main_application = &app;
