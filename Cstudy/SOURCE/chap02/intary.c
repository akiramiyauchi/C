/* 要素型がint型で要素数が5の配列 */

#include <stdio.h>

#define N 5						/* 配列の要素数 */

int main()
{
	int i;
	int a[N];					/* 配列の宣言 */

	for (i = 0; i < N; i++) {	/* 各要素に値を読み込む */
		printf("a[%d] : ", i);
		scanf("%d", &a[i]);
	}

	puts("各要素の値");
	for (i = 0; i < N; i++) {	/* 各要素の値を表示 */
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}
