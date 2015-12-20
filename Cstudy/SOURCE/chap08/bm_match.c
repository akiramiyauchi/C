/* Boyer-Moore法による文字列探索 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

/*--- Boyer-Moore法による文字列探索 ---*/
int bm_match(const char txt[], const char pat[])
{
	int pt;							/* txtをなぞるカーソル */
	int pp;							/* patをなぞるカーソル */
	int txt_len = strlen(txt);		/* txtの文字数 */
	int pat_len = strlen(pat);		/* patの文字数 */
	int skip[UCHAR_MAX + 1];		/* スキップテーブル */

	for (pt = 0; pt <= UCHAR_MAX; pt++)		/* スキップテーブルの作成 */
		skip[pt] = pat_len;
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;
											/* pt == pat_len - 1 である */
	while (pt < txt_len) {
		pp = pat_len - 1;					/* patの最後の文字に着目 */

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
	char s1[256];		/* テキスト */
	char s2[256];		/* パターン */

	puts("Boyer-Moore法");

	printf("テキスト：");
	scanf("%s", s1);

	printf("パターン：");
	scanf("%s", s2);

	idx = bm_match(s1, s2);	/* 文字列s1から文字列s2をBoyer-Moore法で探索 */

	if (idx == -1)
		puts("テキスト中にパターンは存在しません。");
	else
		printf("%d文字目にマッチします。\n", idx + 1);

	return 0;
}
