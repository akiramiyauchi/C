/* �����񂩂�̕����̒T�� */

#include <stdio.h>

/*--- ������s���當��c��T�� ---*/
int str_chr(const char *s, int c)
{
	int i = 0;

	c = (char)c;
	while (s[i] != c) {
		if (s[i] == '\0')		/* �T�����s */
			return -1;
		i++;
	}
	return i;					/* �T������ */
}

int main(void)
{
	char str[64];				/* ���̕����񂩂�T�� */
	char tmp[64];
	int  ch;					/* �T������ */
	int  idx;

	printf("������F");
	scanf("%s", str);

	printf("�T�������F");
	scanf("%s", tmp);			/* �������񕶎���Ƃ��ēǂݍ���� */
	ch = tmp[0];				/* ���̍ŏ��̕�����T�������Ƃ��� */

	if ((idx = str_chr(str, ch)) == -1)				/* �擪�̏o����T�� */
		printf("����'%c'�͕����񒆂ɑ��݂��܂���B\n", ch);
	else
		printf("����'%c'��%d�����ڂɑ��݂��܂��B\n", ch, idx + 1);

	return 0;
}
