/* �Q���T�� */

#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f���Q���T�� ---*/
int bin_search(const int a[], int n, int key)
{
	int pl = 0;			/* �T���͈͐擪�̓Y�� */
	int pr = n - 1;		/* �@ �V �@�����̓Y�� */
	int pc;				/* �@ �V �@�����̓Y�� */

	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key)		/* �T������ */
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while (pl <= pr);

	return -1;					/* �T�����s */
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */

	puts("�Q���T��");
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

	idx = bin_search(x, nx, ky);	/* �z��x����l��ky�ł���v�f���Q���T�� */

	if (idx == -1)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, idx);

	free(x);	/* �z������ */

	return 0;
}
