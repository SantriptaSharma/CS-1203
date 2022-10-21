typedef struct _NodeCanonical
{
    int value;
    struct _NodeCanonical *next;
} Node;

void Insert(Node **head, int value);
void PrintList(Node *head);
void PrintHalfList(Node *head);
int IsListLooping(Node *head);
void ReverseList(Node **head);
void ChunkReverseList(Node **head, int chunkSize);
Node* FindNode(Node *head, int value);
void FreeList(Node *head);