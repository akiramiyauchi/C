/* 度数ソート */

#include <stdio.h>
#include <stdlib.h>

/*--- 度数ソート（配列要素の値は0以上max以下）---*/
void fsort(int a[], int n, int max)
{
	int i;
	int *f = calloc(max + 1, sizeof(int));		/* 累積度数 */
	int *b = calloc(n,       sizeof(int));		/* 作業用目的配列 */

	for (i = 0;		i <= max; i++) f[i] = 0;			  /* [Step0] */
	for (i = 0;		i < n;	  i++) f[a[i]]++;			  /* [Step1] */
	for (i = 1;		i <= max; i++) f[i] += f[i - 1];	  /* [Step2] */
	for (i = n - 1; i >= 0;	  i--) b[--f[a[i]]] = a[i];	  /* [Step3] */
	for (i = 0;		i < n;	  i++) a[i] = b[i];			  /* [Step4] */

	free(b);
	free(f);
}

int main(void)
{
	int i, nx;
	int *x;		/* 配列の先頭要素へのポインタ */
	const int max = 100;			/* 最大値 */

	puts("度数ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("0～%dの整数を入力せよ。\n", max);
	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}

	fsort(x, nx, max);		/* 配列xを度数ソート */

	puts("昇順にソートしました。");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* 配列を解放 */

	return 0;
}
