#include <stdio.h>
#include <stdlib.h>

int uaf() {
	int* p = (int*)malloc(16);
	free(p);

	int* q = (int*)malloc(16);
	printf("p = %p, q = %p\n", p, q);

	*p = 123;  // p�� q�� ������, q�� ������ �� �� ����
	printf("q = %d\n", q[0]);

	return 0;
}
