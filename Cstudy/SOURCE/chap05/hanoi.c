/* ハノイの塔 */

#include <stdio.h>

/*--- 円盤[1]～円盤[no]をx軸からy軸へ移動 ---*/
void move(int no, int x, int y)
{
	if (no > 1)
		move(no - 1, x, 6 - x - y);		/* グループを開始軸から中間軸へ */

	printf("円盤[%d]を%d軸から%d軸へ移動\n", no, x, y);	/* 底を目的軸へ */

	if (no > 1)
		move(no - 1, 6 - x - y, y);		/* グループを中間軸から目的軸へ */
}

int main(void)
{
	int n;		/* 円盤の枚数 */

	printf("ハノイの塔\n円盤の枚数：");
	scanf("%d", &n);

	move(n, 1, 3);

	return 0;
}
