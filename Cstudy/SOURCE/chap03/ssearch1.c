/* ���`�T�� */

#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f����`�T�� ---*/
int search(const int a[], int n, int key)
{
	int i = 0;

	while (1) {
		if (i == n)
			return -1;		/* �T�����s */
		if (a[i] == key)
			return i;		/* �T������ */
		i++;
	}
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */

	puts("���`�T��");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* �v�f��nx��int�^�z��𐶐� */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("�T���l : ");
	scanf("%d", &ky);

	idx = search(x, nx, ky);	/* �z��x����l��ky�ł���v�f����`�T�� */

	if (idx == -1)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, idx);

	free(x);	/* �z������ */

	return 0;
}
