
#include "libft.h"

void	putendl_fd(char const *s, int fd)
{
	putstr_fd(s, fd);
	putchar_fd('\n', fd);
}
