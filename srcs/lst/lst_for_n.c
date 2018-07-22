/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_for_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lst_for_n(void *start, int count, void (*f)(void*))
{
	t_gen_lst	*start_cast;

	start_cast = start;
	while (start_cast && count)
	{
		(*f)(start_cast);
		start_cast = start_cast->next;
		count--;
	}
}

void	ft_dlst_for_n(void *start, int count, void (*f)(void*), int order)
{
	t_gen_dlst	*start_cast;

	start_cast = start;
	while (start_cast && count)
	{
		(*f)(start_cast);
		if (order > 0)
			start_cast = start_cast->next;
		if (order < 0)
			start_cast = start_cast->prev;
		count--;
	}
}
