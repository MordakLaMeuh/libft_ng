/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_get_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_internal_header.h"

void			*btree_search_content(struct s_node *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	int diff;

	if (root == NULL || cmpf == NULL)
		return (NULL);
	diff = cmpf(data_ref, root->content);
	if (diff == 0)
		return (root->content);
	if (diff < 0)
		return (btree_search_content(root->left, data_ref, cmpf));
	return (btree_search_content(root->right, data_ref, cmpf));
}

struct s_node	*btree_get_node_by_content(
		struct s_node *root,
		void *data_ref,
		int (*cmpf)(void *, void *))
{
	int				diff;

	if (root == NULL || cmpf == NULL)
		return (NULL);
	diff = cmpf(data_ref, root->content);
	if (diff == 0)
		return (root);
	if (diff < 0)
		return (btree_get_node_by_content(root->left, data_ref, cmpf));
	return (btree_get_node_by_content(root->right, data_ref, cmpf));
}
