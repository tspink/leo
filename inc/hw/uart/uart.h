#ifndef __UART_H__
#define	__UART_H__

namespace leo
{
	namespace hw
	{
		namespace uart
		{
			class UART
			{
			public:
				virtual int write(const char *buffer, int length) = 0;
				virtual int read(char *buffer, int length) = 0;
			};
		}
	}
}

#endif

