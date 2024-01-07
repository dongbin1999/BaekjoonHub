#include <stdio.h>

int main(void)
{
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%.11lf", (double)A / B);

	return 0;
}