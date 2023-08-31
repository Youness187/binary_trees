#include "binary_trees.h"
/**
 * binary_trees_ancestor - that finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (!first->parent || (!first->parent->parent && second->parent)
		|| second->parent == first)
		return (binary_trees_ancestor(first, second->parent));

	else if (!second->parent || (!second->parent->parent && first->parent)
		|| first->parent == second )
		return (binary_trees_ancestor(first->parent, second));

	return (binary_trees_ancestor(first->parent, second->parent));
}
