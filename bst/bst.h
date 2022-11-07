typedef struct _BSTNodeCanonical
{
    int val;
    struct _BSTNodeCanonical *left, *right;
    //TODO: Implement Parent, height (0 at leaf), and modify things
} BSTNode;

void Insert(BSTNode **root, int val);
// TODO: Implement
BSTNode* Find(BSTNode *root, int val);
void Delete(BSTNode **root, int val);
void FreeBST(BSTNode *root);