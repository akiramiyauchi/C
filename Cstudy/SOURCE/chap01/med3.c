/* �O�̐����l��ǂݍ���Œ����l�����߂� */

#include <stdio.h>

/*--- a, b, c�̒����l�����߂� ---*/
int med3(int a, int b, int c)
{
	if (a >= b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}

int main(void)
{
	int a, b, c;

	printf("�O�̐����̒����l�����߂܂��B\n");
	printf("a�̒l�F");   scanf("%d", &a);
	printf("b�̒l�F");   scanf("%d", &b);
	printf("c�̒l�F");   scanf("%d", &c);

	printf("�����l��%d�ł��B\n", med3(a, b, c));

	return 0;
}
