/* strstr�֐��̗��p�� */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[256], s2[256];
	char *p;

	puts("strstr�֐�");

	printf("�e�L�X�g�F");
	scanf("%s", s1);

	printf("�p�^�[���F");
	scanf("%s", s2);

	p = strstr(s1, s2);		/* ������s1���當����s2��T�� */

	if (p == NULL)
		printf("�e�L�X�g���Ƀp�^�[���͑��݂��܂���B\n");
	else {
		int ofs = p - s1;
		printf("\n%s\n",  s1);
		printf("%*s|\n",  ofs, "");
		printf("%*s%s\n", ofs, "", s2);
	}

	return 0;
}