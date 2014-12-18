#include <util/mm.h>

#define HEAP_SIZE	0x4000

namespace leo
{
	namespace util
	{
		static unsigned char heap[HEAP_SIZE] __attribute__((aligned(16)));
		static unsigned char *last_ptr = &heap[0];
		
		void *malloc(size_t size)
		{
			unsigned char *p = last_ptr;
			
			if (p > &heap[HEAP_SIZE - size])
				return NULL;
			
			last_ptr += size;
			last_ptr += 16 - (size % 16);
			
			return (void *)p;
		}
		
		void free(void *p)
		{
			if (!p) {
				return;
			}
		}
	}
}
