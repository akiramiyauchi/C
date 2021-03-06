/* 循環・重連結リスト（ソース部）*/

/* 関数Purgeと関数RetrieveをList9-8に追加 */

#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

/*--- 一つのノードを動的に生成 ---*/
static Dnode *AllocDnode(void)
{
	return calloc(1, sizeof(Dnode));
}

/*--- ノードの各メンバに値を設定 ----*/
static void SetDnode(Dnode *n, const Member *x, const Dnode *prev,
												const Dnode *next)
{
	n->data = *x;		/* データ */
	n->prev = prev;		/* 先行ノードへのポインタ */
	n->next = next;		/* 後続ノードへのポインタ */
}

/*--- リストは空か ---*/
static int IsEmpty(const Dlist *list)
{
	return list->head->next == list->head;
}

/*--- リストを初期化 ---*/
void Initialize(Dlist *list)
{
	Dnode *dummyNode = AllocDnode();			/* ダミーノードを生成 */
	list->head = list->crnt = dummyNode;
	dummyNode->prev = dummyNode->next = dummyNode;
}

/*--- 着目ノードのデータを表示 ---*/
void PrintCurrent(const Dlist *list)
{
	if (IsEmpty(list))
		printf("着目要素はありません。");
	else
		PrintMember(&list->crnt->data);
}

/*--- 着目ノードのデータを表示（改行付き）---*/
void PrintLnCurrent(const Dlist *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 関数compareによってxと一致すると判定されるノードを探索 ---*/
Dnode *Search(Dlist *list, const Member *x,
						   int compare(const Member *x, const Member *y))
{
	Dnode *ptr = list->head->next;

	while (ptr != list->head) {
		if (compare(&ptr->data, x) == 0) {
			list->crnt = ptr;
			return ptr;					/* 探索成功 */
		}
		ptr = ptr->next;
	}
	return NULL;						/* 探索失敗 */
}

/*--- 先頭からn個後ろのノードへのポインタを取得 ---*/
Dnode *Retrieve(Dlist *list, int n)
{
	Dnode *ptr = list->head->next;

	while (n >= 0 && ptr != list->head) {
		if (n-- == 0) {
			list->crnt = ptr;
			return ptr;				/* 探索成功 */
		}
		ptr = ptr->next;			/* 後続ノードに着目 */
	}
	return NULL;					/* 探索失敗 */
}

/*--- 全ノードのデータをリスト順に表示 ---*/
void Print(const Dlist *list)
{
	if (IsEmpty(list))
		puts("ノードがありません。");
	else {
		Dnode *ptr = list->head->next;

		puts("【一覧表】");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;			/* 後続ノードに着目 */
		}
	}
}

/*--- 全ノードのデータをリストの逆順に表示 ---*/
void PrintReverse(const Dlist *list)
{
	if (IsEmpty(list))
		puts("ノードがありません。");
	else {
		Dnode *ptr = list->head->prev;

		puts("【一覧表】");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;			/* 先行ノードに着目 */
		}
	}
}

/*--- 着目ノードを一つ後方に進める ---*/
int Next(Dlist *list)
{
	if (IsEmpty(list) || list->crnt->next == list->head)
		return 0;						/* 進めることはできない */
	list->crnt = list->crnt->next;
	return 1;
}

/*--- 着目ノードを一つ前方に戻す ---*/
int Prev(Dlist *list)
{
	if (IsEmpty(list) || list->crnt->prev == list->head)
		return 0;						/* 戻すことはできない */
	list->crnt = list->crnt->prev;
	return 1;
}

/*--- pが指すノードの直後にノードを挿入 ---*/
void InsertAfter(Dlist *list, Dnode *p, const Member *x)
{
	Dnode *ptr = AllocDnode();
	Dnode *nxt = p->next;

	p->next = p->next->prev = ptr;
	SetDnode(ptr, x, p, nxt);
	list->crnt = ptr;						/* 挿入したノードに着目 */
}

/*--- 先頭にノードを挿入 ---*/
void InsertFront(Dlist *list, const Member *x)
{
	InsertAfter(list, list->head, x);
}

/*--- 末尾にノードを挿入 ---*/
void InsertRear(Dlist *list, const Member *x)
{
	InsertAfter(list, list->head->prev, x);
}

/*--- pが指すノードを削除 ---*/
void Remove(Dlist *list, Dnode *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;		/* 削除したノードの先行ノードに着目 */
	free(p);
	if (list->crnt == list->head)
		list->crnt = list->head->next;
}

/*--- 先頭ノードを削除 ---*/
void RemoveFront(Dlist *list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->next);
}

/*--- 末尾ノードを削除 ---*/
void RemoveRear(Dlist *list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->prev);
}

/*--- 着目ノードを削除 ---*/
void RemoveCurrent(Dlist *list)
{
	if (list->crnt != list->head)
		Remove(list, list->crnt);
}

/*--- 全ノードを削除 ---*/
void Clear(Dlist *list)
{
	while (!IsEmpty(list))			/* 空になるまで */
		RemoveFront(list);			/* 先頭ノードを削除 */
}

/*--- 比較関数によって等しいとみなせるノードを削除 ---*/
void Purge(Dlist *list, int compare(const Member *x, const Member *y))
{
	Dnode *ptr = list->head->next;

	while (ptr != list->head) {
		Dnode *ptr2 = ptr;
		Dnode *pre = ptr;

		while (pre->next != list->head) {
			ptr2 = pre->next;
			if (!compare(&ptr->data, &ptr2->data)) {
				pre->next = ptr2->next;
				free(ptr2);
			} else {
				pre = ptr2;
			}
		}
		ptr = ptr->next;
	}
	list->crnt = list->head;
}

/*--- 循環・重連結リストを後始末 ---*/
void Terminate(Dlist *list)
{
	Clear(list);					/* 全ノードを削除 */
	free(list->head);				/* ダミーノードを削除 */
}
