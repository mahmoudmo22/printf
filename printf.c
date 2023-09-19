#include "main.h"
#define BUFF_SIZE 1024U

/**
 * _printf - print a formatted strign to std out
 *@format: format string to be parsed
 * Return: number of printed characters
*/
int _printf(const char *format, ...)
{
	va_list args;
	int indx, maxlength;
	char buffer[BUFF_SIZE];
	char *str = NULL;

	indx = 0;
	maxlength = BUFF_SIZE;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	indx = parser(format, buffer, maxlength, args, str, indx);
	va_end(args);
	write(1, buffer, indx);
	return (indx);
}
