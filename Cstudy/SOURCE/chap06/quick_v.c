/* �N�C�b�N�\�[�g */

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �N�C�b�N�\�[�g�i�z��̕����ߒ���\���j---*/
void quick(int a[], int left, int right)
{
	int pl = left;				/* ���J�[�\�� */
	int pr = right;				/* �E�J�[�\�� */
	int x = a[(pl + pr) / 2];	/* �����i�����̗v�f�j*/

	int i;
	printf("a[%d]�`a[%d]�F{", left, right);
	for (i = left; i < right; i++)
		printf("%d , ", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr)  quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

int main(void)
{
	int i, nx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */

	puts("�N�C�b�N�\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	quick(x, 0, nx - 1);	/* �z��x���N�C�b�N�\�[�g */

	puts("�����Ƀ\�[�g���܂����B");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* �z������ */

	return 0;
}
