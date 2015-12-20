/* �`�F�C���@�ɂ��n�b�V���i�w�b�_���j*/

#ifndef ___ChainHash
#define ___ChainHash

#include "Member.h"

/*--- �o�P�b�g��\���m�[�h ---*/
typedef struct __node {
	Member         data;	/* �f�[�^ */
	struct __node *next;	/* �㑱�m�[�h�ւ̃|�C���^ */
} Node;

/*--- �n�b�V���\ ---*/
typedef struct {
	int    size;			/* �n�b�V���\�̑傫�� */
	Node **table;			/* �n�b�V���\�̐擪�v�f�ւ̃|�C���^ */
} ChainHash;

/*--- �n�b�V���\�������� ---*/
int Initialize(ChainHash *h, int size);

/*--- �T�� ---*/
Node *Search(const ChainHash *h, const Member *x);

/*--- �f�[�^�̒ǉ� ---*/
int Add(ChainHash *h, const Member *x);

/*--- �f�[�^�̍폜 ---*/
int Remove(ChainHash *h, const Member *x);

/*--- �n�b�V���\���_���v ---*/
void Dump(const ChainHash *h);

/*--- �S�f�[�^�̍폜 ---*/
void Clear(ChainHash *h);

/*--- �n�b�V���\����n�� ---*/
void Terminate(ChainHash *h);

#endif
