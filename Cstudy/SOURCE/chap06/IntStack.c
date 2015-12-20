/* int�^�X�^�b�NIntStack�i�\�[�X���j*/

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/*--- �X�^�b�N�̏����� ---*/
int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;								/* �z��̊m�ۂɎ��s */
		return -1;
	}
	s->max = max;
	return 0;
}

/*--- �X�^�b�N�Ƀf�[�^���v�b�V�� ---*/
int Push(IntStack *s, int x)
{
	if (s->ptr >= s->max)						/* �X�^�b�N�͖��t */
		 return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

/*--- �X�^�b�N����f�[�^���|�b�v ---*/
int Pop(IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* �X�^�b�N�͋� */
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

/*--- �X�^�b�N����f�[�^���s�[�N ---*/
int Peek(const IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* �X�^�b�N�͋� */
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*--- �X�^�b�N����ɂ��� ---*/
void Clear(IntStack *s)
{
	s->ptr = 0;
}

/*--- �X�^�b�N�̗e�� ---*/
int Capacity(const IntStack *s)
{
	return s->max;
}

/*--- �X�^�b�N�ɐς܂�Ă���f�[�^�� ---*/
int Size(const IntStack *s)
{
	return s->ptr;
}

/*--- �X�^�b�N�͋� ---*/
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0;
}

/*--- �X�^�b�N�͖��t�� ---*/
int IsFull(const IntStack *s)
{
	return s->ptr >= s->max;
}

/*--- �X�^�b�N����̒T�� ---*/
int Search(const IntStack *s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* ���と��ɐ��`�T�� */
		if (s->stk[i] == x)
			return i;		/* �T������ */
	return -1;				/* �T�����s */
}

/*--- �S�f�[�^�̕\�� ---*/
void Print(const IntStack *s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* �ꁨ����ɑ��� */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- �X�^�b�N�̌�n�� ---*/
void Terminate(IntStack *s)
{
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}
