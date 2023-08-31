#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a B-T using level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (!tree->parent)
		func(tree->n);
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	if (tree->left)
		binary_tree_levelorder(tree->left, func);
	if (tree->right)
		binary_tree_levelorder(tree->right, func);
}
