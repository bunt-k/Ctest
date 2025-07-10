#include <stdio.h>
#include <stdlib.h>

int uaf() {
	int* p = (int*)malloc(16);
	free(p);

	int* q = (int*)malloc(16);
	printf("p = %p, q = %p\n", p, q);

	*p = 123;  // p와 q가 같으면, q에 영향을 줄 수 있음
	printf("q = %d\n", q[0]);

	return 0;
}
