/* ���`���X�g�̗��p�� */

/* ���K9-1�̊֐�Purge�Ɖ��K9-2�̊֐�Retrieve�̃e�X�g��List9-3�ɒǉ� */

#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

/*--- ���j���[ ---*/
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR,  RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT,  SRCH_NO,   SRCH_NAME, PRINT_ALL, CLEAR,
	PURGE_NO, PURGE_NAME, RETRIEVE,
} Menu;

/*--- ���j���[�I�� ---*/
Menu SelectMenu(void)
{
	int  i, ch;
	char *mstring[] = {
		"�擪�Ƀm�[�h��}��", "�����Ƀm�[�h��}��",	"�擪�̃m�[�h���폜",
		"�����̃m�[�h���폜", "���ڃm�[�h��\��",	"���ڃm�[�h���폜",
		"�ԍ��ŒT��",		  "�����ŒT��",			"�S�m�[�h��\��",
		"�S�m�[�h���폜",	  "�ԍ�����m�[�h�폜", "��������m�[�h�폜",
		"n�Ԗڂ̃m�[�h"
	};

	do {
		for (i = TERMINATE; i < RETRIEVE; i++) {
			printf("(%2d) %-18.18s  ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) �I�� �F");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > RETRIEVE);

	return (Menu)ch;
}

/*--- ���C�� ---*/
int main(void)
{
	Menu menu;
	List list;

	Initialize(&list);				/* ���`���X�g�̏����� */

	do {
		int n;
		Member x;
		Member *ptr;

		switch (menu = SelectMenu()) {
		 /* �擪�Ƀm�[�h��}�� */
		 case INS_FRONT :
				x = ScanMember("�擪�ɑ}��", MEMBER_NO | MEMBER_NAME);
				InsertFront(&list, &x);
				break;

		 /* �����Ƀm�[�h��}�� */
		 case INS_REAR :
				x = ScanMember("�����ɑ}��", MEMBER_NO | MEMBER_NAME);
				InsertRear(&list, &x);
				break;

		 /* �擪�m�[�h���폜 */
		 case RMV_FRONT :
				RemoveFront(&list);
				break;

		 /* �����m�[�h���폜 */
		 case RMV_REAR :
				RemoveRear(&list);
				break;

		 /* ���ڃm�[�h�̃f�[�^��\�� */
		 case PRINT_CRNT :
				PrintLnCurrent(&list);
				break;

		 /* ���ڃm�[�h���폜 */
		 case RMV_CRNT :
				RemoveCurrent(&list);
				break;

		 /* �ԍ��ɂ��T�� */
		 case SRCH_NO :
				x = ScanMember("�T��", MEMBER_NO);
				if (Search(&list, &x, MemberNoCmp) != NULL)
					PrintLnCurrent(&list);
				else
					puts("���̔ԍ��̃f�[�^�͂���܂���B");
				break;

		 /* �����ɂ��T�� */
		 case SRCH_NAME :
				x = ScanMember("�T��", MEMBER_NAME);
				if (Search(&list, &x, MemberNameCmp) != NULL)
					PrintLnCurrent(&list);
				else
					puts("���̖��O�̃f�[�^�͂���܂���B");
				break;

		 /* �S�m�[�h�̃f�[�^��\�� */
		 case PRINT_ALL :
				Print(&list);
				break;

		 /* �S�m�[�h���폜 */
		 case CLEAR :
				Clear(&list);
				break;

		/* �ԍ�����v����S�m�[�h���폜 */
		 case PURGE_NO :
				Purge(&list, MemberNoCmp);
				break;

		/* ��������v����S�m�[�h���폜 */
		 case PURGE_NAME :
				Purge(&list, MemberNameCmp);
				break;

		/* n�Ԗڂ̃m�[�h��\�� */
		 case RETRIEVE :
				printf("�擪���牽���F");
				scanf("%d", &n);
				if ((ptr = Retrieve(&list, n)) != NULL)
					PrintLnMember(ptr);
				else
					puts("���̃f�[�^�͂���܂���B");
				break;
		}
	} while (menu != TERMINATE);

	Terminate(&list);							/* ���`���X�g�̌�n�� */

	return 0;
}
