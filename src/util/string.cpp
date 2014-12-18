#include <util/string.h>

namespace leo {
	namespace util {
		/**
		 * Fills a region of memory with the given character
		 * @param dest
		 * @param c
		 * @param n
		 * @return 
		 */
		void *memset(void *dest, int c, size_t n)
		{
			for (size_t i = 0; i < n; i++) {
				((unsigned char *) dest)[i] = (char) c;
			}

			return dest;
		}

		/**
		 * Copies one block of memory onto another - the memory areas must not overlap.
		 * @param dest
		 * @param src
		 * @param n
		 * @return 
		 */
		void *memcpy(void *dest, const void *src, size_t n)
		{
			for (size_t i = 0; i < n; i++) {
				((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			}

			return dest;
		}

		/**
		 * Moves one block of memory onto another - the memory areas may overlap.
		 * @param dest
		 * @param src
		 * @param n
		 * @return 
		 */
		void *memmove(void *dest, const char *src, size_t n)
		{
			return NULL;
		}

		/**
		 * Returns the length of a string.
		 */
		int strlen(const char *str)
		{
			int c = 0;
			while (*str++) {
				c++;
			}

			return c;
		}
	}
}
