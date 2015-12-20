/* Boyer-Moore�@�ɂ�镶����T�� */

#include <stdio.h>
#include <string.h>
#include <limits.h>

/*--- Boyer-Moore�@�ɂ�镶����T�� ---*/
int bm_match(const char txt[], const char pat[])
{
	int pt;							/* txt���Ȃ���J�[�\�� */
	int pp;							/* pat���Ȃ���J�[�\�� */
	int txt_len = strlen(txt);		/* txt�̕����� */
	int pat_len = strlen(pat);		/* pat�̕����� */
	int skip[UCHAR_MAX + 1];		/* �X�L�b�v�e�[�u�� */

	for (pt = 0; pt <= UCHAR_MAX; pt++)		/* �X�L�b�v�e�[�u���̍쐬 */
		skip[pt] = pat_len;
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;
											/* pt == pat_len - 1 �ł��� */
	while (pt < txt_len) {
		pp = pat_len - 1;					/* pat�̍Ō�̕����ɒ��� */

		while (txt[pt] == pat[pp]) {
			if (pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}

	return -1;
}

int main(void)
{
	int  idx;
	char s1[256];		/* �e�L�X�g */
	char s2[256];		/* �p�^�[�� */

	puts("Boyer-Moore�@");

	printf("�e�L�X�g�F");
	scanf("%s", s1);

	printf("�p�^�[���F");
	scanf("%s", s2);

	idx = bm_match(s1, s2);	/* ������s1���當����s2��Boyer-Moore�@�ŒT�� */

	if (idx == -1)
		puts("�e�L�X�g���Ƀp�^�[���͑��݂��܂���B");
	else
		printf("%d�����ڂɃ}�b�`���܂��B\n", idx + 1);

	return 0;
}
