/* 
 * File:   string.h
 * Author: spink
 *
 * Created on 17 December 2014, 17:48
 */

#ifndef STRING_H
#define	STRING_H

#include <stddef.h>

namespace leo
{
	namespace util
	{
		extern void *memset(void *dest, int c, size_t n);
		extern void *memcpy(void *dest, void *src, size_t n);
		extern void *memmove(void *dest, void *src, size_t n);
		
		static inline void *bzero(void *dest, size_t n)
		{
			return memset(dest, 0, n);
		}
		
		extern int strlen(const char *str);
	}
}

#endif	/* STRING_H */
