/* ������̔�r�istrncmp�֐��j*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char st[128];

	puts("\"STRING\"�̐擪3�����Ɣ�r���܂��B");
	puts("\"XXXX\"�ŏI�����܂��B");

	while (1) {
		printf("������st�F");
		scanf("%s", st);

		if (strncmp("XXXX", st, 3) == 0)
			break;
		printf("strncmp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));
	}

	return 0;
}
