#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l = binary_tree_height(tree->left) + 1;
	if (tree->right)
		r = binary_tree_height(tree->right) + 1;

	return ((l < r) ? r : l);
}
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
		l = binary_tree_height(tree->left) + 1;
	if (tree->right)
		r = binary_tree_height(tree->right) + 1;

	return (l - r);
}
/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	l = binary_tree_size(tree->left);
	r = binary_tree_size(tree->right);

	return (l + r + 1);
}
/**
 * perf - checks if the tree is perfect
 * @tree: a pointer to a tree
 * Return: 1 if is perfect or 0 if not
 */
int perf(const binary_tree_t *tree)
{
	int h, s, p, i;

	if (!tree)
		return (0);

	h = (int)binary_tree_height(tree) + 1;
	s = (int)binary_tree_size(tree);

	p = 1;

	for (i = 0; i < h; i++)
		p *= 2;

	if (s == p - 1)
		return (1);

	return (0);
}
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if perfect or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (binary_tree_balance(tree) == 0 && perf(tree))
		return (1);
	return (0);
}

