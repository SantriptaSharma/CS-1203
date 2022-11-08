#include <stdlib.h>
#include <stdio.h>
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

BSTNode* Find(BSTNode *root, int val)
{
    if (root == NULL || root->val == val) return root;

    if (val < root->val) return Find(root->left, val);
    return Find(root->right, val);
}

static void InOrderRecursive(BSTNode *cur)
{
    if (cur->left) InOrderRecursive(cur->left);
    printf("%d, ", cur->val);
    if (cur->right) InOrderRecursive(cur->right);
}

void PrintInOrder(BSTNode *root)
{
    printf("[ ");
    InOrderRecursive(root);
    printf(" ]\n");
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