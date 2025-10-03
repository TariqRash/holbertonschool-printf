#include "main.h"

char g_buffer[1024];
int g_buffer_index = 0;

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

int add_to_buffer(char c)
{
	if (g_buffer_index >= 1024)
		flush_buffer();
	
	g_buffer[g_buffer_index++] = c;
	return (1);
}

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
