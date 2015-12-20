/* int�^�W��IntSet�i�\�[�X���j*/

#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/*--- �R�����g�Ɂ��̂����֐������K7-1�Œǉ����ꂽ�֐��ł��� ---*/

/*--- �W���̏����� ---*/
int Initialize(IntSet *s, int max)
{
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;								/* �z��̊m�ۂɎ��s */
		return -1;
	}
	s->max = max;
	return 0;
}

/*--- �W��s��n�������Ă��邩 ---*/
int IsMember(const IntSet *s, int n)
{
	int i;

	for (i = 0; i < s->num; i++)
		if (s->set[i] == n)
			return i;			/* �܂܂��i�Y����ԋp�j*/
	return -1;					/* �܂܂�Ȃ� */
}

/*--- ���W��s�͖��t�i�v�f��ǉ��ł��Ȃ���ԁj�� ---*/
int IsFull(const IntSet *s)
{
	return s->num >= s->max;
}

/*--- �W��s��n��ǉ� ---*/
void Add(IntSet *s, int n)
{
	if (s->num < s->max && IsMember(s, n) == -1)	/* �܂܂�Ȃ������� */
		s->set[s->num++] = n;						/* �z��̖����ɒǉ� */
}

/*--- �W��s����n���폜 ---*/
void Remove(IntSet *s, int n)
{
	int idx;

	if ((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];		/* �����̗v�f���폜�ʒu�Ɉړ� */
	}
}

/*--- �W��s���i�[�ł���ő�̗v�f�� ---*/
int Capacity(const IntSet *s)
{
	return s->max;
}

/*--- �W��s�̗v�f�� ---*/
int Size(const IntSet *s)
{
	return s->num;
}

/*--- �W��s2��s1�ɑ�� ---*/
void Assign(IntSet *s1, const IntSet *s2)
{
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num;	/* �R�s�[����v�f�� */

	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

/*--- �W��s1��s2�͓������� ---*/
int Equal(const IntSet *s1, const IntSet *s2)
{
	int i, j;

	if (Size(s1) != Size(s2))
		return 0;

	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;
		if (j == s2->num)
			return 0;
	}
	return 1;
}

/*--- �W��s2��s3�̘a�W����s1�ɑ�� ---*/
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;

	Assign(s1, s2);
	for (i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]);

	return s1;
}

/*--- �W��s2��s3�̐ϏW����s1�ɑ�� ---*/
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;

	s1->num = 0;			/* s1����W���ɂ��� */
	for (i = 0; i < s2->num; i++)
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				Add(s1, s2->set[i]);
	return s1;
}

/*--- �W��s2����s3���������W����s1�ɑ�� ---*/
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;

	s1->num = 0;			/* s1����W���ɂ��� */
	for (i = 0; i < s2->num; i++) {
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				break;
		if (j == s3->num)
			Add(s1, s2->set[i]);
	}
	return s1;
}

/*--- ���W��s2��s3�̑Ώۍ���s1�ɑ�� ---*/
IntSet *SymmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;

	s1->num = 0;			/* s1����W���ɂ��� */

	for (i = 0; i < s2->num; i++)
		if (IsMember(s3, s2->set[i]) == -1)
			Add(s1, s2->set[i]);

	for (i = 0; i < s3->num; i++)
		if (IsMember(s2, s3->set[i]) == -1)
			Add(s1, s3->set[i]);

	return s1;
}

/*--- ���W��s1�ɑ΂��ďW��s2�̑S�v�f��ǉ� ---*/
IntSet *ToUnion(IntSet *s1, const IntSet *s2)
{
	int i;

	for (i = 0; i < s2->num; i++)
		Add(s1, s2->set[i]);

	return s1;
}

/*--- ���W��s1����W��s2�Ɋ܂܂�Ȃ��S�v�f���폜 ---*/
IntSet *ToIntersection(IntSet *s1, const IntSet *s2)
{
	int i = 0;

	while (i < s1->num) {
		if (IsMember(s2, s1->set[i]) == -1)
			Remove(s1, s1->set[i]);
		else
			i++;
	}
	return s1;
}

/*--- ���W��s1����W��s2�Ɋ܂܂��S�v�f���폜 ---*/
IntSet *ToDifference(IntSet *s1, const IntSet *s2)
{
	int i;

	for (i = 0; i < s2->num; i++)
		Remove(s1, s2->set[i]);

	return s1;
}

/*--- ���W��s1��s2�̕����W���� ---*/
int IsSubset(const IntSet *s1, const IntSet *s2)
{
	int i, j;

	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;
		if (j == s2->num)					/* s1->set[i]��s2�Ɋ܂܂�Ȃ� */
			return 0;
	}
	return 1;
}

/*--- ���W��s1��s2�̐^�����W���� ---*/
int IsProperSubset(const IntSet *s1, const IntSet *s2)
{
	int i;

	if (s1->num >= s2->num)					/* s1�̗v�f����s2�ȏ�ł���� */
		return 0;							/* s1��s2�̐^�����W���ł͂Ȃ� */

	return IsSubset(s1, s2);
}

/*--- �W��s�̑S�v�f��\�� ---*/
void Print(const IntSet *s)
{
	int i;

	printf("{ ");
	for (i = 0; i < s->num; i++)
		printf("%d ", s->set[i]);
	printf("}");
}

/*--- �W��s�̑S�v�f��\���i���s�t���j---*/
void PrintLn(const IntSet *s)
{
	Print(s);
	putchar('\n');
}

/*--- ���W��s�̑S�v�f���폜 ---*/
void Clear(IntSet *s)
{
	s->num = 0;
}

/*--- �W���̌�n�� ---*/
void Terminate(IntSet *s)
{
	if (s->set != NULL) {
		free(s->set);							/* �z������ */
		s->max = s->num = 0;
	}
}
