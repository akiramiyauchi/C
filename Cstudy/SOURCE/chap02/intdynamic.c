/* 動的に生成した整数に値を代入して表示 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;

	x = calloc(1, sizeof(int));		/* int型用の記憶域を確保 */

	if (x == NULL)
		puts("記憶域の確保に失敗しました。");
	else {
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);					/* 記憶域を解放 */
	}

	return 0;
}
