/* �D���Ȍ������l��ǂݍ���ŗv�f��N�̔z��ɍŌ��N���i�[ */

#include <stdio.h>

#define N  10		/* �ۑ�����l�̌� */

int main()
{
	int i;
	int a[N];		/* �ǂݍ��񂾒l���i�[ */
	int cnt = 0;	/* �ǂݍ��񂾌� */
	int retry;		/* ������x�H */

	puts("��������͂��Ă��������B");

	do {
		printf("%d�ڂ̐��� : ", cnt + 1);
		scanf("%d", &a[cnt++ % N]);

		printf("�����܂����H�iYes�c1�^No�c0�j�F");
		scanf("%d", &retry);
	} while (retry == 1);

	i = cnt - N;
	if (i < 0) i = 0;

	for ( ; i < cnt; i++)
		printf("%2d�ڂ̐��� = %d\n", i + 1, a[i % N]);

	return 0;
}
