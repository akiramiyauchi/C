/* KMP�@�ɂ�镶����T�� */

#include <stdio.h>

/*--- KMP�@�ɂ�镶����T�� ---*/
int kmp_match(const char txt[], const char pat[])
{
	int pt = 1;			/* txt���Ȃ���J�[�\�� */
	int pp = 0;			/* pat���Ȃ���J�[�\�� */
	int skip[1024];		/* �X�L�b�v�e�[�u�� */

	skip[pt] = 0;
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if (pp == 0)
			skip[++pt] = pp;
		else
			pp = skip[pp];
	}

	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++; pp++;
		} else if (pp == 0)
			pt++;
		else
			pp = skip[pp];
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

	puts("KMP�@");

	printf("�e�L�X�g�F");
	scanf("%s", s1);

	printf("�p�^�[���F");
	scanf("%s", s2);

	idx = kmp_match(s1, s2);	/* ������s1���當����s2��KMP�@�ŒT�� */

	if (idx == -1)
		puts("�e�L�X�g���Ƀp�^�[���͑��݂��܂���B");
	else
		printf("%d�����ڂɃ}�b�`���܂��B\n", idx + 1);

	return 0;
}
