/* �͂܂����@�ɂ�镶����T�� */

#include <stdio.h>

/*--- �͂܂����@�ɂ�镶����T�� ---*/
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;		/* txt���Ȃ���J�[�\�� */
	int pp = 0;		/* pat���Ȃ���J�[�\�� */

	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		} else {
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	if (pat[pp] == '\0')
		return pt - pp;

	return -1;
}

int main(void)
{
	int  idx;
	char s1[256];		/* �e�L�X�g */
	char s2[256];		/* �p�^�[�� */

	puts("�͂܂����@");

	printf("�e�L�X�g�F");
	scanf("%s", s1);

	printf("�p�^�[���F");
	scanf("%s", s2);

	idx = bf_match(s1, s2);		/* ������s1���當����s2��͂܂����@�ŒT�� */

	if (idx == -1)
		puts("�e�L�X�g���Ƀp�^�[���͑��݂��܂���B");
	else
		printf("%d�����ڂɃ}�b�`���܂��B\n", idx + 1);

	return 0;
}
