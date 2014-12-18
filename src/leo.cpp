#include <leo.h>
#include <hw/uart/uart.h>
#include <platform/launchpad.h>

using namespace leo;

extern Application *main_application;
Application *main_application __attribute__((weak));

/**
 * Construct a new LEO on the given platform.
 */
Leo::Leo(Platform& platform) : _platform(platform)
{

}

/**
 * Start LEO
 */
bool Leo::start()
{
	irq.relocate_exception_vectors();
	
	// Initialise the platform
	if (!_platform.initialise()) {
		return false;
	}
	
	_platform.debug_uart().write_string("LEO is starting...\n");
	
	// Run the application (if there is one)
	bool result = true;
	if (main_application) {
		result = main_application->run(*this);
	}

	_platform.debug_uart().write_string("LEO is stopping...\n");

	// Shut down the platform	
	_platform.shutdown();
	
	return result;
}

void Leo::delay(int ms)
{
	// TODO
}