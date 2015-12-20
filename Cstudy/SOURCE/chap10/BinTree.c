/* �Q���T���؁i�\�[�X���j*/

/* ���K10-1�̊֐�PrintTreeReverse��
   ���K10-3�̊֐�GetMinNode,GetMaxNode��List10-2�ɒǉ� */

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- ��̃m�[�h�𓮓I�Ɋm�� ---*/
static BinNode *AllocBinNode(void)
{
	return calloc(1, sizeof(BinNode));
}

/*--- �m�[�h�̊e�����o�ɒl��ݒ� ----*/
static void SetBinNode(BinNode *n, const Member *x, const BinNode *left,
													const BinNode *right)
{
	n->data  = *x;			/* �f�[�^ */
	n->left  = left;		/* ���q�m�[�h�ւ̃|�C���^ */
	n->right = right;		/* �E�q�m�[�h�ւ̃|�C���^ */
}

/*--- �T�� ---*/
BinNode *Search(BinNode *p, const Member *x)
{
	int cond;

	if (p == NULL)
		return NULL;									/* �T�����s */
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p;										/* �T������ */
	else if (cond < 0)
		Search(p->left,  x);				/* �������؂���T�� */
	else
		Search(p->right, x);				/* �E�����؂���T�� */
}

/*--- �m�[�h��}�� ---*/
BinNode *Add(BinNode *p, const Member *x)
{
	int cond;

	if (p == NULL) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	} else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("�y�G���[�z%d�͊��ɓo�^����Ă��܂��B\n", x->no);
	else if (cond < 0)
		p->left  = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
}

/*--- �m�[�h���폜 ---*/
int Remove(BinNode **root, const Member *x)
{
	BinNode *next, *temp;
	BinNode **left;
	BinNode **p = root;

	while (1) {
		int cond;
		if (*p == NULL) {
			printf("�y�G���[�z%d�͓o�^����Ă��܂���B\n", x->no);
			return -1;		/* ���̃L�[�͑��݂��Ȃ� */
		} else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break;							/* �T������ */
		else if (cond < 0)
			p = &((*p)->left);				/* �������؂���T�� */
		else
			p = &((*p)->right);				/* �E�����؂���T�� */
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

/*--- �S�m�[�h�̃f�[�^��\�� ---*/
void PrintTree(const BinNode *p)
{
	if (p != NULL) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

/*--- �S�m�[�h�̍폜 ---*/
void FreeTree(BinNode *p)
{
	if (p != NULL) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}


/*--- �S�m�[�h���L�[�l�̍~���ɕ\�� ---*/
void PrintTreeReverse(const BinNode *p)
{
	if (p != NULL) {
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}

/*--- �ŏ��̃L�[�l�����m�[�h���擾 ---*/
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

/*--- �ő�̃L�[�l�����m�[�h���擾 ---*/
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
