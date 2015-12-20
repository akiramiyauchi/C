/* �x���\�[�g */

#include <stdio.h>
#include <stdlib.h>

/*--- �x���\�[�g�i�z��v�f�̒l��0�ȏ�max�ȉ��j---*/
void fsort(int a[], int n, int max)
{
	int i;
	int *f = calloc(max + 1, sizeof(int));		/* �ݐϓx�� */
	int *b = calloc(n,       sizeof(int));		/* ��Ɨp�ړI�z�� */

	for (i = 0;		i <= max; i++) f[i] = 0;			  /* [Step0] */
	for (i = 0;		i < n;	  i++) f[a[i]]++;			  /* [Step1] */
	for (i = 1;		i <= max; i++) f[i] += f[i - 1];	  /* [Step2] */
	for (i = n - 1; i >= 0;	  i--) b[--f[a[i]]] = a[i];	  /* [Step3] */
	for (i = 0;		i < n;	  i++) a[i] = b[i];			  /* [Step4] */

	free(b);
	free(f);
}

int main(void)
{
	int i, nx;
	int *x;		/* �z��̐擪�v�f�ւ̃|�C���^ */
	const int max = 100;			/* �ő�l */

	puts("�x���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("0�`%d�̐�������͂���B\n", max);
	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}

	fsort(x, nx, max);		/* �z��x��x���\�[�g */

	puts("�����Ƀ\�[�g���܂����B");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	/* �z������ */

	return 0;
}
