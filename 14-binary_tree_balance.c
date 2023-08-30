#include "binary_trees.h"
/**
 * binary_tree_balance - that measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: the measure the balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l = binary_tree_balance(tree->left) + 1;
	if (tree->right)
		r = binary_tree_balance(tree->right) + 1;

	return (l - r);
}
