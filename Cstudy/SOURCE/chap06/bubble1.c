/* Pπ·\[g */

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- Pπ·\[g ---*/
void bubble(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
}

int main(void)
{
	int i, nx;
	int *x;		/* zρΜζͺvfΦΜ|C^ */

	puts("Pπ·\[g");
	printf("vf : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* vfnxΜint^zρπΆ¬ */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);					/* zρxπPπ·\[g */

	puts("ΈΙ\[g΅ά΅½B");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* zρππϊ */

	return 0;
}
