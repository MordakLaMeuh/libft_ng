/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_internal_header.h"

static int	recurse_level_count(struct s_node *root, int n)
{
	int i;
	int j;

	i = n;
	j = n;
	if (root)
	{
		if (root->left)
			i = recurse_level_count(root->left, n + 1);
		if (root->right)
			j = recurse_level_count(root->right, n + 1);
	}
	return ((i > j) ? i : j);
}

int			btree_level_count(struct s_node *root)
{
	if (!root)
		return (0);
	return (recurse_level_count(root, 1));
}
