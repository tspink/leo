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
			bool initialise();
		};
	}
}

#endif
