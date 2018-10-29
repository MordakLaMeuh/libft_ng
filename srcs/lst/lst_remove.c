/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:44:38 by bmickael          #+#    #+#             */
/*   Updated: 2018/10/29 17:44:42 by bmickael         ###   ########.fr       */
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
