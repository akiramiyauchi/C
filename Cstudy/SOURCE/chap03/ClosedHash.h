/* �I�[�v���A�h���X�@�ɂ��n�b�V���i�w�b�_���j*/

#ifndef ___ClosedHash
#define ___ClosedHash

#include "Member.h"

/*--- �v�f�̏�� ---*/
typedef enum {
	Occupied, Empty, Deleted
} Status;

/*--- �v�f ---*/
typedef struct {
	Member data;			/* �f�[�^ */
	Status stat;			/* �v�f�̏��*/
} Bucket;

/*--- �n�b�V���\ ---*/
typedef struct {
	int     size;			/* �n�b�V���\�̑傫�� */
	Bucket *table;			/* �n�b�V���\�̐擪�v�f�ւ̃|�C���^ */
} ClosedHash;

/*--- �n�b�V���\�������� ---*/
int Initialize(ClosedHash *h, int size);

/*--- �T�� ---*/
Bucket *Search(const ClosedHash *h, const Member *x);

/*--- �f�[�^�̒ǉ� ---*/
int Add(ClosedHash *h, const Member *x);

/*--- �f�[�^�̍폜 ---*/
int Remove(ClosedHash *h, const Member *x);

/*--- �n�b�V���\���_���v ---*/
void Dump(const ClosedHash *h);

/*--- �S�f�[�^�̍폜 ---*/
void Clear(ClosedHash *h);

/*--- �n�b�V���\����n�� ---*/
void Terminate(ClosedHash *h);

#endif
