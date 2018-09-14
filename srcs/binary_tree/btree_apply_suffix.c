
#include "btree_internal_header.h"

int	btree_apply_suffix(struct s_node *root, void (*applyf)(void *))
{
	if (applyf == NULL)
		return (-EINVAL);
	if (root) {
		if (root->left)
			btree_apply_suffix(root->left, applyf);
		if (root->right)
			btree_apply_suffix(root->right, applyf);
		applyf(root->content);
	}
	return (0);
}
