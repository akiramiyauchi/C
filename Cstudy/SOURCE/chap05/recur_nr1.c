/* �ċA�ɑ΂��闝����[�߂邽�߂̐^�ɍċA�I�Ȋ֐� */

#include <stdio.h>

/*--- �֐�recur�i�����ċA�������j---*/
void recur(int n)
{
Top:
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
}

int main(void)
{
	int x;

	printf("��������͂���F");
	scanf("%d", &x);

	recur(x);

	return 0;
}
