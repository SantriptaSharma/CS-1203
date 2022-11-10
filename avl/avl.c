#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

static void UpdateHeight(AVLNode *target)
{
    if (target == NULL) return;

    int maxHeight = -1;

    if (target->left) maxHeight = target->left->height;
    if (target->right && maxHeight < target->right->height) maxHeight = target->right->height;

    target->height = maxHeight + 1;

    if (maxHeight != -1) UpdateHeight(target->parent);
}

void Insert(AVLNode **root, int val)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(**root));
        (*root)->left = (*root)->right = (*root)->parent = NULL;
        (*root)->val = val;
        (*root)->height = 0;
        return;
    }

    if (val < (*root)->val)
    {
        if ((*root)->left != NULL) return Insert(&((*root)->left), val);

        (*root)->left = malloc(sizeof(**root));
        (*root)->left->left = (*root)->left->right = NULL;
        (*root)->left->parent = *root;
        (*root)->left->val = val;
        (*root)->left->height = 0;
    }
    else
    {
        if ((*root)->right != NULL) return Insert(&((*root)->right), val);

        (*root)->right = malloc(sizeof(**root));
        (*root)->right->left = (*root)->right->right = NULL;
        (*root)->right->parent = *root;
        (*root)->right->val = val;
        (*root)->right->height = 0;
    }

    UpdateHeight(*root);
}

AVLNode* Find(AVLNode *root, int val)
{
    if (root == NULL || root->val == val) return root;

    if (val < root->val) return Find(root->left, val);
    return Find(root->right, val);
}

AVLNode* FindMinimum(AVLNode *root)
{
    if (root == NULL || root->left == NULL) return root;

    return FindMinimum(root->left);
}

AVLNode* FindSuccessor(AVLNode *target)
{
    if (target->right != NULL)
    {
        return FindMinimum(target);
    }

    AVLNode *parent = target->parent;
    
    while (parent != NULL && target == parent->right)
    {
        target = parent;
        parent = parent->parent;
    }

    return parent;
}

static void ShiftBtoA(AVLNode **root, AVLNode *a, AVLNode *b)
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

AVLNode* Delete(AVLNode *target)
{
    AVLNode *root = target;
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

    AVLNode *succ = FindSuccessor(target);
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

static void InOrderRecursive(AVLNode *cur)
{
    if (cur->left) InOrderRecursive(cur->left);
    printf("%d (%d), ", cur->val, cur->height);
    if (cur->right) InOrderRecursive(cur->right);
}

void PrintInOrder(AVLNode *root)
{
    printf("[ ");
    InOrderRecursive(root);
    printf(" ]\n");
}

void FreeAVL(AVLNode *root)
{
    if (root != NULL)
    {
        FreeAVL(root->left);
        FreeAVL(root->right);
        free(root);
    }
}