#ifndef CSUTILS

#define CSUTILS
#include <stdlib.h>

#define PrintList(list, n) {\
    int i; \
    printf("[ "); \
    for (i = 0; i < n; i++) \
        printf(i == n - 1 ? "%d" : "%d, ", list[i]); \
    printf(" ]\n"); \
}

#define Assert(name, x) {\
    if (!(x)) \
    { \
        printf("\x1B[33mAssertion: %s failed.\x1B[0m\n", name); \
        return 1; \
    } \
    else \
    { \
        printf("\x1B[32mAssertion: %s passed.\x1B[0m\n", name); \
    } \
}

#define ArraySwap(arr, a, b) {\
    if(a != b)\
    {\
        int temp = arr[a];\
        arr[a] = arr[b];\
        arr[b] = temp;\
    }\
}

#endif

#define signum(a) (a > 0 ? 1 : (a < 0 ? -1 : 0))

#define max(a, b) ((a) > (b) ? (a) : (b))

#define min(a, b) ((a) > (b) ? (b) : (a))