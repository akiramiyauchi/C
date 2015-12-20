/* ビットベクトルによる整数集合演算（ソース部）*/

#include <stdio.h>
#include "BitSet.h"

/*--- 集合sにnが入っているか ---*/
int IsMember(BitSet s, int n)
{
	return s & SetOf(n);
}

/*--- 集合sにnを追加 ---*/
void Add(BitSet *s, int n)
{
	*s |= SetOf(n);
}

/*--- 集合sからnを削除 ---*/
void Remove(BitSet *s, int n)
{
	*s &= ~SetOf(n);
}

/*--- 集合sの要素数 ---*/
int Size(BitSet s)
{
	int n = 0;

	for ( ; s != BitSetNull; n++)
		s &= s - 1;
	return n;
}

/*--- 集合sの全要素を表示 ---*/
void Print(BitSet s)
{
	int i;

	printf("{ ");
	for (i = 0; i < BitSetBits; i++)
		if (IsMember(s, i))
			printf("%d ", i);
	printf("}");
}

/*--- 集合sの全要素を表示（改行付き）---*/
void PrintLn(BitSet s)
{
	Print(s);
	putchar('\n');
}
