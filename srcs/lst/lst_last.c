/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*ft_lst_last(void *lst)
{
	t_gen_lst	*lst_cast;

	lst_cast = lst;
	while (lst_cast && lst_cast->next)
		lst_cast = lst_cast->next;
	return (lst_cast);
}

void	*ft_dlst_last(void *lst)
{
	return (ft_lst_last(lst));
}
