/* ヒープソート */

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- a[left]～a[right]をヒープ化 ---*/
static void downheap(int a[], int left, int right)
{
	int temp = a[left];				/* 根 */
	int child;
	int parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;		/* 左の子 */
		int cr = cl + 1;				/* 右の子 */
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;	/* 大きいほう */
		if (temp >= a[child])
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

/*--- ヒープソート ---*/
void heapsort(int a[], int n)
{
	int i;

	for (i = (n - 1) / 2; i >= 0; i--)
		downheap(a, i, n - 1);

	for (i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);
		downheap(a, 0, i - 1);
	}
}

int main(void)
{
	int i, nx;
	int *x;		/* 配列の先頭要素へのポインタ */

	puts("ヒープソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	heapsort(x, nx);	/* 配列xをヒープソート */

	puts("昇順にソートしました。");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* 配列を解放 */

	return 0;
}
