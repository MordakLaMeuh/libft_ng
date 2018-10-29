/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:44:37 by bmickael          #+#    #+#             */
/*   Updated: 2018/10/29 17:44:42 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t	ft_lst_len(void *lst)
{
	t_gen_lst	*lst_cast;
	size_t		i;

	i = 0;
	lst_cast = lst;
	while (lst_cast)
	{
		lst_cast = lst_cast->next;
		i++;
	}
	return (i);
}

size_t	ft_dlst_len(void *lst)
{
	return (ft_lst_len(lst));
}
