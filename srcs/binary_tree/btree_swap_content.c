/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_swap_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:38:18 by bmickael          #+#    #+#             */
/*   Updated: 2017/03/24 07:12:30 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_internal_header.h"

void			btree_swap_data(
		struct s_node *node_a,
		struct s_node *node_b)
{
	void	*content;
	size_t	size;
	uint8_t	node_type;

	content = node_a->content;
	node_a->content = node_b->content;
	node_b->content = content;

	size = node_a->size;
	node_a->size = node_b->size;
	node_b->size = size;

	node_type = node_a->mask.s.node_type;
	node_a->mask.s.node_type = node_b->mask.s.node_type;
	node_b->mask.s.node_type = node_type;
}
