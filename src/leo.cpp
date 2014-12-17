#include <leo.h>
#include <platform/launchpad.h>

using namespace leo;

extern Application *main_application;

Leo::Leo(Platform& platform) : _platform(platform)
{

}

void Leo::start()
{
	// Initialise the platform
	if (!_platform.initialise()) {
		return;
	}
	
	// Run the application
	if (main_application) {
		main_application->run(*this);
	}
}
