/* ２分探索 */

#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aからkeyと一致する要素を２分探索 ---*/
int bin_search(const int a[], int n, int key)
{
	int pl = 0;			/* 探索範囲先頭の添字 */
	int pr = n - 1;		/* 　 〃 　末尾の添字 */
	int pc;				/* 　 〃 　中央の添字 */

	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key)		/* 探索成功 */
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while (pl <= pr);

	return -1;					/* 探索失敗 */
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;		/* 配列の先頭要素へのポインタ */

	puts("２分探索");
	printf("要素数 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* 要素数nxのint型配列を生成 */

	printf("昇順に入力してください。\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);	/* 一つ前の値よりも小さければ再入力 */
	}
	printf("探す値 : ");
	scanf("%d", &ky);

	idx = bin_search(x, nx, ky);	/* 配列xから値がkyである要素を２分探索 */

	if (idx == -1)
		puts("探索に失敗しました。");
	else
		printf("%dはx[%d]にあります。\n", ky, idx);

	free(x);	/* 配列を解放 */

	return 0;
}
