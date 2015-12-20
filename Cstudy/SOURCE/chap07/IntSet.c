/* int型集合IntSet（ソース部）*/

#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/*--- コメントに■のついた関数が演習7-1で追加された関数である ---*/

/*--- 集合の初期化 ---*/
int Initialize(IntSet *s, int max)
{
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;								/* 配列の確保に失敗 */
		return -1;
	}
	s->max = max;
	return 0;
}

/*--- 集合sにnが入っているか ---*/
int IsMember(const IntSet *s, int n)
{
	int i;

	for (i = 0; i < s->num; i++)
		if (s->set[i] == n)
			return i;			/* 含まれる（添字を返却）*/
	return -1;					/* 含まれない */
}

/*--- ■集合sは満杯（要素を追加できない状態）か ---*/
int IsFull(const IntSet *s)
{
	return s->num >= s->max;
}

/*--- 集合sにnを追加 ---*/
void Add(IntSet *s, int n)
{
	if (s->num < s->max && IsMember(s, n) == -1)	/* 含まれなかったら */
		s->set[s->num++] = n;						/* 配列の末尾に追加 */
}

/*--- 集合sからnを削除 ---*/
void Remove(IntSet *s, int n)
{
	int idx;

	if ((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];		/* 末尾の要素を削除位置に移動 */
	}
}

/*--- 集合sが格納できる最大の要素数 ---*/
int Capacity(const IntSet *s)
{
	return s->max;
}

/*--- 集合sの要素数 ---*/
int Size(const IntSet *s)
{
	return s->num;
}

/*--- 集合s2をs1に代入 ---*/
void Assign(IntSet *s1, const IntSet *s2)
{
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num;	/* コピーする要素数 */

	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

/*--- 集合s1とs2は等しいか ---*/
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

/*--- 集合s2とs3の和集合をs1に代入 ---*/
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;

	Assign(s1, s2);
	for (i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]);

	return s1;
}

/*--- 集合s2とs3の積集合をs1に代入 ---*/
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;

	s1->num = 0;			/* s1を空集合にする */
	for (i = 0; i < s2->num; i++)
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				Add(s1, s2->set[i]);
	return s1;
}

/*--- 集合s2からs3を引いた集合をs1に代入 ---*/
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;

	s1->num = 0;			/* s1を空集合にする */
	for (i = 0; i < s2->num; i++) {
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				break;
		if (j == s3->num)
			Add(s1, s2->set[i]);
	}
	return s1;
}

/*--- ■集合s2とs3の対象差をs1に代入 ---*/
IntSet *SymmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;

	s1->num = 0;			/* s1を空集合にする */

	for (i = 0; i < s2->num; i++)
		if (IsMember(s3, s2->set[i]) == -1)
			Add(s1, s2->set[i]);

	for (i = 0; i < s3->num; i++)
		if (IsMember(s2, s3->set[i]) == -1)
			Add(s1, s3->set[i]);

	return s1;
}

/*--- ■集合s1に対して集合s2の全要素を追加 ---*/
IntSet *ToUnion(IntSet *s1, const IntSet *s2)
{
	int i;

	for (i = 0; i < s2->num; i++)
		Add(s1, s2->set[i]);

	return s1;
}

/*--- ■集合s1から集合s2に含まれない全要素を削除 ---*/
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

/*--- ■集合s1から集合s2に含まれる全要素を削除 ---*/
IntSet *ToDifference(IntSet *s1, const IntSet *s2)
{
	int i;

	for (i = 0; i < s2->num; i++)
		Remove(s1, s2->set[i]);

	return s1;
}

/*--- ■集合s1はs2の部分集合か ---*/
int IsSubset(const IntSet *s1, const IntSet *s2)
{
	int i, j;

	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;
		if (j == s2->num)					/* s1->set[i]はs2に含まれない */
			return 0;
	}
	return 1;
}

/*--- ■集合s1はs2の真部分集合か ---*/
int IsProperSubset(const IntSet *s1, const IntSet *s2)
{
	int i;

	if (s1->num >= s2->num)					/* s1の要素数がs2以上であれば */
		return 0;							/* s1はs2の真部分集合ではない */

	return IsSubset(s1, s2);
}

/*--- 集合sの全要素を表示 ---*/
void Print(const IntSet *s)
{
	int i;

	printf("{ ");
	for (i = 0; i < s->num; i++)
		printf("%d ", s->set[i]);
	printf("}");
}

/*--- 集合sの全要素を表示（改行付き）---*/
void PrintLn(const IntSet *s)
{
	Print(s);
	putchar('\n');
}

/*--- ■集合sの全要素を削除 ---*/
void Clear(IntSet *s)
{
	s->num = 0;
}

/*--- 集合の後始末 ---*/
void Terminate(IntSet *s)
{
	if (s->set != NULL) {
		free(s->set);							/* 配列を解放 */
		s->max = s->num = 0;
	}
}
