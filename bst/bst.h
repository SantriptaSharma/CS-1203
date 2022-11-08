typedef struct _BSTNodeCanonical
{
    int val;
    struct _BSTNodeCanonical *left, *right;
} BSTNode;

void Insert(BSTNode **root, int val);
// TODO: Implement find, inorder, preorder, postorder
BSTNode* Find(BSTNode *root, int val);
void PrintInOrder(BSTNode *root);
void Delete(BSTNode **root, int val);
void FreeBST(BSTNode *root);