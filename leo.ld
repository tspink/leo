MEMORY
{
	FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 0x40000
	RAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 0x8000
	STACK (rwx) : ORIGIN = 0x20007FFF, LENGTH = 0x0
}

SECTIONS
{
	. = 0x0;
	
	.text :
	{
		_start_text = .;
		KEEP(*(.init.vector_table))
		*(.text)
		*(.text.*)
		*(.rodata)
		*(.rodata.*)
		_start_init_array = .;
		*(.init_array)
		_end_init_array = .;
		_end_text = .;
	}>FLASH
	
	.data :
	{
		_start_data = .;
		*(.data)
		*(.data.*)
		_end_data = .;
	}>RAM AT >FLASH
	
	.bss :
	{
		_start_bss = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		_end_bss = .;
	}>RAM
	
	.stack :
	{
		_stack_top = .;
	}>STACK
}
