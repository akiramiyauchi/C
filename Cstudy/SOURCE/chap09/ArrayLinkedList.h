/* �J�[�\���ɂ����`���X�g�i�w�b�_���j*/

/* �֐�Purge�Ɗ֐�Retrieve��List9-4�ɒǉ� */

#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#include "Member.h"

#define Null	-1			/* ��J�[�\�� */

typedef int Index;			/* �J�[�\���^ */

/*--- �m�[�h ---*/
typedef struct {
	Member data;			/* �f�[�^ */
	Index next;				/* �㑱�m�[�h */
	Index Dnext;			/* �t���[���X�g�̌㑱�m�[�h */
} Node;

/*--- ���`���X�g ---*/
typedef struct {
	Node  *n;				/* ���X�g�{�́i�z��j */
	Index head;				/* �擪�m�[�h */
	Index max;				/* ���p���̖������R�[�h */
	Index deleted;			/* �t���[���X�g�̐擪�m�[�h */
	Index crnt;				/* ���ڃm�[�h */
} List;

/*--- ���`���X�g���������i�ő�v�f����size�j---*/
void Initialize(List *list, int size);

/*--- �֐�compare�ɂ����x�ƈ�v����Ɣ��肳���m�[�h��T�� ---*/
Index Search(List *list, const Member *x,
						 int compare(const Member *x, const Member *y));


/*--- �擪����n���̃m�[�h�ւ̃J�[�\�����擾 ---*/
Index Retrieve(List *list, int n);

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

/*--- ��r�֐��ɂ���ē������Ƃ݂Ȃ���m�[�h���폜 ---*/
void Purge(List *list, int compare(const Member *x, const Member *y));

/*--- ���ڃm�[�h�̃f�[�^��\�� ---*/
void PrintCurrent(const List *list);

/*--- ���ڃm�[�h�̃f�[�^��\���i���s�t���j---*/
void PrintLnCurrent(const List *list);

/*--- �S�m�[�h�̃f�[�^��\�� ---*/
void Print(const List *list);

/*--- ���`���X�g�̌�n�� ---*/
void Terminate(List *list);

#endif
