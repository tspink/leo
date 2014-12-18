#include <platform/launchpad.h>
#include <hw/uart/uart.h>

using namespace leo::platform;

Launchpad::Launchpad() : _debug_uart(new hw::uart::NullUART())
{
	
}

bool Launchpad::initialise()
{
	return true;	
}

void Launchpad::shutdown()
{
	
}

int Launchpad::ticks() const
{
	return 0;
}

leo::hw::uart::UART *Launchpad::get_uart(int id)
{
	if (id != 0)
		return NULL;
	return _debug_uart;
}

leo::hw::gpio::GPIO *Launchpad::get_gpio(int id)
{
	return NULL;
}
