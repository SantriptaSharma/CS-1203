#include <stdio.h>
#include "bst.h"

#define Assert(name, x) \
    if (!(x)) \
    { \
        printf("\x1B[33mAssertion: %s failed.\x1B[0m\n", name); \
        return 1; \
    } \
    else \
    { \
        printf("\x1B[32mAssertion: %s passed.\x1B[0m\n", name); \
    }

int main()
{
    BSTNode *root = NULL;
    Insert(&root, 5);
    Insert(&root, 3);
    Insert(&root, 7);
    Insert(&root, 1);
    Insert(&root, 4);
    Insert(&root, 6);
    Insert(&root, 8);

    int a = root->val;
    Assert("Expect 5 at root", a == 5);
    a = root->left->left->val;
    Assert("Expect 1 at root->left->left", a == 1);
    a = root->right->left->val;
    Assert("Expect 6 at root->right->left", a == 6);

    FreeBST(root);

    a = root->val;
    Assert("Expect garbage at root", a != 5);

    return 0;
}