typedef struct _BSTNodeCanonical
{
    int val;
    struct _BSTNodeCanonical *left, *right, *parent;
} BSTNode;

void Insert(BSTNode **root, int val);
BSTNode* Find(BSTNode *root, int val);
void PrintInOrder(BSTNode *root);
void Delete(BSTNode *target);
void FreeBST(BSTNode *root);