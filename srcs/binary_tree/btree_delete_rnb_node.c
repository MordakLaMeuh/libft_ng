
#include "btree_internal_header.h"

int	btree_delete_rnb_node_by_content(
	struct s_node **root,
	void *content,
	int (*cmpf)(void *, void *),
	int (*deallocator)(void *))
{
	struct s_node *node_to_trash;
	struct s_node *sibling;

	sibling = NULL;
	if (root == NULL || cmpf == NULL || deallocator == NULL)
		return (-EINVAL);
	node_to_trash = btree_get_node_by_content(*root, content, cmpf);
	if (node_to_trash == NULL)
		return (-1);
	node_to_trash = btree_internal_trash_node(node_to_trash, root,
			&sibling);
	if (node_to_trash->parent != NULL)
		apply_delete_strategy(node_to_trash, root, sibling);
	else if (*root)
		SET_BLACK((*root));
	deallocator(node_to_trash);
	return (0);
}

void *btree_delete_rnb_node_by_content_and_return(
	struct s_node **root,
	void *content,
	int (*cmpf)(void *, void *),
	void *(*functor)(void *))
{
	struct s_node *node_to_trash;
	struct s_node *sibling;

	sibling = NULL;
	if (root == NULL || cmpf == NULL)
		return NULL;
	node_to_trash = btree_get_node_by_content(*root, content, cmpf);
	if (node_to_trash == NULL)
		return NULL;
	node_to_trash = btree_internal_trash_node(node_to_trash, root,
			&sibling);
	if (node_to_trash->parent != NULL)
		apply_delete_strategy(node_to_trash, root, sibling);
	else if (*root)
		SET_BLACK((*root));
	return functor(node_to_trash);
}

int	btree_delete_rnb_node(
	struct s_node **root,
	struct s_node *node,
	int (*deallocator)(void *))
{
	struct s_node *node_to_trash;
	struct s_node *sibling;

	sibling = NULL;
	if (root == NULL || node == NULL || deallocator == NULL)
		return (-EINVAL);
	node_to_trash = btree_internal_trash_node(node, root, &sibling);
	if (node_to_trash->parent != NULL)
		apply_delete_strategy(node_to_trash, root, sibling);
	else if (*root)
		SET_BLACK((*root));
	deallocator(node_to_trash);
	return (0);
}
