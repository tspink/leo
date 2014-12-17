#include <leo.h>

extern "C" {

	extern unsigned long _start_text, _end_text;
	extern unsigned long _start_data, _end_data;
	extern unsigned long _start_bss, _end_bss;

	extern void leo_start(void);

	void reset_handler() __attribute__ ((noreturn,cold));

	void reset_handler()
	{
		unsigned long *src, *dest;

		// Copy the data section into RAM
		src = &_end_text;
		dest = &_start_data;

		while (dest < &_end_bss) {
			*dest++ = *src++;
		}

		// Zero out the BSS section in RAM
		dest = &_start_bss;
		while (dest < &_end_bss) {
			*dest++ = 0;
		}

		// Start LEO
		leo_start();

		// Loop forever
		while(1);
	}
}
