/* 
 * File:   irq.h
 * Author: spink
 *
 * Created on 17 December 2014, 18:26
 */

#ifndef IRQ_H
#define	IRQ_H

namespace leo
{
	namespace sys
	{
		typedef void (*isr_fn_t)(void);
		
#define MAX_IRQ				132
#define MAX_TABLE_ENTRIES	15 + MAX_IRQ
		
		struct ExceptionVectorTable
		{
			unsigned int sp_main;
			
			union {
				struct {
					isr_fn_t reset;
					isr_fn_t nmi;
					isr_fn_t hard_fault;
					isr_fn_t mm_fault;
					isr_fn_t bus_fault;
					isr_fn_t usage_fault;
					isr_fn_t rsvd7;
					isr_fn_t rsvd8;
					isr_fn_t rsvd9;
					isr_fn_t rsvd10;
					isr_fn_t svcall;
					isr_fn_t rsvd12;
					isr_fn_t rsvd13;
					isr_fn_t pendsv;
					isr_fn_t systick;
					isr_fn_t irq_lines[MAX_IRQ];
				} fns __attribute__((packed));
				
				struct {
					isr_fn_t entries[MAX_TABLE_ENTRIES];
				} ent __attribute__((packed));
			};
		} __attribute__((packed));
		
		class IRQManager
		{
		public:
			IRQManager();
			void relocate_exception_vectors();
			void attach_irq_handler(int irq, isr_fn_t isr);
		};
	}
}

#endif	/* IRQ_H */

