#include <stdlib.h>
#include <stdio.h>

void foo(int **const p) {
	int j = 11;
	*p = &j;
	printf("%d ", **p);
}

int main() { 
	int i = 0;
	int *p = &i;
	printf("%d", i);
	{
		int i = 5;
	}
	printf("%d", i);
	printf("%d ", *p);
	//(&p);
	printf("%d ", *p);
	printf("%d ", *p);
	getchar();
	return 0;
}