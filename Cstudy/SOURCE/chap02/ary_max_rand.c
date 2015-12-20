/* �z��̗v�f�̍ő�l�����߂�i�l�͗����Ő����j*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a�̗v�f�̍ő�l�����߂� ---*/
int maxof(const int a[], int n)
{
	int i;
	int max = a[0];				/* �ő�l */

	for (i = 1; i < n; i++)
		if (a[i] > max) max = a[i];

	return max;
}

int main(void)
{
	int i;
	int *height;		/* �z��̐擪�v�f�ւ̃|�C���^ */
	int number;			/* �l�����z��height�̗v�f�� */

	printf("�l�� : ");
	scanf("%d", &number);

	height = calloc(number, sizeof(int));	/* �v�f��number�̔z��𐶐� */

	srand(time(NULL));						/* �������痐���̎�������� */
	for (i = 0; i < number; i++) {
		height[i] = 100 + rand() % 90;		/* 100�`189�̗����𐶐��E��� */
		printf("height[%d] = %d\n", i, height[i]);
	}

	printf("�ő�l��%d�ł��B\n", maxof(height, number));

	free(height);		/* �z��height����� */

	return 0;
}
