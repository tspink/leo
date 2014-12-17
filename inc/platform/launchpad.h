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
			Launchpad();
			
			bool initialise();
			void shutdown();
			
			leo::hw::uart::UART& debug_uart();
			
		private:
			leo::hw::uart::UART *_debug_uart;
		};
	}
}

#endif
