
#include "libft.h"

void	*memset4(
	u32 *restrict dst,
	u32 patern,
	size_t n)
{
	while (n--)
		*dst++ = patern;
	return dst;
}
