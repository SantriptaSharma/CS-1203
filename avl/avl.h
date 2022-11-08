//TODO: write rotations, rebalancing, insertion, searches, remove etc.
typedef struct _AVLCanonical
{
    int val, height;
    struct _AVLCanonical *left, *right, *parent;
} AVLNode;

void Insert(AVLNode **root, int val);
AVLNode* Find(AVLNode *root, int val);
AVLNode* FindMinimum(AVLNode *root);
AVLNode* FindSuccessor(AVLNode *target);
AVLNode* Delete(AVLNode *target);
void PrintInOrder(AVLNode *root);
void FreeBST(AVLNode *root);