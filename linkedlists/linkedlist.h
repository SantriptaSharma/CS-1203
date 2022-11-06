typedef struct _NodeCanonical
{
    int value;
    struct _NodeCanonical *next;
} Node;

void Insert(Node **head, int value);
void InsertSorted(Node **head, Node *new);
void PrintList(Node *head);
void PrintHalfList(Node *head);
int IsListLooping(Node *head);
void FreeList(Node *head);
void ReverseList(Node **head);
void ChunkReverseList(Node **head, int chunkSize);
void SelectionSort(Node **head);
void InsertionSort(Node **head);
void QuickSort(Node **head, int n);