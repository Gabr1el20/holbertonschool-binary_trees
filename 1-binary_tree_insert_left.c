#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as
 * the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *leftNode = malloc(sizeof(binary_tree_t)), *oldLeft = parent->left;

    if (parent == NULL)
        return (NULL);
    if (leftNode)
    {
        leftNode->n = value;
        leftNode->parent = parent;
        if (oldLeft == NULL)
        {
            parent->left = leftNode;
            leftNode->left = NULL;
            leftNode->right = NULL;
        }
        else
        {
            parent->left = leftNode;
            leftNode->left = oldLeft;
            oldLeft->parent = leftNode;
            leftNode->right = NULL;
        }
    }
    else
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }
    return (parent->left);
}