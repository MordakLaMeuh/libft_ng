/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:44:37 by bmickael          #+#    #+#             */
/*   Updated: 2018/10/29 17:44:42 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lst_add(void **first, void *new)
{
	t_gen_lst *new_cast;

	new_cast = new;
	new_cast->next = *first;
	*first = new_cast;
}

void	ft_dlst_add(void **first, void *new)
{
	t_gen_dlst *new_cast;
	t_gen_dlst *first_cast;

	first_cast = *first;
	new_cast = new;
	new_cast->next = *first;
	new_cast->prev = NULL;
	if (first_cast)
		first_cast->prev = new_cast;
	*first = new_cast;
}
