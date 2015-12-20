/* クイックソート */

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- クイックソート（配列の分割過程を表示）---*/
void quick(int a[], int left, int right)
{
	int pl = left;				/* 左カーソル */
	int pr = right;				/* 右カーソル */
	int x = a[(pl + pr) / 2];	/* 枢軸（中央の要素）*/

	int i;
	printf("a[%d]～a[%d]：{", left, right);
	for (i = left; i < right; i++)
		printf("%d , ", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr)  quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

int main(void)
{
	int i, nx;
	int *x;		/* 配列の先頭要素へのポインタ */

	puts("クイックソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	quick(x, 0, nx - 1);	/* 配列xをクイックソート */

	puts("昇順にソートしました。");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* 配列を解放 */

	return 0;
}
