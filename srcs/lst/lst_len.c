/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
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
