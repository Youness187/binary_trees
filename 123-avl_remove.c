#include "binary_trees.h"

/**
 * measures_balance - Measures balance factor of a AVL
 * @tree: tree
 */
void measures_balance(avl_t **tree)
{
	int balance;

	if (!tree || !(*tree))
		return;
	if (((*tree)->left) && !((*tree)->right))
		return;
	measures_balance(&(*tree)->left);
	measures_balance(&(*tree)->right);
	balance = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
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
 * avl_remove - remove a node from a AVL tree
 * @root:  is a pointer to the root node of the tree
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tree = (avl_t *) bst_delete(root, root, value);

	if (tree == NULL)
		return (NULL);
	measures_balance(&tree);
	return (tree);
}
