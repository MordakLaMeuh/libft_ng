/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_check_binary_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_internal_header.h"

static int	apply_infix_ret(struct s_node *root, int (*applyf)(void *))
{
	int ret;

	ret = 0;
	if (root)
	{
		if (root->left)
			ret |= apply_infix_ret(root->left, applyf);
		ret |= applyf(root->content);
		if (root->right)
			ret |= apply_infix_ret(root->right, applyf);
	}
	return (ret);
}

int			btree_check_binary_tree(struct s_node *root, int (*applyf)(void *))
{
	if (applyf == NULL)
		return (-EINVAL);
	return (apply_infix_ret(root, applyf));
}
