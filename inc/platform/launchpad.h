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
			
			int freq() const { return 0; }
			
			leo::hw::uart::UART& debug_uart();
			
		private:
			leo::hw::uart::UART *_debug_uart;
		};
	}
}

#endif
