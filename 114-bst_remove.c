#include "binary_trees.h"
/**
 * delete - Deletes a node from a bst
 * @root: A pointer to the root node of the bst
 * @node: A pointer to the node to the delete from bts
 * Return: A pointer to the new root node after deletion
 */
bst_t *delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *tmp;

	if (node->left == NULL)
	{
		tmp = node->right;
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? tmp : root);
	}
	else if (node->right == NULL)
	{
		tmp = node->left;
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? tmp : root);
	}
	tmp = node->right;
	while (tmp->left)
		tmp = tmp->left;
	node->n = tmp->n;

	return (delete(root, tmp));
}

/**
 * bst_delete - removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree
 * @node: A pointer to the node to the delete from bts
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root node after removing the desired value
 */
bst_t *bst_delete(bst_t *node, bst_t *root, int value)
{
	if (!node)
		return (NULL);
	if (node->n == value)
		return (delete(root, node));
	if (node->n > value)
		return (bst_delete(node->left, root, value));
	return (bst_delete(node->right, root, value));
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root node removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	return (bst_delete(root, root, value));
}
