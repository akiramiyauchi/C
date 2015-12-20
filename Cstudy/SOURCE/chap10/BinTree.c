/* ２分探索木（ソース部）*/

/* 演習10-1の関数PrintTreeReverseと
   演習10-3の関数GetMinNode,GetMaxNodeをList10-2に追加 */

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- 一つのノードを動的に確保 ---*/
static BinNode *AllocBinNode(void)
{
	return calloc(1, sizeof(BinNode));
}

/*--- ノードの各メンバに値を設定 ----*/
static void SetBinNode(BinNode *n, const Member *x, const BinNode *left,
													const BinNode *right)
{
	n->data  = *x;			/* データ */
	n->left  = left;		/* 左子ノードへのポインタ */
	n->right = right;		/* 右子ノードへのポインタ */
}

/*--- 探索 ---*/
BinNode *Search(BinNode *p, const Member *x)
{
	int cond;

	if (p == NULL)
		return NULL;									/* 探索失敗 */
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p;										/* 探索成功 */
	else if (cond < 0)
		Search(p->left,  x);				/* 左部分木から探索 */
	else
		Search(p->right, x);				/* 右部分木から探索 */
}

/*--- ノードを挿入 ---*/
BinNode *Add(BinNode *p, const Member *x)
{
	int cond;

	if (p == NULL) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	} else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("【エラー】%dは既に登録されています。\n", x->no);
	else if (cond < 0)
		p->left  = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
}

/*--- ノードを削除 ---*/
int Remove(BinNode **root, const Member *x)
{
	BinNode *next, *temp;
	BinNode **left;
	BinNode **p = root;

	while (1) {
		int cond;
		if (*p == NULL) {
			printf("【エラー】%dは登録されていません。\n", x->no);
			return -1;		/* そのキーは存在しない */
		} else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break;							/* 探索成功 */
		else if (cond < 0)
			p = &((*p)->left);				/* 左部分木から探索 */
		else
			p = &((*p)->right);				/* 右部分木から探索 */
	}
	if ((*p)->left == NULL)
		next = (*p)->right;
	else {
		left = &((*p)->left);
		while ((*left)->right != NULL)
			left = &(*left)->right;
		next = *left;
		*left = (*left)->left;
		next->left  = (*p)->left;
		next->right = (*p)->right;
	}
	temp = *p;
	*p = next;
	free(temp);

	return 0;
}

/*--- 全ノードのデータを表示 ---*/
void PrintTree(const BinNode *p)
{
	if (p != NULL) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

/*--- 全ノードの削除 ---*/
void FreeTree(BinNode *p)
{
	if (p != NULL) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}


/*--- 全ノードをキー値の降順に表示 ---*/
void PrintTreeReverse(const BinNode *p)
{
	if (p != NULL) {
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}

/*--- 最小のキー値をもつノードを取得 ---*/
BinNode *GetMinNode(const BinNode *p)
{
	if (p == NULL)
		return NULL;
	else {
		while (p->left != NULL)
			p = p->left;
		return p;
	}
}

/*--- 最大のキー値をもつノードを取得 ---*/
BinNode *GetMaxNode(const BinNode *p)
{
	if (p == NULL)
		return NULL;
	else {
		while (p->right != NULL)
			p = p->right;
		return p;
	}
}
