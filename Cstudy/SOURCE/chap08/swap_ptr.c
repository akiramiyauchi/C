/* ポインタ値を交換する関数 */

#include <stdio.h>

/*--- 二つのポインタを交換 ---*/
void swap_ptr(char **x, char **y)
{
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(void)
{
	char *s1 = "ABCD";		/* s1は"ABCD"の先頭文字'A'を指す */
	char *s2 = "EFGH";		/* s2は"EFGH"の先頭文字'E'を指す */

	printf("ポインタs1は\"%s\"を指しています。\n", s1);
	printf("ポインタs2は\"%s\"を指しています。\n", s2);

	swap_ptr(&s1, &s2);

	puts("\nポインタs1とs2の値を交換しました。\n");

	printf("ポインタs1は\"%s\"を指しています。\n", s1);
	printf("ポインタs2は\"%s\"を指しています。\n", s2);

	return 0;
}
