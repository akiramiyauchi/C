/* �v�f�^��int�^�ŗv�f����5�̔z�� */

#include <stdio.h>

#define N 5						/* �z��̗v�f�� */

int main()
{
	int i;
	int a[N];					/* �z��̐錾 */

	for (i = 0; i < N; i++) {	/* �e�v�f�ɒl��ǂݍ��� */
		printf("a[%d] : ", i);
		scanf("%d", &a[i]);
	}

	puts("�e�v�f�̒l");
	for (i = 0; i < N; i++) {	/* �e�v�f�̒l��\�� */
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}
