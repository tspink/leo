.globl vector_table
vector_table:
	.word 0				/* SP_MAIN */

	.word undefined_handler		/* RESET */
	.word undefined_handler		/* NMI */
	.word undefined_handler		/* HARD FAULT */
	.word undefined_handler		/* MEM MANAGE */
	.word undefined_handler		/* BUS FAULT */
	.word undefined_handler		/* USAGE FAULT */
	.word undefined_handler		/* RSVD */
	.word undefined_handler		/* RSVD */
	.word undefined_handler		/* RSVD */
	.word undefined_handler		/* RSVD */
	.word undefined_handler		/* SVCALL */
	.word undefined_handler		/* DEBUG MONITOR */
	.word undefined_handler		/* RSVD */
	.word undefined_handler		/* PENDSV */
	.word undefined_handler		/* SYSTICK */
	.word undefined_handler		/* EXTINT0 */
	/* ... */

undefined_handler:
	b undefined_handler
