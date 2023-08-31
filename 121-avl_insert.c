#include "binary_trees.h"
/**
 * insert_node - function that inserts a value in an AVL Tree
 * @tree: is a double pointer to the root
 * @parent: parent node of struct avl
 * @new: the new node
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *insert_node(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int balance;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = insert_node(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insert_node(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	balance = binary_tree_balance(*tree);
	if (balance > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (balance < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - function that inserts a value in an AVL Tree
 * @tree: is a double pointer to the root
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_node(tree, *tree, &new, value);
	return (new);
}
