#include "binary_trees.h"
/**
 * height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: the height of the tree
 */
int height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l = height(tree->left) + 1;
	if (tree->right)
		r = height(tree->right) + 1;

	return ((l < r) ? r : l);
}

/**
 * is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check.
 * @s: the smallest value
 * @l: the largest value
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int s, int l)
{
	int balance;

	if (tree != NULL)
	{
		if (tree->n < s || tree->n > l)
			return (0);
		balance = height(tree->left) - height(tree->right);
		if (balance > 1 || balance < 0)
			return (0);
		return (is_avl(tree->left, s, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, l));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, (-1 * __INT_MAX__), __INT_MAX__));
}
