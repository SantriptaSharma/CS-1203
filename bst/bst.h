typedef struct _BSTNodeCanonical
{
    int val;
    struct _BSTNodeCanonical *left, *right;
} BSTNode;

void Insert(BSTNode **root, int val);
void FreeBST(BSTNode *root);