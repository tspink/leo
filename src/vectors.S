.thumb

.section .init.vector_table,"x"
.globl _init_vector_table
_init_vector_table:
	.word _stack_top	/* SP_MAIN */
	.word reset_handler	/* RESET */

	.rept 153
	.word _init_undef_handler
	.endr

.type _init_undef_handler,%function
_init_undef_handler:
	b _init_undef_handler
