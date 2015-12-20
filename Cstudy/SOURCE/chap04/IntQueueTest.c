/* int�^�L���[IntQueue�̗��p�� */

#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("�L���[�̐����Ɏ��s���܂����B");
		return 1;
	}

	while (1) {
		int m, x;
		int idx;

		printf("���݂̃f�[�^���F%d / %d\n", Size(&que), Capacity(&que));
		printf("(1)�G���L���[ (2)�f�L���[ (3)�s�[�N (4)�\�� 5)�T�� 6)�N���A 7)��/���t (0)�I��:");
		scanf("%d", &m);

		if (m == 0) break;

		switch (m) {
		 case 1: /*--- �G���L���[ ---*/
				 printf("�f�[�^�F");   scanf("%d", &x);
				 if (Enque(&que, x) == -1)
					puts("\a�G���[�F�G���L���[�Ɏ��s���܂����B");
				 break;

		 case 2: /*--- �f�L���[ ---*/
				 if (Deque(&que, &x) == -1)
					puts("\a�G���[�F�f�L���[�Ɏ��s���܂����B");
				 else
					printf("�f�L���[�����f�[�^��%d�ł��B\n", x);
				 break;

		 case 3: /*--- �s�[�N ---*/
				 if (Peek(&que, &x) == -1)
					puts("\a�G���[�F�s�[�N�Ɏ��s���܂����B");
				 else
					printf("�s�[�N�����f�[�^��%d�ł��B\n", x);
				 break;

		 case 4: /*--- �\�� ---*/
				 Print(&que);
				 break;

		 case 5: /*--- �T�� ---*/
				 printf("�T������f�[�^�F");
				 scanf("%d", &x);
				 if ((idx = Search(&que, x)) == -1)
					puts("\a�G���|�F�T���Ɏ��s���܂����B");
				 else {
					 printf("���̃f�[�^�͓Y��%d�̈ʒu�ɂ���܂��B\n", idx);
					 printf("�L���[�̐擪�v�f����%d���̈ʒu�ł��B\n", Search2(&que, x));
				 }
				 break;

		 case 6: /*--- �N���A ---*/
				 Clear(&que);
				 break;

		 case 7: /*--- ��^���t�̔��� ---*/
				 printf("�X�^�b�N�͋�%s�B\n",   IsEmpty(&que) ? "�ł�" : "�ł͂���܂���");
				 printf("�X�^�b�N�͖��t%s�B\n", IsFull(&que)  ? "�ł�" : "�ł͂���܂���");
				 break;
		}
	}

	Terminate(&que);

	return 0;
}
