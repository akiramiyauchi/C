/* �|�C���^�ɂ����`���X�g�i�w�b�_���j*/

#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

/*--- �m�[�h ---*/
typedef struct __node {
	Member         data;	/* �f�[�^ */
	struct __node *next;	/* �㑱�|�C���^�i�㑱�m�[�h�ւ̃|�C���^�j*/
} Node;

/*--- ���`���X�g ---*/
typedef struct {
	Node *head;		/* �擪�m�[�h�ւ̃|�C���^ */
	Node *crnt;		/* ���ڃm�[�h�ւ̃|�C���^ */
} List;

/*--- ���`���X�g�������� ---*/
void Initialize(List *list);

/*--- �֐�compare�ɂ����x�ƈ�v����Ɣ��肳���m�[�h��T�� ---*/
Node *Search(List *list, const Member *x,
						 int compare(const Member *x, const Member *y));

/*--- �擪�Ƀm�[�h��}�� ---*/
void InsertFront(List *list, const Member *x);

/*--- �����Ƀm�[�h��}�� ---*/
void InsertRear(List *list, const Member *x);

/*--- �擪�m�[�h���폜 ---*/
void RemoveFront(List *list);

/*--- �����m�[�h���폜 ---*/
void RemoveRear(List *list);

/*--- ���ڃm�[�h���폜 ---*/
void RemoveCurrent(List *list);

/*--- �S�m�[�h���폜 ---*/
void Clear(List *list);

/*--- ���ڃm�[�h�̃f�[�^��\�� ---*/
void PrintCurrent(const List *list);

/*--- ���ڃm�[�h�̃f�[�^��\���i���s�t���j---*/
void PrintLnCurrent(const List *list);

/*--- �S�m�[�h�̃f�[�^�����X�g���ɕ\�� ---*/
void Print(const List *list);

/*--- ���`���X�g�̌�n�� ---*/
void Terminate(List *list);

#endif
