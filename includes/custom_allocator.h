
#ifndef CUSTOM_ALLOCATOR_H
# define CUSTOM_ALLOCATOR_H

#include "i386_type.h"

struct		s_custom_memory_fn
{
	void	*(*allocator)(size_t);
	int	(*deallocator)(void *);
};

#endif
