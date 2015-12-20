/* int�^�X�^�b�NIntStack�̗��p�� */

#include <stdio.h>
#include "IntStack.h"

int main(void)
{
	IntStack s;

	if (Initialize(&s, 64) == -1) {
		puts("�X�^�b�N�̐����Ɏ��s���܂����B");
		return 1;
	}

	while (1) {
		int menu, x;

		printf("���݂̃f�[�^���F%d / %d\n", Size(&s), Capacity(&s));
		printf("(1)�v�b�V��  (2)�|�b�v�@(3)�s�[�N�@(4)�\���@(0) �I���F");
		scanf("%d", &menu);

		if (menu == 0) break;

		switch (menu) {
		 case 1: /*--- �v�b�V�� ---*/
				 printf("�f�[�^�F");
				 scanf("%d", &x);
				 if (Push(&s, x) == -1)
					puts("\a�G���|�F�v�b�V���Ɏ��s���܂����B");
				 break;

		 case 2: /*--- �|�b�v ---*/
				 if (Pop(&s, &x) == -1)
					puts("\a�G���|�F�|�b�v�Ɏ��s���܂����B");
				 else
					printf("�|�b�v�����f�[�^��%d�ł��B\n", x);
				 break;

		 case 3: /*--- �s�[�N ---*/
				 if (Peek(&s, &x) == -1)
					puts("\a�G���|�F�s�[�N�Ɏ��s���܂����B");
				 else
					printf("�s�[�N�����f�[�^��%d�ł��B\n", x);
				 break;

		 case 4: /*--- �\�� ---*/
				 Print(&s);
				 break;
		}
	}

	Terminate(&s);

	return 0;
}
