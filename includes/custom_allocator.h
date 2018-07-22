/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:21:53 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:21:56 by vcombey          ###   ########.fr       */
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
