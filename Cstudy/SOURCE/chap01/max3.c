/* �O�̐����l��ǂݍ���ōő�l�����߂� */

#include <stdio.h>

int main(void)
{
	int a, b, c;
	int max;				/* �ő�l */

	printf("�O�̐����̍ő�l�����߂܂��B\n");
	printf("a�̒l�F");   scanf("%d", &a);
	printf("b�̒l�F");   scanf("%d", &b);
	printf("c�̒l�F");   scanf("%d", &c);

	max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	printf("�ő�l��%d�ł��B\n", max);

	return 0;
}
