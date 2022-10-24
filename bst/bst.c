#include <stdlib.h>
#include "bst.h"

void Insert(BSTNode **root, int val)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(BSTNode));
        (*root)->left = (*root)->right = NULL;
        (*root)->val = val;
    }
    else if (*root != NULL && val < (*root)->val)
    {
        Insert(&(*root)->left, val);
    }
    else if (*root != NULL && val > (*root)->val)
    {
        Insert(&(*root)->right, val);
    }
}

void FreeBST(BSTNode *root)
{
    if (root != NULL)
    {
        FreeBST(root->left);
        FreeBST(root->right);
        free(root);
    }
}