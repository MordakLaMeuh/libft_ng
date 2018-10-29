/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:44:36 by bmickael          #+#    #+#             */
/*   Updated: 2018/10/29 17:44:42 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chained_tools.h"

void	lst_del(
		struct s_list **alst,
		void (*del)(void *, size_t, void (*)(void *)),
		void (*deallocator)(void *))
{
	struct s_list *current;
	struct s_list *tmp;

	current = *alst;
	while (current)
	{
		del(current->content, current->content_size, deallocator);
		tmp = current;
		current = current->next;
		deallocator(tmp);
	}
	*alst = NULL;
}
