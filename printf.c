#include "main.h"
#define BUFF_SIZE 1024

/**
 * _printf - print a formatted strign to std out
 *@format: format string to be parsed
 * Return: number of printed characters
*/
int _printf(const char *format, ...)
{
	va_list args;
	size_t indx, maxlength;
	char buffer[BUFF_SIZE];

	indx = 0;
	maxlength = BUFF_SIZE;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	indx = parser(format, buffer, maxlength, args, indx);
	va_end(args);
	write(1, buffer, indx);
	return (indx);
}
