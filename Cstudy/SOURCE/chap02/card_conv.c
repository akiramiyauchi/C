/* ������2�i���`36�i���Ɋ�ϊ� */

#include <stdio.h>

/*--- �����lx��n�i���ɕϊ����Ĕz��d�ɉ��ʌ�����i�[ ---*/
int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int  digits = 0;						/* �ϊ���̌��� */

	if (x == 0)								/* 0�ł���� */
		d[digits++] = dchar[0];				/* �ϊ����0 */
	else
		while (x) {
			d[digits++] = dchar[x % n];		/* n�Ŋ�������]���i�[ */
			x /= n;
		}
	return digits;
}

int main(void)
{
	int      i;
	unsigned no;		/* �ϊ����鐮�� */
	int      cd;		/* � */
	int      dno;		/* �ϊ���̌��� */
	char     cno[512];	/* �ϊ���̐��l�̊e���̐������i�[���镶���̔z�� */
	int      retry;		/* ������x�H */

	puts("10�i������ϊ����܂��B");

	do {
		printf("�ϊ�����񕉂̐����F");
		scanf("%u", &no);

		do {
			printf("���i���ɕϊ����܂����i2-36�j�F");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_convr(no, cd, cno);		/* no��cd�i���ɕϊ� */

		printf("%d�i���ł�", cd);
		for (i = dno - 1; i >= 0; i--)		/* ��ʌ����珇�ɕ\�� */
			printf("%c", cno[i]);
		printf("�ł��B\n");

		printf("������x���܂����i1�c�͂��^0�c�������j�F");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
