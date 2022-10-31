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
