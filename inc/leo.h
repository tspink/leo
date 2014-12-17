#ifndef __LEO_H__
#define __LEO_H__

namespace leo
{
	class Platform;
	
	class Leo
	{
	public:
		Leo(Platform& platform);
		bool start();
		
		inline Platform& platform() const { return _platform; }
		
	private:
		Platform& _platform;
	};
	
	class Application
	{
	public:
		virtual bool run(Leo& leo) = 0;
	};
}

#endif
