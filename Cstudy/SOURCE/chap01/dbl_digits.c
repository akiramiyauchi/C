/* ２桁の正の整数値（10～99）を読み込む */

#include <stdio.h>

int main(void)
{
	int no;

	printf("２桁の整数値を入力してください。\n");

	do {
		printf("値は：");
		scanf("%d", &no);
	} while (no < 10 || no > 99);

	printf("変数noの値は%dになりました。\n", no);

	return 0;
}
