/* P}ό\[g */

#include <stdio.h>
#include <stdlib.h>

/*--- P}ό\[g ---*/
void insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void)
{
	int i, nx;
	int *x;		/* zρΜζͺvfΦΜ|C^ */

	puts("P}ό\[g");
	printf("vf : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* vfnxΜint^zρπΆ¬ */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);				/* zρxπP}ό\[g */

	puts("ΈΙ\[g΅ά΅½B");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* zρππϊ */

	return 0;
}
