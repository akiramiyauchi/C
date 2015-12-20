/* 単純挿入ソート */

#include <stdio.h>
#include <stdlib.h>

/*--- 単純挿入ソート ---*/
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
	int *x;		/* 配列の先頭要素へのポインタ */

	puts("単純挿入ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* 要素数nxのint型配列を生成 */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);				/* 配列xを単純挿入ソート */

	puts("昇順にソートしました。");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* 配列を解放 */

	return 0;
}
