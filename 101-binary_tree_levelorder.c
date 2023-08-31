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
 * print_current_level - Print nodes at a current level
 * @root: is a pointer the node of the tree to traverse
 * @level: level of the tree
 * @func: is a pointer to a function to call for each node
*/
void print_current_level(const binary_tree_t *root, int level,
						void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 0)
		func(root->n);
	else if (level > 0)
	{
		print_current_level(root->left, level - 1, func);
		print_current_level(root->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a B-T using level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree || !func)
		return;
	h = binary_tree_height(tree);

	for (i = 0; i <= h; i++)
		print_current_level(tree, i, func);
}
