#ifndef __PLATFORM_H__
#define	__PLATFORM_H__

namespace leo
{
	namespace hw
	{
		namespace uart
		{
			class UART;
		}
	}
	
	class Platform
	{
	public:
		virtual bool initialise() = 0;
		virtual void shutdown() = 0;
		
		virtual int freq() const = 0;
		
		virtual hw::uart::UART& debug_uart() = 0;
	};
}

#endif

