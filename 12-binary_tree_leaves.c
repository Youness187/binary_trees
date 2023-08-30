#include "binary_trees.h"
/**
 * binary_tree_leaves - function that measures the leaves of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the leaves
 * Return: the leaves of the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	l = binary_tree_leaves(tree->left);
	r = binary_tree_leaves(tree->right);

	return ((l + r) == 0 ? 1 : l + r);
}

