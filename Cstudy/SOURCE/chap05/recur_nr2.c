/* �ċA�ɑ΂��闝����[�߂邽�߂̐^�ɍċA�I�Ȋ֐� */

#include <stdio.h>
#include "IntStack.h"

/*--- �֐�recur�i�ċA�������j---*/
void recur(int n)
{
	IntStack stk;				/* �X�^�b�N */
	Initialize(&stk, 100);
Top:
	if (n > 0) {
		Push(&stk, n);			/* n�̒l���v�b�V�� */
		n = n - 1;
		goto Top;
	}

	if (!IsEmpty(&stk)) {		/* �X�^�b�N����łȂ���� */
		Pop(&stk, &n);			/* �l��ۑ����Ă���n���|�b�v */
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
	Terminate(&stk);
}

int main(void)
{
	int x;

	printf("��������͂���F");
	scanf("%d", &x);

	recur(x);

	return 0;
}
