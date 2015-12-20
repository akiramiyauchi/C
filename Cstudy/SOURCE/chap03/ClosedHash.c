/* オープンアドレス法によるハッシュ（ソース部：キーは氏名）*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ClosedHash.h"

/*--- ハッシュ関数（keyのハッシュ値を返す）---*/
static int hash(const char *key, int size)
{
	unsigned long h = 0;

	while (*key)
		h += *(key++);
	return h % size;
}

/*--- 再ハッシュ関数 ---*/
static int rehash(int key, int size)
{
	return (key + 1) % size;
}

/*--- ノードの各メンバに値を設定 ----*/
static void SetBucket(Bucket *n, const Member *x, Status stat)
{
	n->data = *x;		/* データ */
	n->stat = stat;		/* 要素の状態 */
}

/*--- ハッシュ表を初期化 ---*/
int Initialize(ClosedHash *h, int size)
{
	int i;

	if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (i = 0; i < size; i++)
		h->table[i].stat = Empty;
	return 1;
}

/*--- 探索 ---*/
Bucket *Search(const ClosedHash *h, const Member *x)
{
	int i;
	int key = hash(x->name, h->size);	/* 探索するデータのハッシュ値 */
	Bucket *p = &h->table[key];			/* 着目ノード */

	for (i = 0; p->stat != Empty && i < h->size; i++) {
		if (p->stat == Occupied && !strcmp(p->data.name, x->name))
			return p;
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return NULL;
}

/*--- データの追加 ---*/
int Add(ClosedHash *h, const Member *x)
{
	int i;
	int key = hash(x->name, h->size);		/* 追加するデータのハッシュ値 */
	Bucket *p = &h->table[key];			/* 着目ノード */

	if (Search(h, x))					/* このキーは登録済み */
		return 1;

	for (i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			SetBucket(p, x, Occupied);
			return 0;
		}
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return 2;							/* ハッシュ表が満杯 */
}

/*--- データの削除 ---*/
int Remove(ClosedHash *h, const Member *x)
{
	Bucket *p = Search(h, x);

	if (p == NULL)
		return 1;						/* そのキー値は存在しない */

	p->stat = Deleted;
	return 0;
}

/*--- ハッシュ表をダンプ ---*/
void Dump(const ClosedHash *h)
{
	int i;

	for (i = 0; i < h->size; i++) {
		printf("%02d : ", i);
		switch (h->table[i].stat) {
		 case Occupied : printf("%d (%s)\n",
								h->table[i].data.no, h->table[i].data.name);
						 break;

		 case Empty :	 printf("-- 未登録 --\n");	break;

		 case Deleted :	 printf("-- 削除済 --\n");	break;
		}
	}
}

/*--- 全データの削除 ---*/
void Clear(ClosedHash *h)
{
	int i;
	for (i = 0; i < h->size; i++)
		h->table[i].stat = Empty;
}

/*--- ハッシュ表を後始末 ---*/
void Terminate(ClosedHash *h)
{
	Clear(h);				/* 全データを削除 */
	free(h->table);			/* ハッシュ表用配列の記憶域を解放 */
	h->size = 0;			/* ハッシュ表の容量をクリア */
}
