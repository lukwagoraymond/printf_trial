#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf -    Function to print out on Standard
 *              output
 * @format:     Variable part of function mandatory
 *              arguments 
 * @...:        Optional part of function to be 
 *              filled with variable number of
 *              arguments
 * Return:      Returns an integer value 
 */
int _printf(const char *format, ...)
{
	int index;
	char *str = NULL;
	int k;
	int count = 0;

	va_list(arguments);
	va_start(arguments, format);

	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			_putchar(format[index]);
			count += 1;
		}
		/* To account for '%c' conversion specifier */
		else if (format[index] == '%' && format[index + 1] == 'c')
		{
			_putchar(va_arg(arguments, int));
			index++;
			count += 1;
		}
		/* To account for '%s' conversion specifier */
		else if (format[index] == '%' && format[index + 1] == 's')
		{
			str = va_arg(arguments, char*);
			index++;
			
			for (k = 0; str[k] != '\0'; k++)
				_putchar(str[k]);
				count += 1;
		}
		/* To account for '%%' conversion specifier */
		else if (format[index] == '%' && format[index + 1] == '%')
		{
			_putchar('%');
			count += 1;
		}
	}
	va_end(arguments);
	return (count);
}