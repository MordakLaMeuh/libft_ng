/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lst_remove(void **first, void (*f)(void*))
{
	t_gen_lst		*node;
	t_gen_lst		*tmp_next;

	node = *first;
	while (node)
	{
		tmp_next = node->next;
		ft_lst_del_one(first, node, (f));
		node = tmp_next;
	}
}

void	ft_dlst_remove(void **first, void (*f)(void*))
{
	ft_lst_remove(first, f);
}
