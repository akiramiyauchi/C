/* 整数を2進数～36進数に基数変換 */

#include <stdio.h>

/*--- 整数値xをn進数に変換して配列dに下位桁から格納 ---*/
int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int  digits = 0;						/* 変換後の桁数 */

	if (x == 0)								/* 0であれば */
		d[digits++] = dchar[0];				/* 変換後も0 */
	else
		while (x) {
			d[digits++] = dchar[x % n];		/* nで割った剰余を格納 */
			x /= n;
		}
	return digits;
}

int main(void)
{
	int      i;
	unsigned no;		/* 変換する整数 */
	int      cd;		/* 基数 */
	int      dno;		/* 変換後の桁数 */
	char     cno[512];	/* 変換後の数値の各桁の数字を格納する文字の配列 */
	int      retry;		/* もう一度？ */

	puts("10進数を基数変換します。");

	do {
		printf("変換する非負の整数：");
		scanf("%u", &no);

		do {
			printf("何進数に変換しますか（2-36）：");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_convr(no, cd, cno);		/* noをcd進数に変換 */

		printf("%d進数では", cd);
		for (i = dno - 1; i >= 0; i--)		/* 上位桁から順に表示 */
			printf("%c", cno[i]);
		printf("です。\n");

		printf("もう一度しますか（1…はい／0…いいえ）：");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
