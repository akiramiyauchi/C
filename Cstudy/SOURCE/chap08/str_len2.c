/* ������̒��������߂� */

#include <stdio.h>

/*--- ������s�̒��������߂�i���̂Q�j---*/
int str_len(const char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return len;
}

int main(void)
{
	char str[256];

	printf("������F");
	scanf("%s", str);

	printf("���̕������%d�����ł��B\n", str_len(str));

	return 0;
}
