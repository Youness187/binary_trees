#include "binary_trees.h"
/**
 * sorted - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @start: start
 * @last: end
 * Return: a pointer to the root node of the created AVL tree
 */
avl_t *sorted(avl_t *parent, int *array, int start, int last)
{
	avl_t *root, *new;
	int mid = 0;

	if (start <= last)
	{
		mid = (start + last) / 2;
		new = binary_tree_node(parent, array[mid]);
		if (new == NULL)
			return (NULL);
		root = new;
		root->left = sorted(root, array, start, mid - 1);
		root->right = sorted(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: a pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (sorted(NULL, array, 0, ((int)(size)) - 1));
}
