#include <stdio.h>

int f(int n) {
	if (n < 2) {
		return n;
	}
	return n*f(n - 1);
}

int main() {
	int number = 0;
	puts("enter number");
	scanf_s("%i", &number);
	printf("%i", f(number));
	getchar();
	getchar();
	return 0;
}