/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pushback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*ft_lst_pushback(void **first, void *new_node)
{
	t_gen_lst *last;

	if (!(*first))
	{
		*first = new_node;
		return (new_node);
	}
	last = ft_lst_last(*first);
	last->next = new_node;
	return (new_node);
}

void	*ft_dlst_pushback(void **first, void *new)
{
	t_gen_dlst	*last;
	t_gen_dlst	*new_cast;

	if (!(*first))
	{
		*first = new;
		return (new);
	}
	new_cast = new;
	last = ft_dlst_last(*first);
	last->next = new;
	new_cast->prev = last;
	return (new);
}