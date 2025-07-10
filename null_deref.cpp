#include <stdio.h>

volatile int* p = NULL;

int nd() {
    *p = 123;  // 강제로 주소 0번지에 쓰기 시도
    printf("이 메시지는 출력되지 않습니다.\n");
    return 0;
}

// cl null_deref.cpp