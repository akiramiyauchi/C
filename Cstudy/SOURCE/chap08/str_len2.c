/* 文字列の長さを求める */

#include <stdio.h>

/*--- 文字列sの長さを求める（その２）---*/
int str_len(const char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return len;
}

int main(void)
{
	char str[256];

	printf("文字列：");
	scanf("%s", str);

	printf("その文字列は%d文字です。\n", str_len(str));

	return 0;
}
