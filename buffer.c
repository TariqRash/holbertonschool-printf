#include "main.h"

static char buffer[1024];
static int buf_index = 0;

int add_to_buffer(char c)
{
	if (buf_index >= 1024)
		flush_buffer();
	buffer[buf_index++] = c;
	return (1);
}

int flush_buffer(void)
{
	int count = buf_index;

	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		buf_index = 0;
	}
	return (count);
}

void reset_buffer(void)
{
	buf_index = 0;
}
