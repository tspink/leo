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

leo::hw::uart::UART& Launchpad::debug_uart()
{
	return *_debug_uart;
}
