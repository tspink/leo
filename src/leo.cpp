#include <leo.h>
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
	// Initialise the platform
	if (!_platform.initialise()) {
		return false;
	}
	
	//_platform.debug_uart().
	
	// Run the application (if there is one)
	bool result = true;
	if (main_application) {
		result = main_application->run(*this);
	}

	// Shut down the platform	
	_platform.shutdown();
	
	return result;
}
