/* �P���}���\�[�g */

#include <stdio.h>
#include <stdlib.h>

/*--- �P���}���\�[�g ---*/
void insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void)
{
	int i, nx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */

	puts("�P���}���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* �v�f��nx��int�^�z��𐶐� */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);				/* �z��x��P���}���\�[�g */

	puts("�����Ƀ\�[�g���܂����B");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* �z������ */

	return 0;
}
