/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iteri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lst_iteri(void *start, void *end, void (*f)(void*, size_t))
{
	size_t		i;
	t_gen_lst	*start_cast;

	i = 0;
	start_cast = start;
	while (start_cast != end)
	{
		(*f)(start_cast, i);
		start_cast = start_cast->next;
		i++;
	}
}

void	ft_dlst_iteri(void *start, void *end,\
		void (*f)(void*, size_t), int order)
{
	size_t		i;
	t_gen_dlst	*start_cast;

	i = 0;
	start_cast = start;
	while (start_cast != end)
	{
		(*f)(start_cast, i);
		if (order > 0)
			start_cast = start_cast->next;
		else if (order < 0)
			start_cast = start_cast->prev;
		i++;
	}
}
