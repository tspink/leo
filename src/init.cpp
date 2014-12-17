#include <leo.h>

extern "C" void app_start(void);

extern "C" void leo_start()
{
	app_start();
}
