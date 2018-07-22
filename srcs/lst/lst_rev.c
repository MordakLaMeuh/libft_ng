/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lst_rev(void **lst)
{
	t_gen_lst *a;
	t_gen_lst *b;
	t_gen_lst *c;

	a = NULL;
	b = *lst;
	c = b->next;
	while (b)
	{
		b->next = a;
		a = b;
		b = c;
		if (c)
			c = c->next;
	}
	*lst = a;
}
