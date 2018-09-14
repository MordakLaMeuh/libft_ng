
#include "libft.h"

extern void putchar(char c);

void	putstr(const char *s)
{
	size_t len = strlen(s);

	for (size_t i = 0; i < len; i++)
		putchar(s[i]);
}
