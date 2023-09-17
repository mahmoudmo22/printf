#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 *
*/
int _printf(const char *format, ...);



#endif //_PRINTF_H
