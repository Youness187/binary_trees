#include "binary_trees.h"
/**
 * array_to_avl - function that builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: a pointer to the root node of the created AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (array[j] == array[i])
				if (j == i)
					if (!avl_insert(&tree, array[i]))
						return (NULL);
				break;
		}
	}
	return (tree);
}
