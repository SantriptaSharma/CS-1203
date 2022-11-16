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

BSTNode* FindMinimum(BSTNode *root)
{
    if (root == NULL || root->left == NULL) return root;

    return FindMinimum(root->left);
}

BSTNode* FindSuccessor(BSTNode *target)
{
    if (target->right != NULL)
    {
        return FindMinimum(target->right);
    }

    BSTNode *parent = target->parent;
    
    while (parent != NULL && target == parent->right)
    {
        target = parent;
        parent = parent->parent;
    }

    return parent;
}

static void ShiftBtoA(BSTNode **root, BSTNode *a, BSTNode *b)
{
    if (a->parent == NULL)
    {
        *root = b;
    }
    else if (a == a->parent->left)
    {
        a->parent->left = b;
    }
    else
    {
        a->parent->right = b;
    }

    if (b != NULL)
    {
        b->parent = a->parent;
    }
}

BSTNode* Delete(BSTNode *target)
{
    BSTNode *root = target;
    while (root != NULL && root->parent != NULL) root = root->parent;
    
    if (target->left == NULL)
    {
        ShiftBtoA(&root, target, target->right);
        free(target);
        return root;
    }
    else if (target->right == NULL)
    {
        ShiftBtoA(&root, target, target->left);
        free(target);
        return root;
    }

    BSTNode *succ = FindSuccessor(target);
    if (succ->parent != target)
    {
        ShiftBtoA(&root, succ, succ->right);
        succ->right = target->right;
        succ->right->parent = succ;
    }
    
    ShiftBtoA(&root, target, succ);
    succ->left = target->left;
    succ->left->parent = succ;
    return root;
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