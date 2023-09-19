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
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @buffer: A list of all the posible functions
 * @maxlength: max length of buffer
 * @args: A list containing all the argumentents passed to the program.
 * @str: string only
 * @indx: size of buffer
 * Return: int number of printed
 */
int parser(const char *format, char *buffer, size_t maxlength,
		va_list args, char *str, int indx)
{
	while (*format)
	{
		if (*format != '%')
		{
			/* append cahracter to buffer and append it  */
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
			str = va_arg(args, char*);
			if (str == NULL)
				str = "(null)";
			while (*str)
			{
				append_out_buffer(*str, buffer, indx++, maxlength);
				str++;
			}
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
