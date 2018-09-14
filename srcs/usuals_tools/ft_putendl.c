
#include "libft.h"

extern void putchar(char c);

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	putchar('\n');
}
