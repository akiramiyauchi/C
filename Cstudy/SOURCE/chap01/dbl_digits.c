/* �Q���̐��̐����l�i10�`99�j��ǂݍ��� */

#include <stdio.h>

int main(void)
{
	int no;

	printf("�Q���̐����l����͂��Ă��������B\n");

	do {
		printf("�l�́F");
		scanf("%d", &no);
	} while (no < 10 || no > 99);

	printf("�ϐ�no�̒l��%d�ɂȂ�܂����B\n", no);

	return 0;
}
