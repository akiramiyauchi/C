/* ����f�[�^Member�i�w�b�_���j*/

#ifndef ___Member
#define ___Member

/*--- ����f�[�^ ---*/
typedef struct {
	int  no;			/* �ԍ� */
	char name[20];		/* ���� */
} Member;

#define MEMBER_NO		1		/* �ԍ���\���萔�l */
#define MEMBER_NAME		2		/* ������\���萔�l  */

/*--- ����̔ԍ��̔�r�֐� ---*/
int MemberNoCmp(const Member *x, const Member *y);

/*--- ����̎����̔�r�֐� ---*/
int MemberNameCmp(const Member *x, const Member *y);

/*--- ����f�[�^�̕\���i���s�Ȃ��j---*/
void PrintMember(const Member *x);

/*--- ����f�[�^�̕\���i���s����j---*/
void PrintLnMember(const Member *x);

/*--- ����f�[�^�̓Ǎ��� ---*/
Member ScanMember(const char *message, int sw);

#endif
