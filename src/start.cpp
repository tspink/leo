#include <leo.h>
#include <platform/launchpad.h>

static void leo_start()
{
	leo::platform::Launchpad platform;
	leo::Leo leo(platform);
	
	leo.start();
}

extern "C" {
	extern unsigned long _start_text, _end_text;
	extern unsigned long _start_data, _end_data;
	extern unsigned long _start_bss, _end_bss;

	typedef void (*init_fn_t)(void);
	extern init_fn_t _start_init_array, _end_init_array;
	
	/**
	 * Executes all the registered static constructors (if any)
     */
	static void execute_static_constructors()
	{
		init_fn_t *init_fns = &_start_init_array;
		if (!init_fns) {
			return;
		}
		
		while (init_fns < &_end_init_array) {
			init_fn_t init_fn = *init_fns++;
			if (init_fn) init_fn();
		}
	}

	/**
	 * This is the initial reset handler.
     */
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

		// Call C++ static constructors
		execute_static_constructors();
		
		// Start LEO
		leo_start();

		// Loop forever
		while(1);
	}
}
