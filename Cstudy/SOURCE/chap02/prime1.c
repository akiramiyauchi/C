/* 1,000ˆÈ‰º‚Ì‘f”‚ğ—ñ‹“i‘æ‚P”Åj*/

#include <stdio.h>

int main(void)
{
	int i, n;
	unsigned long counter = 0;	/* œZ‚Ì‰ñ” */

	for (n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {
			counter++;
			if (n % i == 0)		/* Š„‚èØ‚ê‚é‚Æ‘f”‚Å‚Í‚È‚¢ */
				break;			/* ‚»‚êˆÈã‚ÌŒJ•Ô‚µ‚Í•s—v */
		}
		if (n == i)				/* ÅŒã‚Ü‚ÅŠ„‚èØ‚ê‚È‚©‚Á‚½ */
			printf("%d\n", n);
	}

	printf("œZ‚ğs‚Á‚½‰ñ”F%lu\n", counter);

	return 0;
}
