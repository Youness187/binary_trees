#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *right_ro, *tmp;

	if (!tree || !tree->left)
		return (NULL);

	right_ro = tree->left;
	tmp = right_ro->right;
	right_ro->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = right_ro;
	right_ro->parent = tmp;
	if (tmp)
	{
		if (tmp->right == tree)
			tmp->right = right_ro;
		else
			tmp->left = right_ro;
	}

	return (right_ro);
}
