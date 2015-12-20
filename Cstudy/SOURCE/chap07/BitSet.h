/* �r�b�g�x�N�g���W��BitSet���C�u�����i�w�b�_���j*/

#ifndef ___BitSet
#define ___BitSet

typedef unsigned long  BitSet;				/* �W����\���^ */

#define BitSetNull		(BitSet)0			/* ��W�� */
#define BitSetBits		32					/* �L���ȃr�b�g�� */

#define SetOf(no)	((BitSet)1 << (no))		/* �W��{no} */

/*--- �W��s��n�������Ă��邩 ---*/
int IsMember(BitSet s, int n);

/*--- �W��s��n��ǉ� ---*/
void Add(BitSet *s, int n);

/*--- �W��s����n���폜 ---*/
void Remove(BitSet *s, int n);

/*--- �W��s�̗v�f�� ---*/
int Size(BitSet s);

/*--- �W��s�̑S�v�f��\�� ---*/
void Print(BitSet s);

/*--- �W��s�̑S�v�f��\���i���s�t���j---*/
void PrintLn(BitSet s);

#endif
