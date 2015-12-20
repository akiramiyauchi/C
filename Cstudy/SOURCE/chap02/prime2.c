/* 1,000ˆÈ‰º‚Ì‘f”‚ğ—ñ‹“i‘æ‚Q”Åj*/

#include <stdio.h>

int main(void)
{
	int i, n;
	int prime[500];						/* ‘f”‚ğŠi”[‚·‚é”z—ñ */
	int ptr = 0;						/* Šù‚É“¾‚ç‚ê‚½‘f”‚ÌŒÂ” */
	unsigned long counter = 0;			/* œZ‚Ì‰ñ” */

	prime[ptr++] = 2;					/* ‚Q‚Í‘f”‚Å‚ ‚é */

	for (n = 3; n <= 1000; n += 2) {	/* Šï”‚Ì‚İ‚ğ‘ÎÛ‚Æ‚·‚é */
		for (i = 1; i < ptr; i++) {		/* Šù‚É“¾‚ç‚ê‚½‘f”‚ÅŠ„‚Á‚Ä‚İ‚é */
			counter++;
			if (n % prime[i] == 0)		/* Š„‚èØ‚ê‚é‚Æ‘f”‚Å‚Í‚È‚¢ */
				break;					/* ‚»‚êˆÈã‚ÌŒJ•Ô‚µ‚Í•s—v */
		}
		if (ptr == i)					/* ÅŒã‚Ü‚ÅŠ„‚èØ‚ê‚È‚©‚Á‚½ */
			prime[ptr++] = n;			/* ”z—ñ‚É“o˜^ */
	}

	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);

	printf("œZ‚ğs‚Á‚½‰ñ”F%lu\n", counter);

	return 0;
}
