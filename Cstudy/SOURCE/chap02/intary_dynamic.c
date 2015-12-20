/* 配列を動的に生成 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int *a;	 /* 配列の先頭要素へのポインタ */
	int na;	 /* 配列aの要素数 */

	printf("要素数：");
	scanf("%d", &na);

	a = calloc(na, sizeof(int));	/* 要素数naのint型配列用の記憶域を確保 */

	if (a == NULL)
		puts("記憶域の確保に失敗しました。");
	else {
		printf("%d個の整数を入力してください。\n", na);
		for (i = 0; i < na; i++) {
			printf("a[%d] : ", i);
			scanf("%d", &a[i]);
		}

		printf("各要素の値は以下のとおりです。\n");
		for (i = 0; i < na; i++)
			printf("a[%d] = %d\n", i, a[i]);

		free(a);					/* 記憶域を解放 */
	}

	return 0;
}
