#include "binary_trees.h"
/**
 * is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 * @s: the smallest value
 * @l: the largest value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int s, int l)
{
	if (tree)
	{
		if (tree->n < s || tree->n > l)
			return (0);
		return (is_bst(tree->left, s, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, l));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree:  is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, (-1 * __INT_MAX__), __INT_MAX__));
}
