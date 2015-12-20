/* ビットベクトル集合BitSetライブラリ（ヘッダ部）*/

#ifndef ___BitSet
#define ___BitSet

typedef unsigned long  BitSet;				/* 集合を表す型 */

#define BitSetNull		(BitSet)0			/* 空集合 */
#define BitSetBits		32					/* 有効なビット数 */

#define SetOf(no)	((BitSet)1 << (no))		/* 集合{no} */

/*--- 集合sにnが入っているか ---*/
int IsMember(BitSet s, int n);

/*--- 集合sにnを追加 ---*/
void Add(BitSet *s, int n);

/*--- 集合sからnを削除 ---*/
void Remove(BitSet *s, int n);

/*--- 集合sの要素数 ---*/
int Size(BitSet s);

/*--- 集合sの全要素を表示 ---*/
void Print(BitSet s);

/*--- 集合sの全要素を表示（改行付き）---*/
void PrintLn(BitSet s);

#endif
