/* �n�m�C�̓� */

#include <stdio.h>

/*--- �~��[1]�`�~��[no]��x������y���ֈړ� ---*/
void move(int no, int x, int y)
{
	if (no > 1)
		move(no - 1, x, 6 - x - y);		/* �O���[�v���J�n�����璆�Ԏ��� */

	printf("�~��[%d]��%d������%d���ֈړ�\n", no, x, y);	/* ���ړI���� */

	if (no > 1)
		move(no - 1, 6 - x - y, y);		/* �O���[�v�𒆊Ԏ�����ړI���� */
}

int main(void)
{
	int n;		/* �~�Ղ̖��� */

	printf("�n�m�C�̓�\n�~�Ղ̖����F");
	scanf("%d", &n);

	move(n, 1, 3);

	return 0;
}
