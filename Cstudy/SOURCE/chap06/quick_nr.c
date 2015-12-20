/* �N�C�b�N�\�[�g */

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �N�C�b�N�\�[�g�i��ċA�Łj---*/
void quick(int a[], int left, int right)
{
	IntStack lstack;		/* �������ׂ��擪�v�f�̓Y���̃X�^�b�N */
	IntStack rstack;		/* �������ׂ������v�f�̓Y���̃X�^�b�N */

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left),  left);		/* ���J�[�\�� */
		int pr = (Pop(&rstack, &right), right);		/* �E�J�[�\�� */
		int x = a[(left + right) / 2];				/* �����͒����̗v�f */

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);	/* ���O���[�v�͈̔͂� */
			Push(&rstack, pr);		/* �Y�����v�b�V�� */
		}
		if (pl < right) {
			Push(&lstack, pl);		/* �E�O���[�v�͈̔͂� */
			Push(&rstack, right);	/* �Y�����v�b�V�� */
		}
	}
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
