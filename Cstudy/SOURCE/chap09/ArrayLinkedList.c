/* カーソルによる線形リスト（ソース部）*/

/* 関数Purgeと関数RetrieveをList9-5に追加 */

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- 挿入するレコードのインデックスを求める ---*/
static Index GetIndex(List *list)
{
	if (list->deleted == Null)				/* 削除レコードがない場合 */
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

/*--- 指定したレコードを削除リストに登録する ---*/
static void DeleteIndex(List *list, Index idx)
{
	if (list->deleted == Null) {			/* 削除レコードがない場合 */
		list->deleted = idx;
		list->n[idx].Dnext = Null;
	} else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

/*--- nの指すノードの各メンバに値を設定 ----*/
static void SetNode(Node *n, const Member *x, Index next)
{
	n->data = *x;							/* データ */
	n->next = next;							/* 後続ノードへのポインタ */
}

/*--- 線形リストを初期化（最大要素数はsize）---*/
void Initialize(List *list, int size)
{
	list->n = calloc(size, sizeof(Node));
	list->head = Null;							/* 先頭ノード */
	list->crnt = Null;							/* 着目ノード */
	list->max = Null;
	list->deleted = Null;
}

/*--- 関数compareによってxと一致すると判定されるノードを探索 ---*/
Index Search(List *list, const Member *x,
						 int compare(const Member *x, const Member *y))
{
	Index ptr = list->head;

	while (ptr != Null) {
		if (compare(&list->n[ptr].data, x) == 0) {
			list->crnt = ptr;
			return ptr;				/* 探索成功 */
		}
		ptr = list->n[ptr].next;
	}
	return Null;						/* 探索失敗 */
}

/*--- 先頭からn個後ろのノードへのカーソルを取得 ---*/
Index Retrieve(List *list, int n)
{
	Index ptr = list->head;

	while (n >= 0  &&  ptr != Null) {
		if (n-- == 0) {
			list->crnt = ptr;
			return ptr;					/* 探索成功 */
		}
		ptr = list->n[ptr].next;		/* 後続ノードに着目 */
	}
	return Null;	
}

/*--- 先頭にノードを挿入 ---*/
void InsertFront(List *list, const Member *x)
{
	Index ptr = list->head;
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr);
}

/*--- 末尾にノードを挿入 ---*/
void InsertRear(List *list, const Member *x)
{
	if (list->head == Null)					/* 空であれば */
		InsertFront(list, x);				/* 先頭に挿入 */
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != Null)
			ptr = list->n[ptr].next;
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, Null);
	}
}

/*--- 先頭ノードを削除 ---*/
void RemoveFront(List *list)
{
	if (list->head != Null) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

/*--- 末尾ノードを削除 ---*/
void RemoveRear(List *list)
{
	if (list->head != Null) {
		if (list->n[list->head].next == Null)	/* ノードが一つだけであれば */
			RemoveFront(list);					/* 先頭ノードを削除 */
		else {
			Index ptr = list->head;
			Index pre;

			while (list->n[ptr].next != Null) {
				pre = ptr;
				ptr = list->n[ptr].next;
			}
			list->n[pre].next = Null;
			DeleteIndex(list, ptr);
			list->crnt = pre;
		}
	}
}

/*--- 着目ノードを削除 ---*/
void RemoveCurrent(List *list)
{
	if (list->head != Null) {
		if (list->crnt == list->head)		/* 先頭ノードに着目していれば */
			RemoveFront(list);				/* 先頭ノードを削除 */
		else {
			Index ptr = list->head;

			while (list->n[ptr].next != list->crnt)
				ptr = list->n[ptr].next;
			list->n[ptr].next = list->n[list->crnt].next;
			DeleteIndex(list, list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- 全ノードを削除 ---*/
void Clear(List *list)
{
	while (list->head != Null)			/* 空になるまで */
		RemoveFront(list);				/* 先頭ノードを削除 */
	list->crnt = Null;
}

/*--- 比較関数によって等しいとみなせるノードを削除 ---*/
void Purge(List *list, int compare(const Member *x, const Member *y))
{
	Index ptr = list->head;

	while (ptr != Null) {
		Index ptr2 = ptr;
		Index pre = ptr;

		while (list->n[ptr2].next != Null) {
			ptr2 = list->n[pre].next;
			if (!compare(&list->n[ptr].data, &list->n[ptr2].data)) {
				list->n[pre].next = list->n[ptr2].next;
				DeleteIndex(list, ptr2);
			} else {
				pre = ptr2;
			}
		}
		ptr = list->n[ptr].next;
	}
	list->crnt = list->head;
}

/*--- 着目ノードのデータを表示 ---*/
void PrintCurrent(const List *list)
{
	if (list->crnt == Null)
		printf("着目要素はありません。");
	else
		PrintMember(&list->n[list->crnt].data);
}

/*--- 着目ノードのデータを表示（改行付き）---*/
void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 全ノードのデータを表示 ---*/
void Print(const List *list)
{
	if (list->head == Null)
		puts("ノードがありません。");
	else {
		Index ptr = list->head;

		puts("【一覧表】");
		while (ptr != Null) {
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;		/* 後続ノード */
		}
	}
}

/*--- 線形リストの後始末 ---*/
void Terminate(List *list)
{
	Clear(list);					/* 全ノードを削除 */
	free(list->n);
}
