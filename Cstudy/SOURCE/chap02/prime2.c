/* 1,000�ȉ��̑f����񋓁i��Q�Łj*/

#include <stdio.h>

int main(void)
{
	int i, n;
	int prime[500];						/* �f�����i�[����z�� */
	int ptr = 0;						/* ���ɓ���ꂽ�f���̌� */
	unsigned long counter = 0;			/* ���Z�̉� */

	prime[ptr++] = 2;					/* �Q�͑f���ł��� */

	for (n = 3; n <= 1000; n += 2) {	/* ��݂̂�ΏۂƂ��� */
		for (i = 1; i < ptr; i++) {		/* ���ɓ���ꂽ�f���Ŋ����Ă݂� */
			counter++;
			if (n % prime[i] == 0)		/* ����؂��Ƒf���ł͂Ȃ� */
				break;					/* ����ȏ�̌J�Ԃ��͕s�v */
		}
		if (ptr == i)					/* �Ō�܂Ŋ���؂�Ȃ����� */
			prime[ptr++] = n;			/* �z��ɓo�^ */
	}

	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);

	printf("���Z���s�����񐔁F%lu\n", counter);

	return 0;
}
