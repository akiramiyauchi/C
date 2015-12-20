/* 再帰に対する理解を深めるための真に再帰的な関数 */

#include <stdio.h>
#include "IntStack.h"

/*--- 関数recur（再帰を除去）---*/
void recur(int n)
{
	IntStack stk;				/* スタック */
	Initialize(&stk, 100);
Top:
	if (n > 0) {
		Push(&stk, n);			/* nの値をプッシュ */
		n = n - 1;
		goto Top;
	}

	if (!IsEmpty(&stk)) {		/* スタックが空でなければ */
		Pop(&stk, &n);			/* 値を保存していたnをポップ */
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
	Terminate(&stk);
}

int main(void)
{
	int x;

	printf("整数を入力せよ：");
	scanf("%d", &x);

	recur(x);

	return 0;
}
