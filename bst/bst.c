#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void Insert(BSTNode **root, int val)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(**root));
        (*root)->left = (*root)->right = (*root)->parent = NULL;
        (*root)->val = val;
        return;
    }

    if (val < (*root)->val)
    {
        if ((*root)->left != NULL) return Insert(&((*root)->left), val);

        (*root)->left = malloc(sizeof(**root));
        (*root)->left->left = (*root)->left->right = NULL;
        (*root)->left->parent = *root;
        (*root)->left->val = val;
    }
    else
    {
        if ((*root)->right != NULL) return Insert(&((*root)->right), val);

        (*root)->right = malloc(sizeof(**root));
        (*root)->right->left = (*root)->right->right = NULL;
        (*root)->right->parent = *root;
        (*root)->right->val = val;
    }
}

BSTNode* Find(BSTNode *root, int val)
{
    if (root == NULL || root->val == val) return root;

    if (val < root->val) return Find(root->left, val);
    return Find(root->right, val);
}

void Delete(BSTNode *target)
{

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