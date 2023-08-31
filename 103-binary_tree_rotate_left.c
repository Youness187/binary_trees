#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *left_ro, *tmp;

	if (!tree || !tree->right)
		return (NULL);

	left_ro = tree->right;
	tmp = left_ro->left;
	left_ro->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = left_ro;
	left_ro->parent = tmp;
	if (tmp)
	{
		if (tmp->left == tree)
			tmp->left = left_ro;
		else
			tmp->right = left_ro;
	}

	return (left_ro);
}
