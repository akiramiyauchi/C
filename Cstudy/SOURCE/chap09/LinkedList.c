/* �|�C���^�ɂ����`���X�g�i�\�[�X���j */

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/*--- ��̃m�[�h�𓮓I�ɐ��� ---*/
static Node *AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/*--- n�̎w���m�[�h�̊e�����o�ɒl��ݒ� ----*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
	n->data = *x;		/* �f�[�^ */
	n->next = next;		/* �㑱�|�C���^ */
}

/*--- ���`���X�g�������� ---*/
void Initialize(List *list)
{
	list->head = NULL;		/* �擪�m�[�h */
	list->crnt = NULL;		/* ���ڃm�[�h */
}

/*--- �֐�compare�ɂ����x�ƈ�v����Ɣ��肳���m�[�h��T�� ---*/
Node *Search(List *list, const Member *x,
						 int compare(const Member *x, const Member *y))
{
	Node *ptr = list->head;

	while (ptr != NULL) {
		if (compare(&ptr->data, x) == 0) {	/* �L�[�l����v */
			list->crnt = ptr;
			return ptr;					/* �T������ */
		}
		ptr = ptr->next;				/* �㑱�m�[�h�ɒ��� */
	}
	return NULL;						/* �T�����s */
}

/*--- �擪�Ƀm�[�h��}�� ---*/
void InsertFront(List *list, const Member *x)
{
	Node *ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr);
}

/*--- �����Ƀm�[�h��}�� ---*/
void InsertRear(List *list, const Member *x)
{
	if (list->head == NULL)					/* ��ł���� */
		InsertFront(list, x);				/* �擪�ɑ}�� */
	else {
		Node *ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

/*--- �擪�m�[�h���폜 ---*/
void RemoveFront(List *list)
{
	if (list->head != NULL) {
		Node *ptr = list->head->next;		/* �Q�Ԗڂ̃m�[�h�ւ̃|�C���^ */
		free(list->head);					/* �擪�m�[�h����� */
		list->head = list->crnt = ptr;		/* �V�����擪�m�[�h */
	}
}

/*--- �����m�[�h���폜 ---*/
void RemoveRear(List *list)
{
	if (list->head != NULL) {
		if ((list->head)->next == NULL)		/* �m�[�h��������ł���� */
			RemoveFront(list);				/* �擪�m�[�h���폜 */
		else {
			Node *ptr = list->head;
			Node *pre;

			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}
			pre->next = NULL;				/* pre�͖�������2�Ԗ� */
			free(ptr);						/* ptr�͖��� */
			list->crnt = pre;
		}
	}
}

/*--- ���ڃm�[�h���폜 ---*/
void RemoveCurrent(List *list)
{
	if (list->head != NULL) {
		if (list->crnt == list->head)	/* �擪�m�[�h�ɒ��ڂ��Ă���� */
			RemoveFront(list);			/* �擪�m�[�h���폜 */
		else {
			Node *ptr = list->head;

			while (ptr->next != list->crnt)
				ptr = ptr->next;
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- �S�m�[�h���폜 ---*/
void Clear(List *list)
{
	while (list->head != NULL)			/* ��ɂȂ�܂� */
		RemoveFront(list);				/* �擪�m�[�h���폜 */
	list->crnt = NULL;
}

/*--- ���ڃm�[�h�̃f�[�^��\�� ---*/
void PrintCurrent(const List *list)
{
	if (list->crnt == NULL)
		printf("���ڃm�[�h�͂���܂���B");
	else
		PrintMember(&list->crnt->data);
}

/*--- ���ڃm�[�h�̃f�[�^��\���i���s�t���j---*/
void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- �S�m�[�h�̃f�[�^�����X�g���ɕ\�� ---*/
void Print(const List *list)
{
	if (list->head == NULL)
		puts("�m�[�h������܂���B");
	else {
		Node *ptr = list->head;

		puts("�y�ꗗ�\�z");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;				/* �㑱�m�[�h�ɒ��� */
		}
	}
}

/*--- ���`���X�g�̌�n�� ---*/
void Terminate(List *list)
{
	Clear(list);						/* �S�m�[�h���폜 */
}
