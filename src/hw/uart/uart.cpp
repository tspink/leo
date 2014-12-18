#include <hw/uart/uart.h>
#include <util/string.h>

using namespace leo::hw::uart;

int UART::write_string(const char *string)
{
	return write(string, util::strlen(string));
}

int NullUART::write(const char *buffer, int length)
{
	return length;
}

int NullUART::read(char *buffer, int length)
{
	return 0;
}
