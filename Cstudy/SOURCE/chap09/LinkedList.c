/* ポインタによる線形リスト（ソース部） */

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/*--- 一つのノードを動的に生成 ---*/
static Node *AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/*--- nの指すノードの各メンバに値を設定 ----*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
	n->data = *x;		/* データ */
	n->next = next;		/* 後続ポインタ */
}

/*--- 線形リストを初期化 ---*/
void Initialize(List *list)
{
	list->head = NULL;		/* 先頭ノード */
	list->crnt = NULL;		/* 着目ノード */
}

/*--- 関数compareによってxと一致すると判定されるノードを探索 ---*/
Node *Search(List *list, const Member *x,
						 int compare(const Member *x, const Member *y))
{
	Node *ptr = list->head;

	while (ptr != NULL) {
		if (compare(&ptr->data, x) == 0) {	/* キー値が一致 */
			list->crnt = ptr;
			return ptr;					/* 探索成功 */
		}
		ptr = ptr->next;				/* 後続ノードに着目 */
	}
	return NULL;						/* 探索失敗 */
}

/*--- 先頭にノードを挿入 ---*/
void InsertFront(List *list, const Member *x)
{
	Node *ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr);
}

/*--- 末尾にノードを挿入 ---*/
void InsertRear(List *list, const Member *x)
{
	if (list->head == NULL)					/* 空であれば */
		InsertFront(list, x);				/* 先頭に挿入 */
	else {
		Node *ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

/*--- 先頭ノードを削除 ---*/
void RemoveFront(List *list)
{
	if (list->head != NULL) {
		Node *ptr = list->head->next;		/* ２番目のノードへのポインタ */
		free(list->head);					/* 先頭ノードを解放 */
		list->head = list->crnt = ptr;		/* 新しい先頭ノード */
	}
}

/*--- 末尾ノードを削除 ---*/
void RemoveRear(List *list)
{
	if (list->head != NULL) {
		if ((list->head)->next == NULL)		/* ノードが一つだけであれば */
			RemoveFront(list);				/* 先頭ノードを削除 */
		else {
			Node *ptr = list->head;
			Node *pre;

			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}
			pre->next = NULL;				/* preは末尾から2番目 */
			free(ptr);						/* ptrは末尾 */
			list->crnt = pre;
		}
	}
}

/*--- 着目ノードを削除 ---*/
void RemoveCurrent(List *list)
{
	if (list->head != NULL) {
		if (list->crnt == list->head)	/* 先頭ノードに着目していれば */
			RemoveFront(list);			/* 先頭ノードを削除 */
		else {
			Node *ptr = list->head;

			while (ptr->next != list->crnt)
				ptr = ptr->next;
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- 全ノードを削除 ---*/
void Clear(List *list)
{
	while (list->head != NULL)			/* 空になるまで */
		RemoveFront(list);				/* 先頭ノードを削除 */
	list->crnt = NULL;
}

/*--- 着目ノードのデータを表示 ---*/
void PrintCurrent(const List *list)
{
	if (list->crnt == NULL)
		printf("着目ノードはありません。");
	else
		PrintMember(&list->crnt->data);
}

/*--- 着目ノードのデータを表示（改行付き）---*/
void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 全ノードのデータをリスト順に表示 ---*/
void Print(const List *list)
{
	if (list->head == NULL)
		puts("ノードがありません。");
	else {
		Node *ptr = list->head;

		puts("【一覧表】");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;				/* 後続ノードに着目 */
		}
	}
}

/*--- 線形リストの後始末 ---*/
void Terminate(List *list)
{
	Clear(list);						/* 全ノードを削除 */
}
