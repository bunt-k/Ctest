#include <stdio.h>

void test() {
    int secret = 123456;
    int A[] = { 1, 2, 3, 4, 5, 6, 7 };

    printf("Address of secret : %p\n", &secret);
    printf("Address of A[0]   : %p\n", &A[0]);
    printf("Address of A[-1]  : %p\n", &A[-1]);

    printf("\nA[0] = %d\n", A[0]);
    printf("A[-1] = %d  // undefined behavior\n", A[-1]);

    A[-1] = 777;  // 실제로 secret을 덮을 수 있음

    printf("\nAfter A[-1] = 777\n");
    printf("secret = %d\n", secret);
}

int ngt() {
    test();
    return 0;
}
