/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_get_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:13:04 by bmickael          #+#    #+#             */
/*   Updated: 2017/03/24 07:10:12 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_internal_header.h"

struct s_node	*btree_get_node_by_content(
		struct s_node *root,
		void *data_ref,
		int (*cmpf)(void *, struct s_node *))
{
	int				diff;

	if (root == NULL || cmpf == NULL)
		return (NULL);
	diff = cmpf(data_ref, root);
	if (diff == 0)
		return (root);
	if (diff < 0)
		return (btree_get_node_by_content(root->left, data_ref, cmpf));
	return (btree_get_node_by_content(root->right, data_ref, cmpf));
}
