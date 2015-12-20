/* int�^�W��IntSet�i�w�b�_���j*/

#ifndef ___IntSet
#define ___IntSet

/*--- �R�����g�Ɂ��̂����֐������K7-1�Œǉ����ꂽ�֐��ł��� ---*/

/*--- int�^�̏W������������\���� ---*/
typedef struct {
	int max;	/* �W���̗e�� */
	int num;	/* �W���̗v�f�� */
	int *set;	/* �W���{�̂̔z��i�̐擪�v�f�ւ̃|�C���^�j*/
} IntSet;

/*--- �W���̏����� ---*/
int Initialize(IntSet *s, int max);

/*--- �W��s��n�������Ă��邩 ---*/
int IsMember(const IntSet *s, int n);

/*--- ���W��s�͖��t�i�v�f��ǉ��ł��Ȃ���ԁj�� ---*/
int IsFull(const IntSet *s);

/*--- �W��s��n��ǉ� ---*/
void Add(IntSet *s, int n);

/*--- �W��s����n���폜 ---*/
void Remove(IntSet *s, int n);

/*--- �W��s���i�[�ł���ő�̗v�f�� ---*/
int Capacity(const IntSet *s);

/*--- �W��s�̗v�f�� ---*/
int Size(const IntSet *s);

/*--- �W��s2��s1�ɑ�� ---*/
void Assign(IntSet *s1, const IntSet *s2);

/*--- �W��s1��s2�͓������� ---*/
int Equal(const IntSet *s1, const IntSet *s2);

/*--- �W��s2��s3�̘a�W����s1�ɑ�� ---*/
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3);

/*--- �W��s2��s3�̐ϏW����s1�ɑ�� ---*/
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3);

/*--- �W��s2����s3���������W����s1�ɑ�� ---*/
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3);

/*--- ���W��s2��s3�̑Ώۍ���s1�ɑ�� ---*/
IntSet *SymmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3);

/*--- ���W��s1�ɑ΂��ďW��s2�̑S�v�f��ǉ� ---*/
IntSet *ToUnion(IntSet *s1, const IntSet *s2);

/*--- ���W��s1����W��s2�Ɋ܂܂�Ȃ��S�v�f���폜 ---*/
IntSet *ToIntersection(IntSet *s1, const IntSet *s2);

/*--- ���W��s1����W��s2�Ɋ܂܂��S�v�f���폜 ---*/
IntSet *ToDifference(IntSet *s1, const IntSet *s2);

/*--- ���W��s1��s2�̕����W���� ---*/
int IsSubset(const IntSet *s1, const IntSet *s2);

/*--- ���W��s1��s2�̐^�����W���� ---*/
int IsProperSubset(const IntSet *s1, const IntSet *s2);

/*--- �W��s�̑S�v�f��\�� ---*/
void Print(const IntSet *s);

/*--- �W��s�̑S�v�f��\���i���s�t���j---*/
void PrintLn(const IntSet *s);

/*--- ���W��s�̑S�v�f���폜 ---*/
void Clear(IntSet *s);

/*--- �W���̌�n�� ---*/
void Terminate(IntSet *s);

#endif
