/* �ǂݍ��񂾐����l�̕����i���^���^�O�j�𔻒� */

#include <stdio.h>

int main(void)
{
	int n;

	printf("��������͂���F");
	scanf("%d", &n);

	if (n > 0)
		printf("����͐��ł��B\n");
	else if (n < 0)
		printf("����͕��ł��B\n");
	else
		printf("����͂O�ł��B\n");

	return 0;
}
