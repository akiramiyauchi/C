/* KćlđÄAIÉßé */

#include <stdio.h>

/*--- ŽlnĚKćđÔp ---*/
int factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main(void)
{
	int x;

	printf("ŽđüÍšćF");
	scanf("%d", &x);

	printf("%dĚKćÍ%dĹˇB\n", x, factorial(x));

	return 0;
}
