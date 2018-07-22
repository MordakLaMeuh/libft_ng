/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chained_tools.h"

struct s_list	*lst_create_elem(void *data, size_t len,
		void *(*allocator)(size_t))
{
	struct s_list *elmt;

	if (!(elmt = (struct s_list *)allocator(sizeof(struct s_list))))
		return (NULL);
	elmt->content = data;
	elmt->content_size = len;
	return (elmt);
}
