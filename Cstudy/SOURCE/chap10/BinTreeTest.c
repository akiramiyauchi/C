/* �Q���T���؂̗��p�� */

/* ���K10-1�̊֐�PrintTreeReverse��
   ���K10-3�̊֐�GetMinNode,GetMaxNode�̃e�X�g��List10-3�ɒǉ� */

#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- ���j���[ ---*/
typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT, PRINT_REV, GET_MIN, GET_MAX
} Menu;

/*--- ���j���[�I�� ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n(1)�}�� (2)�폜 (3)�T�� (4)�\�� (5)�t���\�� (6)�ŏ� (7)�ő� (0)�I���F");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > GET_MAX);
	return (Menu)ch;
}

/*--- ���C���֐� ---*/
int main(void)
{
	Menu    menu;
	BinNode *root = NULL;		/* �Q���T���؂̍��ւ̃|�C���^ */

	do {
		Member x;
		BinNode *temp;

		switch (menu = SelectMenu()) {
		 /*--- �m�[�h�̑}�� ---*/
		 case ADD :
				x = ScanMember("�}��", MEMBER_NO | MEMBER_NAME);
				root = Add(root, &x);
				break;

		 /*--- �m�[�h�̍폜 ---*/
		 case REMOVE :
				x = ScanMember("�폜", MEMBER_NO);
				Remove(&root, &x);
				break;

		 /*--- �m�[�h�̒T�� ---*/
		 case SEARCH :
				x = ScanMember("�T��", MEMBER_NO);
				if ((temp = Search(root, &x)) != NULL)
					PrintLnMember(&temp->data);
				break;

		 /*--- �S�m�[�h�̕\�� ---*/
		 case PRINT :
				puts("�y�ꗗ�\�z");
				PrintTree(root);
				break;
		
		/*--- �S�m�[�h�̋t���\�� ---*/
		 case PRINT_REV :
				puts("�y�t���ꗗ�\�z");
				PrintTreeReverse(root);
				break;

		/*--- �ŏ��L�[�l ---*/
		 case GET_MIN :
				if ((temp = GetMinNode(root)) != NULL)
					PrintLnMember(&temp->data);
				break;

		/*--- �ő傫���L�[�l ---*/
		 case GET_MAX :
				if ((temp = GetMaxNode(root)) != NULL)
					PrintLnMember(&temp->data);
				break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}
