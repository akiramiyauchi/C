/* ������̒��������߂� */

#include <stdio.h>

/*--- ������s�̒��������߂�i���̂R�j---*/
int str_len(const char *s)
{
	const char *p = s;

	while (*s)
		s++;
	return s - p;
}

int main(void)
{
	char str[256];

	printf("������F");
	scanf("%s", str);

	printf("���̕������%d�����ł��B\n", str_len(str));

	return 0;
}
