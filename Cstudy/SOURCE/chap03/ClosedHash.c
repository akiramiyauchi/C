/* �I�[�v���A�h���X�@�ɂ��n�b�V���i�\�[�X���F�L�[�͎����j*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ClosedHash.h"

/*--- �n�b�V���֐��ikey�̃n�b�V���l��Ԃ��j---*/
static int hash(const char *key, int size)
{
	unsigned long h = 0;

	while (*key)
		h += *(key++);
	return h % size;
}

/*--- �ăn�b�V���֐� ---*/
static int rehash(int key, int size)
{
	return (key + 1) % size;
}

/*--- �m�[�h�̊e�����o�ɒl��ݒ� ----*/
static void SetBucket(Bucket *n, const Member *x, Status stat)
{
	n->data = *x;		/* �f�[�^ */
	n->stat = stat;		/* �v�f�̏�� */
}

/*--- �n�b�V���\�������� ---*/
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

/*--- �T�� ---*/
Bucket *Search(const ClosedHash *h, const Member *x)
{
	int i;
	int key = hash(x->name, h->size);	/* �T������f�[�^�̃n�b�V���l */
	Bucket *p = &h->table[key];			/* ���ڃm�[�h */

	for (i = 0; p->stat != Empty && i < h->size; i++) {
		if (p->stat == Occupied && !strcmp(p->data.name, x->name))
			return p;
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return NULL;
}

/*--- �f�[�^�̒ǉ� ---*/
int Add(ClosedHash *h, const Member *x)
{
	int i;
	int key = hash(x->name, h->size);		/* �ǉ�����f�[�^�̃n�b�V���l */
	Bucket *p = &h->table[key];			/* ���ڃm�[�h */

	if (Search(h, x))					/* ���̃L�[�͓o�^�ς� */
		return 1;

	for (i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			SetBucket(p, x, Occupied);
			return 0;
		}
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return 2;							/* �n�b�V���\�����t */
}

/*--- �f�[�^�̍폜 ---*/
int Remove(ClosedHash *h, const Member *x)
{
	Bucket *p = Search(h, x);

	if (p == NULL)
		return 1;						/* ���̃L�[�l�͑��݂��Ȃ� */

	p->stat = Deleted;
	return 0;
}

/*--- �n�b�V���\���_���v ---*/
void Dump(const ClosedHash *h)
{
	int i;

	for (i = 0; i < h->size; i++) {
		printf("%02d : ", i);
		switch (h->table[i].stat) {
		 case Occupied : printf("%d (%s)\n",
								h->table[i].data.no, h->table[i].data.name);
						 break;

		 case Empty :	 printf("-- ���o�^ --\n");	break;

		 case Deleted :	 printf("-- �폜�� --\n");	break;
		}
	}
}

/*--- �S�f�[�^�̍폜 ---*/
void Clear(ClosedHash *h)
{
	int i;
	for (i = 0; i < h->size; i++)
		h->table[i].stat = Empty;
}

/*--- �n�b�V���\����n�� ---*/
void Terminate(ClosedHash *h)
{
	Clear(h);				/* �S�f�[�^���폜 */
	free(h->table);			/* �n�b�V���\�p�z��̋L�������� */
	h->size = 0;			/* �n�b�V���\�̗e�ʂ��N���A */
}
