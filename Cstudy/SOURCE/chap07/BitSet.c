/* �r�b�g�x�N�g���ɂ�鐮���W�����Z�i�\�[�X���j*/

#include <stdio.h>
#include "BitSet.h"

/*--- �W��s��n�������Ă��邩 ---*/
int IsMember(BitSet s, int n)
{
	return s & SetOf(n);
}

/*--- �W��s��n��ǉ� ---*/
void Add(BitSet *s, int n)
{
	*s |= SetOf(n);
}

/*--- �W��s����n���폜 ---*/
void Remove(BitSet *s, int n)
{
	*s &= ~SetOf(n);
}

/*--- �W��s�̗v�f�� ---*/
int Size(BitSet s)
{
	int n = 0;

	for ( ; s != BitSetNull; n++)
		s &= s - 1;
	return n;
}

/*--- �W��s�̑S�v�f��\�� ---*/
void Print(BitSet s)
{
	int i;

	printf("{ ");
	for (i = 0; i < BitSetBits; i++)
		if (IsMember(s, i))
			printf("%d ", i);
	printf("}");
}

/*--- �W��s�̑S�v�f��\���i���s�t���j---*/
void PrintLn(BitSet s)
{
	Print(s);
	putchar('\n');
}
