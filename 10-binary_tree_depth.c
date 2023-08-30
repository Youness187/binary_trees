#include "binary_trees.h"
/**
 * binary_tree_depth - that measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t p = 0;

	if (!tree || !tree->parent)
		return (0);

	p = binary_tree_depth(tree->parent);
	return (p + 1);
}

