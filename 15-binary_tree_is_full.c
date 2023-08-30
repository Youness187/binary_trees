#include "binary_trees.h"
/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if is full or 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	l = binary_tree_is_full(tree->left);
	r = binary_tree_is_full(tree->right);

	return (l && r);
}

