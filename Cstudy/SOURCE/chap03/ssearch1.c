/* üŒ`’Tõ */

#include <stdio.h>
#include <stdlib.h>

/*--- —v‘f”n‚Ì”z—ña‚©‚çkey‚Æˆê’v‚·‚é—v‘f‚ğüŒ`’Tõ ---*/
int search(const int a[], int n, int key)
{
	int i = 0;

	while (1) {
		if (i == n)
			return -1;		/* ’Tõ¸”s */
		if (a[i] == key)
			return i;		/* ’Tõ¬Œ÷ */
		i++;
	}
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;		/* ”z—ñ‚Ìæ“ª—v‘f‚Ö‚Ìƒ|ƒCƒ“ƒ^ */

	puts("üŒ`’Tõ");
	printf("—v‘f” : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* —v‘f”nx‚ÌintŒ^”z—ñ‚ğ¶¬ */

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("’T‚·’l : ");
	scanf("%d", &ky);

	idx = search(x, nx, ky);	/* ”z—ñx‚©‚ç’l‚ªky‚Å‚ ‚é—v‘f‚ğüŒ`’Tõ */

	if (idx == -1)
		puts("’Tõ‚É¸”s‚µ‚Ü‚µ‚½B");
	else
		printf("%d‚Íx[%d]‚É‚ ‚è‚Ü‚·B\n", ky, idx);

	free(x);	/* ”z—ñ‚ğ‰ğ•ú */

	return 0;
}
