/* int型キューIntQueueの利用例 */

#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("キューの生成に失敗しました。");
		return 1;
	}

	while (1) {
		int m, x;
		int idx;

		printf("現在のデータ数：%d / %d\n", Size(&que), Capacity(&que));
		printf("(1)エンキュー (2)デキュー (3)ピーク (4)表示 5)探索 6)クリア 7)空/満杯 (0)終了:");
		scanf("%d", &m);

		if (m == 0) break;

		switch (m) {
		 case 1: /*--- エンキュー ---*/
				 printf("データ：");   scanf("%d", &x);
				 if (Enque(&que, x) == -1)
					puts("\aエラー：エンキューに失敗しました。");
				 break;

		 case 2: /*--- デキュー ---*/
				 if (Deque(&que, &x) == -1)
					puts("\aエラー：デキューに失敗しました。");
				 else
					printf("デキューしたデータは%dです。\n", x);
				 break;

		 case 3: /*--- ピーク ---*/
				 if (Peek(&que, &x) == -1)
					puts("\aエラー：ピークに失敗しました。");
				 else
					printf("ピークしたデータは%dです。\n", x);
				 break;

		 case 4: /*--- 表示 ---*/
				 Print(&que);
				 break;

		 case 5: /*--- 探索 ---*/
				 printf("探索するデータ：");
				 scanf("%d", &x);
				 if ((idx = Search(&que, x)) == -1)
					puts("\aエラ－：探索に失敗しました。");
				 else {
					 printf("そのデータは添字%dの位置にあります。\n", idx);
					 printf("キューの先頭要素から%d個後ろの位置です。\n", Search2(&que, x));
				 }
				 break;

		 case 6: /*--- クリア ---*/
				 Clear(&que);
				 break;

		 case 7: /*--- 空／満杯の判定 ---*/
				 printf("スタックは空%s。\n",   IsEmpty(&que) ? "です" : "ではありません");
				 printf("スタックは満杯%s。\n", IsFull(&que)  ? "です" : "ではありません");
				 break;
		}
	}

	Terminate(&que);

	return 0;
}
