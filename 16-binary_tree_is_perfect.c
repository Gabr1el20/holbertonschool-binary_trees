#include "binary_trees.h"

/**
 * binary_tree_heightR - calculates height of the left side
 * @tree: tree to calculate height of
 * Return: height
 */
int binary_tree_heightR(const binary_tree_t *tree)
{
	int countR = 0;
	int countL = 0;

	if (!tree) /* stop as leaf not as NULL*/
		return (0);

	countL = binary_tree_heightR(tree->left);
	countR = binary_tree_heightR(tree->right);
	if (countR >= countL)
		return (countR + 1);
	else
		return (countL + 1);
}
/**
 * binary_tree_heightL - calculates height of the left side
 * @tree: tree to calculate height of
 * Return: height
 */
int binary_tree_heightL(const binary_tree_t *tree)
{
	int countR = 0;
	int countL = 0;

	if (!tree) /* stop as leaf not as NULL*/
		return (0);

	countL = binary_tree_heightL(tree->left);
	countR = binary_tree_heightL(tree->right);
	if (countR >= countL)
		return (countR + 1);
	else
		return (countL + 1);
}
/**
 * binary_tree_balance - calculates balance factor of a tree
 * @tree: tree to calculate the balance factor of
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int countL = 0;
	int countR = 0;

	if (!tree) /* stop as leaf not as NULL*/
		return (0);

	countL = binary_tree_heightL(tree->left);
	countR = binary_tree_heightR(tree->right);

	return (countL - countR);
}

/**
 * binary_tree_size - A function that measures the size
 * of a binary tree.
 * @tree: A pointer to the root node of the tree to measure
 * the size.
 * Return: The size of the node, or 0 if tree == NULL
 */
int tree_size(const binary_tree_t *tree)
{
	int sizebin = 0;

	if (!tree)
		return (0);

	sizebin += tree_size(tree->left) + tree_size(tree->right) + 1;
	return (sizebin);
}

/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: tree to perform perfect check on
 * Return: 1 on perfection
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfection = tree_size(tree);

	if (binary_tree_balance(tree) == 0)
	{
		if (perfection == 1)
			return (1);
		/* checks if power of 2 */
		if (perfection & (perfection - 1))
			return (1);
		return (0);
	}
	return (0);
}
