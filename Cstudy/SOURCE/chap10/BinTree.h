/* ２分探索木（ヘッダ部）*/

#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

/*--- ノード ---*/
typedef struct __bnode {
	Member           data;		/* データ */
	struct __bnode *left;		/* 左子ノードへのポインタ */
	struct __bnode *right;		/* 右子ノードへのポインタ */
} BinNode;

/*--- 探索 ---*/
BinNode *Search(BinNode *p, const Member *x);

/*--- ノードの挿入 ---*/
BinNode *Add(BinNode *p, const Member *x);

/*--- ノードの削除 ---*/
int Remove(BinNode **root, const Member *x);

/*--- 全ノードの表示 ---*/
void PrintTree(const BinNode *p);

/*--- 全ノードの削除 ---*/
void FreeTree(BinNode *p);

#endif