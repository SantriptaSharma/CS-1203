#define MAX_LAYERS 16

typedef struct __SkipNodeCanonical {
    int val, height;
    struct __SkipNodeCanonical *next[MAX_LAYERS];
} SkipNode;

typedef struct __SkipListCanonical {
    int maxHeight;
    SkipNode *head[MAX_LAYERS];
} SkipList;

SkipNode *__CreateSkipListNode(int val);
SkipList *CreateSkipList();
void PrintLevel(SkipList *list, int level);
void FreeSkipList(SkipList *list);

void SkipListInsert(SkipList *list, int val);
void SkipListBinarySearch(SkipList *list, int val);