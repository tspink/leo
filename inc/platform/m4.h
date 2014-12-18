/* 
 * File:   m4.h
 * Author: spink
 *
 * Created on 17 December 2014, 18:48
 */

#ifndef M4_H
#define	M4_H

#include <stddef.h>

#define REG(_base, _offset) (*((unsigned int *)((unsigned long)_base + (unsigned long)_offset)))
#define PERIPHERALS_BASE 0xe000e000

#define VTABLE REG(PERIPHERALS_BASE, 0xd08)

#endif	/* M4_H */

