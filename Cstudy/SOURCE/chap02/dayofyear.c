/* �N���̌o�ߓ��������߂� */

#include <stdio.h>

/*- �e���̓��� -*/
int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/*--- ����year�N�͉[�N�� ---*/
int isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- ����y�Nm��d���̔N���̌o�ߓ��������߂� ---*/
int dayofyear(int y, int m, int d)
{
	int i;
	int days = d;		/* ���� */

	for (i = 1; i < m; i++)
		days += mdays[isleap(y)][i - 1];
	return days;
}

int main(void)
{
	int year, month, day;		/* �N�E���E�� */
	int retry;					/* ������x�H */

	do {
		printf("�N�F");   scanf("%d", &year);
		printf("���F");   scanf("%d", &month);
		printf("���F");   scanf("%d", &day);

		printf("�N����%d���ڂł��B\n", dayofyear(year, month, day));

		printf("������x���܂����i1�c�͂��^0�c�������j�F");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
