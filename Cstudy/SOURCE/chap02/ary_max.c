/* 配列の要素の最大値を求める（値を読み込む）*/

#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aの要素の最大値を求める ---*/
int maxof(const int a[], int n)
{
	int i;
	int max = a[0];				/* 最大値 */

	for (i = 1; i < n; i++)
		if (a[i] > max) max = a[i];

	return max;
}

int main(void)
{
	int i;
	int *height;		/* 配列の先頭要素へのポインタ */
	int number;			/* 人数＝配列heightの要素数 */

	printf("人数 : ");
	scanf("%d", &number);

	height = calloc(number, sizeof(int));	/* 要素数numberの配列を生成 */

	printf("%d人の身長を入力してください。\n", number);
	for (i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf("%d", &height[i]);
	}

	printf("最大値は%dです。\n", maxof(height, number));

	free(height);		/* 配列heightを解放 */

	return 0;
}
