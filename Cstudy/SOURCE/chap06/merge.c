/* �}�[�W�\�[�g */

#include <stdio.h>
#include <stdlib.h>

static int *buff;			/* ��Ɨp�z�� */

/*--- �}�[�W�\�[�g�i���C�����j---*/
static void __mergesort(int a[], int left, int right)
{
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;

		__mergesort(a, left, center);			/* �O�������}�[�W�\�[�g */
		__mergesort(a, center + 1, right);		/* �㔼�����}�[�W�\�[�g */

		for (i = left; i <= center; i++)
			buff[p++] = a[i];

		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];

		while (j < p)
			a[k++] = buff[j++];
	}
}

/*--- �}�[�W�\�[�g ---*/
int mergesort(int a[], int n)
{
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;

	__mergesort(a, 0, n - 1);		/* �z��S�̂��}�[�W�\�[�g */

	free(buff);

	return 0;
}

int main(void)
{
	int i, nx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */

	puts("�}�[�W�\�[�g");
	printf("�v�f���F");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	mergesort(x, nx);		/* �z��x���}�[�W�\�[�g */

	puts("�����Ƀ\�[�g���܂����B");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* �z������ */

	return 0;
}
