/* 
 * File:   mm.h
 * Author: spink
 *
 * Created on 18 December 2014, 08:42
 */

#ifndef MM_H
#define	MM_H

#include <stddef.h>

namespace leo
{
	namespace util
	{
		extern void *malloc(size_t size);
		extern void free(void *p);
	}
}

#endif	/* MM_H */

