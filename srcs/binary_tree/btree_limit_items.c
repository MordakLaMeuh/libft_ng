/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_limit_items.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_internal_header.h"

/*
** Logically, if the tree is okay, highest item is in far right sector.
*/

struct s_node	*btree_get_highest_node(struct s_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->right)
		node = node->right;
	return (node);
}

/*
** Logically, if the tree is okay, lowest item is in far left sector.
*/

struct s_node	*btree_get_lowest_node(struct s_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->left)
		node = node->left;
	return (node);
}

/*
** Logically, if the tree is okay, highest item is in far right sector.
*/

void			*btree_get_highest_node_content(struct s_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->right)
		node = node->right;
	return (node->content);
}

/*
** Logically, if the tree is okay, lowest item is in far left sector.
*/

void			*btree_get_lowest_node_content(struct s_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->left)
		node = node->left;
	return (node->content);
}

int				btree_is_last_node(struct s_node *node)
{
	if (node == NULL)
		return (-EINVAL);
	if (node->parent == NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
