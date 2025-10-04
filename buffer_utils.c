#include "main.h"

char g_buffer[1024];
int g_buffer_index = 0;

/**
 * flush_buffer - Writes buffer to stdout and resets index
 * Return: Number of bytes written
 */
int flush_buffer(void)
{
	int written = 0;
	if (g_buffer_index > 0)
	{
		written = write(1, g_buffer, g_buffer_index);
		g_buffer_index = 0;
	}
	return (written);
}

/**
 * add_to_buffer - Adds character to buffer
 * @c: Character to add
 * Return: Always 1
 */
int add_to_buffer(char c)
{
	if (g_buffer_index >= 1024)
		flush_buffer();
	g_buffer[g_buffer_index++] = c;
	return (1);
}

/**
 * add_str_to_buffer - Adds string to buffer
 * @str: String to add
 * @len: Length of string
 * Return: Number of characters added
 */
int add_str_to_buffer(const char *str, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (g_buffer_index >= 1024)
			flush_buffer();
		g_buffer[g_buffer_index++] = str[i];
	}
	return (len);
}
