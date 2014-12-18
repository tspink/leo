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
				virtual int write_string(const char *string);

				virtual int read(char *buffer, int length) = 0;				
			};
			
			class NullUART : public UART
			{
			public:
				int write(const char *buffer, int length);
				int read(char *buffer, int length);
			};
		}
	}
}

#endif
