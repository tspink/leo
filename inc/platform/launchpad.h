#ifndef __LAUNCHPAD_H__
#define __LAUNCHPAD_H__

#include <platform.h>

namespace leo
{
	namespace platform
	{
		class Launchpad : public Platform
		{
		public:
			enum GPIOPort
			{
				PA = 0,
				PB = 1,
				PC = 2,
				PD = 3,
				PE = 4,
				PF = 5
			};
			
			Launchpad();
			
			bool initialise();
			void shutdown();
			
			int freq() const { return 20 * MHZ; }
			int ticks() const;
			
			leo::hw::uart::UART *get_uart(int id);
			leo::hw::gpio::GPIO *get_gpio(int id);
			
			static inline GPIOPort gpio_to_port(int id) const {
				return id / 8;
			}
			
			static inline int gpio_to_index(int id) const {
				return id % 8;
			}
			
			static inline int port_index_to_gpio(GPIOPort port, int id) const {
				return (port * 8) + (id % 8);
			}
			
		private:
			leo::hw::uart::UART *_debug_uart;
		};
	}
}

#endif
