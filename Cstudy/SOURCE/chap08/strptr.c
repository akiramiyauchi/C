/* 文字列を表示（ポインタによる文字列）*/

#include <stdio.h>

int main(void)
{
	char *pt = "12345";

	printf("ポインタptは\"%s\"を指しています。\n", pt);

	return 0;
}
