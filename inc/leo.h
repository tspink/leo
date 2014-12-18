#ifndef __LEO_H__
#define __LEO_H__

#include <sys/irq.h>

namespace leo
{
	class Platform;
	
	class Leo
	{
	public:
		Leo(Platform& platform);
		bool start();
		
		inline Platform& platform() const { return _platform; }
		
		void delay(int ms);
		
	private:
		sys::IRQManager irq;
		Platform& _platform;
		
		void relocate_exception_vectors();
	};
	
	class Application
	{
	public:
		virtual bool run(Leo& leo) = 0;
	};
}

#endif
