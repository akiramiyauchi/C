/* 1,000�ȉ��̑f�������߂�i��R�Łj*/

#include <stdio.h>

int main(void)
{
	int i, n;
	int prime[500];							/* �f�����i�[����z�� */
	int ptr = 0;							/* ���ɓ���ꂽ�f���̌� */
	unsigned long counter = 0;				/* �揜�̉� */

	prime[ptr++] = 2;						/* �Q�͑f���ł��� */
	prime[ptr++] = 3;						/* �R�͑f���ł��� */

	for (n = 5; n <= 1000; n += 2) {		/* ��݂̂�ΏۂƂ��� */
		int flag = 0;
		for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
			counter++;
			if (n % prime[i] == 0)	{		/* ����؂��Ƒf���ł͂Ȃ� */
				flag = 1;
				break;						/* ����ȏ�̌J�Ԃ��͕s�v */
			}
		}
		if (!flag)							/* �Ō�܂Ŋ���؂�Ȃ����� */
			prime[ptr++] = n;				/* �z��ɓo�^ */
	}

	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);

	printf("�揜�Z���s�����񐔁F%lu\n", counter);

	return 0;
}
