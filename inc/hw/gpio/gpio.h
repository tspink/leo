/* 
 * File:   GPIO.h
 * Author: spink
 *
 * Created on 18 December 2014, 08:23
 */

#ifndef GPIO_H
#define	GPIO_H

namespace leo
{
	namespace hw
	{
		namespace gpio
		{
			class GPIO
			{
			public:
				enum GPIODirection
				{
					Input,
					Output
				};
				
				enum GPIOFeature
				{
					PullUp = 1,
					PullDown = 2,
					OpenDrain = 4
				};
				
				enum GPIOState
				{
					Inactive,
					Active
				};

				void direction(GPIODirection new_direction) = 0;
				GPIODirection direction() = 0;
				
				bool is_feature_supported(GPIOFeature feature) = 0;
				void set_feature(GPIOFeature feature) = 0;
				void clear_feature(GPIOFeature feature) = 0;
				GPIOFeature features() = 0;
				
				void set_state(GPIOState state) = 0;
				void toggle_state() = 0;
				GPIOState state() = 0;
				
				void enable() = 0;
				void disable() = 0;
				bool enabled() = 0;
				bool disabled() = 0;
			};
		}
	}
}

#endif	/* GPIO_H */

