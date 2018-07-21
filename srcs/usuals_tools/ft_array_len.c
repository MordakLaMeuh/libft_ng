#include "libft.h"

size_t	array_len(void **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
