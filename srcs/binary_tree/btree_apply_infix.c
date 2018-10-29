/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:44:35 by bmickael          #+#    #+#             */
/*   Updated: 2018/10/29 17:44:42 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_internal_header.h"

int		btree_apply_infix(struct s_node *root, void (*applyf)(void *))
{
	if (applyf == NULL)
		return (-EINVAL);
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, applyf);
		applyf(root->content);
		if (root->right)
			btree_apply_infix(root->right, applyf);
	}
	return (0);
}

int		btree_apply_infix_rev(struct s_node *root, void (*applyf)(void *))
{
	if (applyf == NULL)
		return (-EINVAL);
	if (root)
	{
		if (root->right)
			btree_apply_infix_rev(root->right, applyf);
		applyf(root->content);
		if (root->left)
			btree_apply_infix_rev(root->left, applyf);
	}
	return (0);
}
