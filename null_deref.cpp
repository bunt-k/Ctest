#include <stdio.h>

volatile int* p = NULL;

int nd() {
    *p = 123;  // ������ �ּ� 0������ ���� �õ�
    printf("�� �޽����� ��µ��� �ʽ��ϴ�.\n");
    return 0;
}

// cl null_deref.cpp