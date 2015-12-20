/* �z��̕��� */

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �z��𕪊����� ---*/
void partition(int a[], int n)
{
	int i;
	int pl = 0;			/* ���J�[�\�� */
	int pr = n - 1;		/* �E�J�[�\�� */
	int x = a[n / 2];	/* �����͒����̗v�f */

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	printf("�����̒l��%d�ł��B\n", x);

	printf("�����ȉ��̃O���[�v\n");				/*-- �����ȉ��̃O���[�v --*/
	for (i = 0; i <= pl - 1; i++)				/* a[0] �` a[pl - 1] */
		printf("%d ", a[i]);
	putchar('\n');

	if (pl > pr + 1) {
		printf("�����ƈ�v����O���[�v\n");		/*-- �����Ɠ����O���[�v --*/
		for (i = pr + 1; i <= pl - 1; i++)		/* a[pr + 1] �` a[pl - 1] */
			printf("%d ", a[i]);
		putchar('\n');
	}

	printf("�����ȏ�̃O���[�v\n");				/*-- �����ȏ�̃O���[�v --*/
	for (i = pr + 1; i < n; i++)				/* a[pr + 1] �` a[n - 1] */
		printf("%d ", a[i]);
	putchar('\n');
}

int main(void)
{
	int i, nx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */

	puts("�z��𕪊����܂��B");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* �v�f��nx��int�^�z��𐶐� */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	partition(x, nx);				/* �z��x�𕪊� */

	free(x);	/* �z������ */

	return 0;
}
