#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as
 * the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *rightNode = malloc(sizeof(binary_tree_t)), *oldright = parent->right;

    if (parent == NULL)
        return (NULL);
    if (rightNode)
    {
        rightNode->n = value;
        rightNode->parent = parent;
        if (oldright == NULL)
        {
            parent->right = rightNode;
            rightNode->left = NULL;
            rightNode->right = NULL;
        }
        else
        {
            parent->right = rightNode;
            rightNode->right = oldright;
            oldright->parent = rightNode;
            rightNode->left = NULL;
        }
    }
    else
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }
    return (parent->left);
}