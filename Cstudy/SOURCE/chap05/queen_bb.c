/* 各行・各列に１個の王妃を配置する組合せを再帰的に列挙 */

#include <stdio.h>

int flag[8];		/* 各行に王妃が配置済みか */
int pos[8];			/* 各列の王妃の位置 */

/*--- 盤面（各列の王妃の位置）を出力 ---*/
void print(void)
{
	int i;

	for (i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

/*--- i列目の適当な位置に王妃を配置 ---*/
void set(int i)
{
	int j;

	for (j = 0; j < 8; j++) {
		if (!flag[j]) {		/* j行には王妃は未配置 */
			pos[i] = j;
			if (i == 7)		/* 全列に配置終了 */
				print();
			else {
				flag[j] = 1;
				set(i + 1);
				flag[j] = 0;
			}
		}
	}
}

int main(void)
{
	int i;

	for (i = 0; i < 8; i++)
		flag[i] = 0;

	set(0);

	return 0;
}
