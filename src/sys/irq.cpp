#include <sys/irq.h>
#include <platform/m4.h>
#include <stddef.h>

using namespace leo::sys;

// The exception vector table MUST aligned to a 1024 byte boundary.
ExceptionVectorTable exception_vector_table __attribute__((aligned(1024)));

extern "C" {
	extern void reset_handler();
	extern unsigned int _stack_top;

	void isr_default_handler(void)
	{
		// Loop forever
		for (;;);
	}
}

IRQManager::IRQManager()
{
	// Initialise all entries in the vector table to a default handler, which
	// will loop forever.
	for (size_t i = 0; i < sizeof(exception_vector_table.ent.entries) / sizeof(exception_vector_table.ent.entries[0]); i++) {
		exception_vector_table.ent.entries[i] = isr_default_handler;
	}
	
	// Reassert the initial stack pointer and reset handler.
	exception_vector_table.sp_main = (unsigned int)&_stack_top;
	exception_vector_table.fns.reset = reset_handler;
}

void IRQManager::relocate_exception_vectors()
{
	uint32_t new_vtable = 1 << 29;			// VTABLE is stored in SRAM
	new_vtable |= (uint32_t)&exception_vector_table;	// VTABLE offset
	
	VTABLE = new_vtable;
}

void IRQManager::attach_irq_handler(int irq, isr_fn_t isr)
{
	if (irq >= 0 && irq < MAX_IRQ && isr != NULL) {
		exception_vector_table.fns.irq_lines[irq] = isr;
	}
}
