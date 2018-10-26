/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:21:53 by bmickael           #+#    #+#             */
/*   Updated: 2018/07/22 17:21:56 by bmickael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_ALLOCATOR_H
# define CUSTOM_ALLOCATOR_H

# include <stdlib.h>

struct				s_custom_memory_fn
{
	void			*(*allocator)(size_t);
	void			(*deallocator)(void *);
};

#endif
