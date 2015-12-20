/* 文字列の比較（strncmp関数）*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char st[128];

	puts("\"STRING\"の先頭3文字と比較します。");
	puts("\"XXXX\"で終了します。");

	while (1) {
		printf("文字列st：");
		scanf("%s", st);

		if (strncmp("XXXX", st, 3) == 0)
			break;
		printf("strncmp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));
	}

	return 0;
}
