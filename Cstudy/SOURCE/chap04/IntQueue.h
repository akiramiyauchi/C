/* int�^�L���[IntQueue�i�w�b�_���j*/

#ifndef ___IntQueue
#define ___IntQueue

/*--- �L���[����������\���� ---*/
typedef struct {
	int max;		/* �L���[�̗e�� */
	int num;		/* ���݂̗v�f�� */
	int front;		/* �擪�v�f�J�[�\�� */
	int rear;		/* �����v�f�J�[�\�� */
	int *que;		/* �L���[�{�́i�̐擪�v�f�ւ̃|�C���^�j*/
} IntQueue;

/*--- �L���[�̏����� ---*/
int Initialize(IntQueue *q, int max);

/*--- �L���[�Ƀf�[�^���G���L���[ ---*/
int Enque(IntQueue *q, int x);

/*--- �L���[����f�[�^���f�L���[ ---*/
int Deque(IntQueue *q, int *x);

/*--- �L���[����f�[�^���s�[�N ---*/
int Peek(const IntQueue *q, int *x);

/*--- �S�f�[�^���폜 ---*/
void Clear(IntQueue *q);

/*--- �L���[�̗e�� ---*/
int Capacity(const IntQueue *q);

/*--- �L���[��̃f�[�^�� ---*/
int Size(const IntQueue *q);

/*--- �L���[�͋� ---*/
int IsEmpty(const IntQueue *q);

/*--- �L���[�͖��t�� ---*/
int IsFull(const IntQueue *q);

/*--- �L���[����̒T�� ---*/
int Search(const IntQueue *q, int x);

/*--- �L���[����̒T���i�_���I�Y����ԋp�j---*/
int Search2(const IntQueue *q, int x);

/*--- �S�f�[�^�̕\�� ---*/
void Print(const IntQueue *q);

/*--- �L���[�̌�n�� ---*/
void Terminate(IntQueue *q);

#endif
