/* 1, 2, �c, n�̘a�����߂�iwhile���j*/

#include <stdio.h>

int main(void)
{
	int i, n;
	int sum;				/* �a */

	puts("1����n�܂ł̘a�����߂܂��B");

	printf("n�̒l�F");
	scanf("%d", &n);

	sum = 0;
	i = 1;

	while (i <= n) {	/* i��n�ȉ��ł���ΌJ��Ԃ� */
		sum += i;			/* sum��i�������� */
		i++;				/* i�̒l���C���N�������g */
	}
	printf("1����%d�܂ł̘a��%d�ł��B\n", n, sum);

	return 0;
}
