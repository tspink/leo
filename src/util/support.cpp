#include <util/mm.h>

extern "C" void __cxa_pure_virtual()
{
	while(1);
}

void *operator new(size_t size)
{
	return leo::util::malloc(size);
}

void operator delete(void *p)
{
	leo::util::free(p);
}
