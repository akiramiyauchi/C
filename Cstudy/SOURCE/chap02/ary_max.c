/* �z��̗v�f�̍ő�l�����߂�i�l��ǂݍ��ށj*/

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

	printf("%d�l�̐g������͂��Ă��������B\n", number);
	for (i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf("%d", &height[i]);
	}

	printf("�ő�l��%d�ł��B\n", maxof(height, number));

	free(height);		/* �z��height����� */

	return 0;
}
