#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <unistd.h>

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
		va_list args, size_t indx);
/**
 * _printf - print a formatted strign to std out
 *@format: format string to be parsed
 * Return: number of printed characters
*/
int _printf(const char *format, ...);



#endif
