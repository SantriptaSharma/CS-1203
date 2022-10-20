typedef struct _NodeCanonical
{
    int value;
    struct _NodeCanonical *next;
} Node;

void Insert(Node **head, int value);
void PrintList(Node *head);
void PrintHalfList(Node *head);
int IsListLooping(Node *head);
void FreeList(Node *head);
void ReverseList(Node **head);
Node* FindNode(Node *head, int value);