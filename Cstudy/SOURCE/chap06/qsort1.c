/* qsort�֐��𗘗p���Đ����z��̗v�f��l�̏����Ƀ\�[�g */

#include <stdio.h>
#include <stdlib.h>

/*--- int�^�̔�r�֐��i�����\�[�g�p�j---*/
int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i, nx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */

	printf("qsort�ɂ��\�[�g\n");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* �v�f��nx��int�^�z��𐶐� */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	qsort(x,											/* �z�� */
		  nx,											/* �v�f�� */
		  sizeof(int),									/* �v�f�̑傫�� */
		  (int (*)(const void *, const void *))int_cmp	/* ��r�֐� */
		 );

	puts("�����Ƀ\�[�g���܂����B");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* �z������ */

	return 0;
}
