/* 1,000ˆÈ‰º‚Ì‘f”‚ğ‹‚ß‚éi‘æ‚R”Åj*/

#include <stdio.h>

int main(void)
{
	int i, n;
	int prime[500];							/* ‘f”‚ğŠi”[‚·‚é”z—ñ */
	int ptr = 0;							/* Šù‚É“¾‚ç‚ê‚½‘f”‚ÌŒÂ” */
	unsigned long counter = 0;				/* æœ‚Ì‰ñ” */

	prime[ptr++] = 2;						/* ‚Q‚Í‘f”‚Å‚ ‚é */
	prime[ptr++] = 3;						/* ‚R‚Í‘f”‚Å‚ ‚é */

	for (n = 5; n <= 1000; n += 2) {		/* Šï”‚Ì‚İ‚ğ‘ÎÛ‚Æ‚·‚é */
		int flag = 0;
		for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
			counter++;
			if (n % prime[i] == 0)	{		/* Š„‚èØ‚ê‚é‚Æ‘f”‚Å‚Í‚È‚¢ */
				flag = 1;
				break;						/* ‚»‚êˆÈã‚ÌŒJ•Ô‚µ‚Í•s—v */
			}
		}
		if (!flag)							/* ÅŒã‚Ü‚ÅŠ„‚èØ‚ê‚È‚©‚Á‚½ */
			prime[ptr++] = n;				/* ”z—ñ‚É“o˜^ */
	}

	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);

	printf("æœZ‚ğs‚Á‚½‰ñ”F%lu\n", counter);

	return 0;
}
