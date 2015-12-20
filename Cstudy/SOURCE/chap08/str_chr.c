/* •¶š—ñ‚©‚ç‚Ì•¶š‚Ì’Tõ */

#include <stdio.h>

/*--- •¶š—ñs‚©‚ç•¶šc‚ğ’Tõ ---*/
int str_chr(const char *s, int c)
{
	int i = 0;

	c = (char)c;
	while (s[i] != c) {
		if (s[i] == '\0')		/* ’Tõ¸”s */
			return -1;
		i++;
	}
	return i;					/* ’Tõ¬Œ÷ */
}

int main(void)
{
	char str[64];				/* ‚±‚Ì•¶š—ñ‚©‚ç’Tõ */
	char tmp[64];
	int  ch;					/* ’T‚·•¶š */
	int  idx;

	printf("•¶š—ñF");
	scanf("%s", str);

	printf("’T‚·•¶šF");
	scanf("%s", tmp);			/* ‚¢‚Á‚½‚ñ•¶š—ñ‚Æ‚µ‚Ä“Ç‚İ‚ñ‚Å */
	ch = tmp[0];				/* ‚»‚ÌÅ‰‚Ì•¶š‚ğ’Tõ•¶š‚Æ‚·‚é */

	if ((idx = str_chr(str, ch)) == -1)				/* æ“ª‚ÌoŒ»‚ğ’Tõ */
		printf("•¶š'%c'‚Í•¶š—ñ’†‚É‘¶İ‚µ‚Ü‚¹‚ñB\n", ch);
	else
		printf("•¶š'%c'‚Í%d•¶š–Ú‚É‘¶İ‚µ‚Ü‚·B\n", ch, idx + 1);

	return 0;
}
