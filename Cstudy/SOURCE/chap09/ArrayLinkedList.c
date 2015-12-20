/* �J�[�\���ɂ����`���X�g�i�\�[�X���j*/

/* �֐�Purge�Ɗ֐�Retrieve��List9-5�ɒǉ� */

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- �}�����郌�R�[�h�̃C���f�b�N�X�����߂� ---*/
static Index GetIndex(List *list)
{
	if (list->deleted == Null)				/* �폜���R�[�h���Ȃ��ꍇ */
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

/*--- �w�肵�����R�[�h���폜���X�g�ɓo�^���� ---*/
static void DeleteIndex(List *list, Index idx)
{
	if (list->deleted == Null) {			/* �폜���R�[�h���Ȃ��ꍇ */
		list->deleted = idx;
		list->n[idx].Dnext = Null;
	} else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

/*--- n�̎w���m�[�h�̊e�����o�ɒl��ݒ� ----*/
static void SetNode(Node *n, const Member *x, Index next)
{
	n->data = *x;							/* �f�[�^ */
	n->next = next;							/* �㑱�m�[�h�ւ̃|�C���^ */
}

/*--- ���`���X�g���������i�ő�v�f����size�j---*/
void Initialize(List *list, int size)
{
	list->n = calloc(size, sizeof(Node));
	list->head = Null;							/* �擪�m�[�h */
	list->crnt = Null;							/* ���ڃm�[�h */
	list->max = Null;
	list->deleted = Null;
}

/*--- �֐�compare�ɂ����x�ƈ�v����Ɣ��肳���m�[�h��T�� ---*/
Index Search(List *list, const Member *x,
						 int compare(const Member *x, const Member *y))
{
	Index ptr = list->head;

	while (ptr != Null) {
		if (compare(&list->n[ptr].data, x) == 0) {
			list->crnt = ptr;
			return ptr;				/* �T������ */
		}
		ptr = list->n[ptr].next;
	}
	return Null;						/* �T�����s */
}

/*--- �擪����n���̃m�[�h�ւ̃J�[�\�����擾 ---*/
Index Retrieve(List *list, int n)
{
	Index ptr = list->head;

	while (n >= 0  &&  ptr != Null) {
		if (n-- == 0) {
			list->crnt = ptr;
			return ptr;					/* �T������ */
		}
		ptr = list->n[ptr].next;		/* �㑱�m�[�h�ɒ��� */
	}
	return Null;	
}

/*--- �擪�Ƀm�[�h��}�� ---*/
void InsertFront(List *list, const Member *x)
{
	Index ptr = list->head;
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr);
}

/*--- �����Ƀm�[�h��}�� ---*/
void InsertRear(List *list, const Member *x)
{
	if (list->head == Null)					/* ��ł���� */
		InsertFront(list, x);				/* �擪�ɑ}�� */
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != Null)
			ptr = list->n[ptr].next;
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, Null);
	}
}

/*--- �擪�m�[�h���폜 ---*/
void RemoveFront(List *list)
{
	if (list->head != Null) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

/*--- �����m�[�h���폜 ---*/
void RemoveRear(List *list)
{
	if (list->head != Null) {
		if (list->n[list->head].next == Null)	/* �m�[�h��������ł���� */
			RemoveFront(list);					/* �擪�m�[�h���폜 */
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

/*--- ���ڃm�[�h���폜 ---*/
void RemoveCurrent(List *list)
{
	if (list->head != Null) {
		if (list->crnt == list->head)		/* �擪�m�[�h�ɒ��ڂ��Ă���� */
			RemoveFront(list);				/* �擪�m�[�h���폜 */
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

/*--- �S�m�[�h���폜 ---*/
void Clear(List *list)
{
	while (list->head != Null)			/* ��ɂȂ�܂� */
		RemoveFront(list);				/* �擪�m�[�h���폜 */
	list->crnt = Null;
}

/*--- ��r�֐��ɂ���ē������Ƃ݂Ȃ���m�[�h���폜 ---*/
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

/*--- ���ڃm�[�h�̃f�[�^��\�� ---*/
void PrintCurrent(const List *list)
{
	if (list->crnt == Null)
		printf("���ڗv�f�͂���܂���B");
	else
		PrintMember(&list->n[list->crnt].data);
}

/*--- ���ڃm�[�h�̃f�[�^��\���i���s�t���j---*/
void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- �S�m�[�h�̃f�[�^��\�� ---*/
void Print(const List *list)
{
	if (list->head == Null)
		puts("�m�[�h������܂���B");
	else {
		Index ptr = list->head;

		puts("�y�ꗗ�\�z");
		while (ptr != Null) {
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;		/* �㑱�m�[�h */
		}
	}
}

/*--- ���`���X�g�̌�n�� ---*/
void Terminate(List *list)
{
	Clear(list);					/* �S�m�[�h���폜 */
	free(list->n);
}
