/* ２分探索木の利用例 */

/* 演習10-1の関数PrintTreeReverseと
   演習10-3の関数GetMinNode,GetMaxNodeのテストをList10-3に追加 */

#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- メニュー ---*/
typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT, PRINT_REV, GET_MIN, GET_MAX
} Menu;

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n(1)挿入 (2)削除 (3)探索 (4)表示 (5)逆順表示 (6)最小 (7)最大 (0)終了：");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > GET_MAX);
	return (Menu)ch;
}

/*--- メイン関数 ---*/
int main(void)
{
	Menu    menu;
	BinNode *root = NULL;		/* ２分探索木の根へのポインタ */

	do {
		Member x;
		BinNode *temp;

		switch (menu = SelectMenu()) {
		 /*--- ノードの挿入 ---*/
		 case ADD :
				x = ScanMember("挿入", MEMBER_NO | MEMBER_NAME);
				root = Add(root, &x);
				break;

		 /*--- ノードの削除 ---*/
		 case REMOVE :
				x = ScanMember("削除", MEMBER_NO);
				Remove(&root, &x);
				break;

		 /*--- ノードの探索 ---*/
		 case SEARCH :
				x = ScanMember("探索", MEMBER_NO);
				if ((temp = Search(root, &x)) != NULL)
					PrintLnMember(&temp->data);
				break;

		 /*--- 全ノードの表示 ---*/
		 case PRINT :
				puts("【一覧表】");
				PrintTree(root);
				break;
		
		/*--- 全ノードの逆順表示 ---*/
		 case PRINT_REV :
				puts("【逆順一覧表】");
				PrintTreeReverse(root);
				break;

		/*--- 最小キー値 ---*/
		 case GET_MIN :
				if ((temp = GetMinNode(root)) != NULL)
					PrintLnMember(&temp->data);
				break;

		/*--- 最大きいキー値 ---*/
		 case GET_MAX :
				if ((temp = GetMaxNode(root)) != NULL)
					PrintLnMember(&temp->data);
				break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}
