
#include "libft.h"

void	putstr_fd(const char *s, int fd)
{
	write(fd, s, strlen(s));
}
