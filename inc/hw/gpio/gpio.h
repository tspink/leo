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

				void direction(GPIODirection new_direction);
				GPIODirection direction();
				
				void set_feature(GPIOFeature feature);
				void clear_feature(GPIOFeature feature);
				GPIOFeature features();
				
				void set_state(GPIOState state);
				void toggle_state();
				GPIOState state();
				
				void enable();
				void disable();
				bool enabled();
				bool disabled();
			};
		}
	}
}

#endif	/* GPIO_H */

