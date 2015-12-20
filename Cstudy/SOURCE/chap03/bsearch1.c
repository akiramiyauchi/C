/* bsearch�֐��𗘗p���������ɕ��񂾔z�񂩂�̒T�� */

#include <stdio.h>
#include <stdlib.h>

/*--- �������r����֐��i�����p�j---*/
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
	int i, nx, ky;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */
	int *p;		/* �T�����ꂽ�v�f�ւ̃|�C���^ */

	puts("bsearch�֐��ɂ��T��");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* �v�f��nx��int�^�z��𐶐� */

	printf("�����ɓ��͂��Ă��������B\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);	/* ��O�̒l������������΍ē��� */
	}

	printf("�T���l : ");
	scanf("%d", &ky);

	p = bsearch(&ky,							/* �T���l�ւ̃|�C���^ */
				x,								/* �z�� */
				nx,								/* �v�f�� */
				sizeof(int),					/* �v�f�̑傫�� */
				(int (*)(const void *, const void *))int_cmp	/* ��r�֐� */
			   );

	if (p == NULL)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, (int)(p - x));

	free(x);	/* �z������ */

	return 0;
}
