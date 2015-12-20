/* �Q���T���؁i�w�b�_���j*/

#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

/*--- �m�[�h ---*/
typedef struct __bnode {
	Member           data;		/* �f�[�^ */
	struct __bnode *left;		/* ���q�m�[�h�ւ̃|�C���^ */
	struct __bnode *right;		/* �E�q�m�[�h�ւ̃|�C���^ */
} BinNode;

/*--- �T�� ---*/
BinNode *Search(BinNode *p, const Member *x);

/*--- �m�[�h�̑}�� ---*/
BinNode *Add(BinNode *p, const Member *x);

/*--- �m�[�h�̍폜 ---*/
int Remove(BinNode **root, const Member *x);

/*--- �S�m�[�h�̕\�� ---*/
void PrintTree(const BinNode *p);

/*--- �S�m�[�h�̍폜 ---*/
void FreeTree(BinNode *p);

#endif