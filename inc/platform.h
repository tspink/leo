#ifndef __PLATFORM_H__
#define	__PLATFORM_H__

#define HZ	1
#define kHZ	1e3
#define MHZ	1e6

namespace leo
{
	namespace hw
	{
		namespace uart
		{
			class UART;
			class GPIO;
		}
	}
	
	class Platform
	{
	public:
		virtual bool initialise() = 0;
		virtual void shutdown() = 0;
		
		virtual int freq() const = 0;
		virtual int ticks() const = 0;
		
		virtual hw::uart::UART *get_uart(int id) = 0;
		virtual hw::gpio::GPIO *get_gpio(int id) = 0;
	};
}

#endif

