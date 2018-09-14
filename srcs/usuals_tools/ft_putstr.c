
#include "libft.h"

extern void putchar(char c);

void	ft_putstr(const char *s)
{
	size_t len = ft_strlen(s);

	for (size_t i = 0; i < len; i++)
		putchar(s[i]);
}
