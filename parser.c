#include "main.h"
/**
 * append_out_buffer - append a character to out buffer
 * @character: character to be appened
 * @buffer: a pointer to the the buufer
 * @idx: index to append to
 * @maxlen: max length of the buffer
*/
void append_out_buffer(char character, void *buffer, size_t idx, size_t maxlen)
{
	if (idx < maxlen)
		((char *)buffer)[idx] = character;
}

/**
 * append_string - append a character to out buffer
 * @buffer: a pointer to the the buufer
 * @indx: index to append to
 * @maxlen: max length of the buffer
 * @args: list of args
 * Return: 1 or -1 depends on the case
*/
int append_string(char *buffer, va_list args, size_t *indx, size_t maxlen)
{
	int found_null;
	char *str;

	str = va_arg(args, char*);
	found_null = 0;
	if (str == NULL)
	{
		str = "(null)";
		found_null = 1;
	}
	while (*str)
	{
		append_out_buffer(*str, buffer, (*indx)++, maxlen);
		str++;
	}
	if (found_null)
		return (-1);
	else
		return (1);
}
/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @buffer: A list of all the posible functions
 * @maxlength: max length of buffer
 * @args: A list containing all the argumentents passed to the program.
 * @indx: size of buffer
 * Return: int number of printed
 */
int parser(const char *format, char *buffer, size_t maxlength,
		va_list args, size_t indx)
{
	int n;

	while (*format)
	{
		if (*format != '%')
		{
			append_out_buffer(*format, buffer, indx++, maxlength);
			format++;
			continue;
		}
		else
			format++; /* evaluate what after %*/
		switch (*format)
		{
		case 'c':
			append_out_buffer((char)va_arg(args, int), buffer,
					indx++, maxlength);
			format++;
			break;
		case 's':
			n = append_string(buffer, args, &indx, maxlength);
			if (n == -1)
				return (n);
			format++;
			break;
		case '%':
			append_out_buffer('%', buffer, indx++, maxlength);
			format++;
			break;
		default:
			append_out_buffer(*format, buffer, indx++, maxlength);
			format++;
			break;
		}
	}
	return (indx);
}
