/* �`�F�C���@�ɂ��n�b�V���i�\�[�X���F�L�[�͎����j*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ChainHash.h"

/*--- �n�b�V���֐��ikey�̃n�b�V���l��Ԃ��j---*/
static int hash(const char *key, int size)
{
	unsigned long h = 0;

	while (*key)
		h += *(key++);
	return h % size;
}

/*--- �m�[�h�̊e�����o�ɒl��ݒ� ----*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
	n->data = *x;		/* �f�[�^ */
	n->next = next;		/* �㑱�m�[�h�ւ̃|�C���^ */
}

/*--- �n�b�V���\�̏����� ---*/
int Initialize(ChainHash *h, int size)
{
	int i;

	if ((h->table = calloc(size, sizeof(Node *))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (i = 0; i < size; i++)
		h->table[i] = NULL;

	return 1;
}

/*--- �T�� ---*/
Node *Search(const ChainHash *h, const Member *x)
{
	int key = hash(x->name, h->size);		/* �T������f�[�^�̃n�b�V���l */
	Node *p = h->table[key];			/* ���ڃm�[�h */

	while (p != NULL) {
		if (!strcmp(p->data.name, x->name))		/* �T������ */
			return p;
		p = p->next;					/* �㑱�m�[�h�ɒ��� */
	}
	return NULL;						/* �T�����s */
}

/*--- �f�[�^�̒ǉ� ---*/
int Add(ChainHash *h, const Member *x)
{
	int key = hash(x->name, h->size);		/* �ǉ�����f�[�^�̃n�b�V���l */
	Node *p = h->table[key];			/* ���ڃm�[�h */
	Node *temp;

	while (p != NULL) {
		if (!strcmp(p->data.name, x->name))	/* ���̃L�[�͓o�^�ς� */
			return 1;					/* �ǉ����s */
		p = p->next;					/* �㑱�m�[�h�ɒ��� */
	}
	if ((temp = (Node *)calloc(1, sizeof(Node))) == NULL)
		return 2;
	SetNode(temp, x, h->table[key]);	/* �ǉ�����m�[�h�ɒl��ݒ� */
	h->table[key] = temp;

	return 0;							/* �ǉ����� */
}

/*--- �f�[�^�̍폜 ---*/
int Remove(ChainHash *h, const Member *x)
{
	int  key = hash(x->name, h->size);	/* �폜����f�[�^�̃n�b�V���l */
	Node *p = h->table[key];			/* ���ڃm�[�h */
	Node **pp = &h->table[key];			/* ���ڃm�[�h�ւ̃|�C���^ */

	while (p != NULL) {
		if (!strcmp(p->data.name, x->name))	{	/* �������� */
			*pp = p->next;
			free(p);					/* ��� */
			return 0;					/* �폜���� */
		}
		pp = &p->next;
		p = p->next;					/* �㑱�m�[�h�ɒ��� */
	}

	return 1;							/* �폜���s�i���݂��Ȃ��j*/
}

/*--- �n�b�V���\���_���v ---*/
void Dump(const ChainHash *h)
{
	int i;

	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];
		printf("%02d  ", i);
		while (p != NULL) {
			printf("�� %d (%s)  ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

/*--- �S�f�[�^�̍폜 ---*/
void Clear(ChainHash *h)
{
	int i;

	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];
		while (p != NULL) {
			Node *next = p->next;
			free(p);
			p = next;
		}
		h->table[i] = NULL;
	}
}

/*--- �n�b�V���\����n�� ---*/
void Terminate(ChainHash *h)
{
	Clear(h);				/* �S�f�[�^���폜 */
	free(h->table);			/* �n�b�V���\�p�z��̋L�������� */
	h->size = 0;			/* �n�b�V���\�̗e�ʂ��N���A */
}
