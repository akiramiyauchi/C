/* �z��̗v�f�̕��т𔽓]���� */

#include <stdio.h>
#include <stdlib.h>

/*--- type�^��x��y�̒l������ ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �v�f��n�̔z��a�̗v�f�̕��т𔽓] ---*/
void ary_reverse(int a[], int n)
{
	int i;

	for (i = 0; i < n / 2; i++)
		swap(int, a[i], a[n - i - 1]);
}

int main(void)
{
	int i;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */
	int nx;		/* �z��x�̗v�f�� */

	printf("�v�f���F");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* �v�f��nx��int�^�z��x�𐶐� */

	printf("%d�̐�������͂��Ă��������B\n", nx);
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_reverse(x, nx);				/* �z��x�̗v�f�̕��т𔽓] */

	printf("�z��̗v�f�̕��т𔽓]���܂����B\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);						/* �z��x����� */

	return 0;
}
