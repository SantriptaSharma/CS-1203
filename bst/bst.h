typedef struct _BSTNodeCanonical
{
    int val;
    struct _BSTNodeCanonical *left, *right, *parent;
} BSTNode;

void Insert(BSTNode **root, int val);
BSTNode* Find(BSTNode *root, int val);
BSTNode* FindMinimum(BSTNode *root);
BSTNode* FindSuccessor(BSTNode *target);
BSTNode* Delete(BSTNode *target);
void PrintInOrder(BSTNode *root);
void FreeBST(BSTNode *root);