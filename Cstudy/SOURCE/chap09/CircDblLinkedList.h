/* �z�E�d�A�����X�g�i�w�b�_���j*/

/* �֐�Purge�Ɗ֐�Retrieve��List9-7�ɒǉ� */

#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList

#include "Member.h"

/*--- �m�[�h ---*/
typedef struct __node {
	Member        data;			/* �f�[�^ */
	struct __node *prev;		/* ��s�m�[�h�ւ̃|�C���^ */
	struct __node *next;		/* �㑱�m�[�h�ւ̃|�C���^ */
} Dnode;

/*--- �z�E�d�A�����X�g ---*/
typedef struct {
	Dnode *head;				/* �擪�_�~�[�m�[�h�ւ̃|�C���^ */
	Dnode *crnt;				/* ���ڃm�[�h�ւ̃|�C���^ */
} Dlist;

/*--- ���X�g�������� ---*/
void Initialize(Dlist *list);

/*--- ���ڃm�[�h�̃f�[�^��\�� ---*/
void PrintCurrent(const Dlist *list);

/*--- ���ڃm�[�h�̃f�[�^��\���i���s�t���j---*/
void PrintLnCurrent(const Dlist *list);

/*--- �֐�compare�ɂ����x�ƈ�v����Ɣ��肳���m�[�h��T�� ---*/
Dnode *Search(Dlist *list, const Member *x,
			  int compare(const Member *x, const Member *y));

/*--- �擪����n���̃m�[�h�ւ̃|�C���^���擾 ---*/
Dnode *Retrieve(Dlist *list, int n);

/*--- �S�m�[�h�̃f�[�^�����X�g���ɕ\�� ---*/
void Print(const Dlist *list);

/*--- �S�m�[�h�̃f�[�^�����X�g�̋t���ɕ\�� ---*/
void PrintRevese(const Dlist *list);

/*--- ���ڃm�[�h�������ɐi�߂� ---*/
int Next(Dlist *list);

/*--- ���ڃm�[�h����O���ɖ߂� ---*/
int Prev(Dlist *list);

/*--- p���w���m�[�h�̒���Ƀm�[�h��}�� ---*/
void InsertAfter(Dlist *list, Dnode *p, const Member *x);

/*--- �擪�Ƀm�[�h��}�� ---*/
void InsertFront(Dlist *list, const Member *x);

/*--- �����Ƀm�[�h��}�� ---*/
void InsertRear(Dlist *list, const Member *x);

/*--- p���w���m�[�h���폜 ---*/
void Remove(Dlist *list, Dnode *p);

/*--- �擪�m�[�h���폜 ---*/
void RemoveFront(Dlist *list);

/*--- �����m�[�h���폜 ---*/
void RemoveRear(Dlist *list);

/*--- ���ڃm�[�h���폜 ---*/
void RemoveCurrent(Dlist *list);

/*--- �S�m�[�h���폜 ---*/
void Clear(Dlist *list);

/*--- ��r�֐��ɂ���ē������Ƃ݂Ȃ���m�[�h���폜 ---*/
void Purge(Dlist *list, int compare(const Member *x, const Member *y));

/*--- �z�E�d�A�����X�g����n�� ---*/
void Terminate(Dlist *list);

#endif
