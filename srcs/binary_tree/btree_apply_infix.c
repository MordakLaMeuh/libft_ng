
#include "btree_internal_header.h"

int	btree_apply_infix(struct s_node *root, void (*applyf)(void *))
{
	if (applyf == NULL)
		return (-EINVAL);
	if (root) {
		if (root->left)
			btree_apply_infix(root->left, applyf);
		applyf(root->content);
		if (root->right)
			btree_apply_infix(root->right, applyf);
	}
	return (0);
}
