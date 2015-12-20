/* int�^�X�^�b�NIntStack�i�w�b�_���j*/

#ifndef ___IntStack
#define ___IntStack

/*--- �X�^�b�N����������\���� ---*/
typedef struct {
	int max;		/* �X�^�b�N�̗e�� */
	int ptr;		/* �X�^�b�N�|�C���^ */
	int *stk;		/* �X�^�b�N�{�́i�̐擪�v�f�ւ̃|�C���^�j */
} IntStack;

/*--- �X�^�b�N�̏����� ---*/
int Initialize(IntStack *s, int max);

/*--- �X�^�b�N�Ƀf�[�^���v�b�V�� ---*/
int Push(IntStack *s, int x);

/*--- �X�^�b�N����f�[�^���|�b�v ---*/
int Pop(IntStack *s, int *x);

/*--- �X�^�b�N����f�[�^���s�[�N ---*/
int Peek(const IntStack *s, int *x);

/*--- �X�^�b�N����ɂ��� ---*/
void Clear(IntStack *s);

/*--- �X�^�b�N�̗e�� ---*/
int Capacity(const IntStack *s);

/*--- �X�^�b�N��̃f�[�^�� ---*/
int Size(const IntStack *s);

/*--- �X�^�b�N�͋� ---*/
int IsEmpty(const IntStack *s);

/*--- �X�^�b�N�͖��t�� ---*/
int IsFull(const IntStack *s);

/*--- �X�^�b�N����̒T�� ---*/
int Search(const IntStack *s, int x);

/*--- �S�f�[�^�̕\�� ---*/
void Print(const IntStack *s);

/*--- �X�^�b�N�̌�n�� ---*/
void Terminate(IntStack *s);

#endif
