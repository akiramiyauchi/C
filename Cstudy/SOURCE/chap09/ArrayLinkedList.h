/* カーソルによる線形リスト（ヘッダ部）*/

/* 関数Purgeと関数RetrieveをList9-4に追加 */

#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#include "Member.h"

#define Null	-1			/* 空カーソル */

typedef int Index;			/* カーソル型 */

/*--- ノード ---*/
typedef struct {
	Member data;			/* データ */
	Index next;				/* 後続ノード */
	Index Dnext;			/* フリーリストの後続ノード */
} Node;

/*--- 線形リスト ---*/
typedef struct {
	Node  *n;				/* リスト本体（配列） */
	Index head;				/* 先頭ノード */
	Index max;				/* 利用中の末尾レコード */
	Index deleted;			/* フリーリストの先頭ノード */
	Index crnt;				/* 着目ノード */
} List;

/*--- 線形リストを初期化（最大要素数はsize）---*/
void Initialize(List *list, int size);

/*--- 関数compareによってxと一致すると判定されるノードを探索 ---*/
Index Search(List *list, const Member *x,
						 int compare(const Member *x, const Member *y));


/*--- 先頭からn個後ろのノードへのカーソルを取得 ---*/
Index Retrieve(List *list, int n);

/*--- 先頭にノードを挿入 ---*/
void InsertFront(List *list, const Member *x);

/*--- 末尾にノードを挿入 ---*/
void InsertRear(List *list, const Member *x);

/*--- 先頭ノードを削除 ---*/
void RemoveFront(List *list);

/*--- 末尾ノードを削除 ---*/
void RemoveRear(List *list);

/*--- 着目ノードを削除 ---*/
void RemoveCurrent(List *list);

/*--- 全ノードを削除 ---*/
void Clear(List *list);

/*--- 比較関数によって等しいとみなせるノードを削除 ---*/
void Purge(List *list, int compare(const Member *x, const Member *y));

/*--- 着目ノードのデータを表示 ---*/
void PrintCurrent(const List *list);

/*--- 着目ノードのデータを表示（改行付き）---*/
void PrintLnCurrent(const List *list);

/*--- 全ノードのデータを表示 ---*/
void Print(const List *list);

/*--- 線形リストの後始末 ---*/
void Terminate(List *list);

#endif
