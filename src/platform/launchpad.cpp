#include <platform/launchpad.h>

using namespace leo::platform;

Launchpad::Launchpad() : _debug_uart(0)
{
	
}

bool Launchpad::initialise()
{
	return true;	
}

void Launchpad::shutdown()
{
	
}

leo::hw::uart::UART& Launchpad::debug_uart()
{
	return *_debug_uart;
}
