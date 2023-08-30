#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a
 * binary tree
 * @tree: Pointer to the root node of the tree to measure the
 * height
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	/* Check if tree is NULL */
	if (!tree)
		return (0);

	/* Recursively measure the height of the left and right subtrees */
	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;

	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;

	/* Return the maximum of the two heights plus one */
	return (left_height >= right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Function that measures the balance
 * factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the
 * balance factor
 * Return: The balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	/* Check if tree is NULL */
	if (!tree)
		return (0);

	/* Measure the height of the left and right subtrees */
	if (tree->left)
		left_height = (int)binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = (int)binary_tree_height(tree->right) + 1;

	/* Return the difference between the two heights */
	return (left_height - right_height);
}
