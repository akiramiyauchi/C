/* �|�C���^�l����������֐� */

#include <stdio.h>

/*--- ��̃|�C���^������ ---*/
void swap_ptr(char **x, char **y)
{
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(void)
{
	char *s1 = "ABCD";		/* s1��"ABCD"�̐擪����'A'���w�� */
	char *s2 = "EFGH";		/* s2��"EFGH"�̐擪����'E'���w�� */

	printf("�|�C���^s1��\"%s\"���w���Ă��܂��B\n", s1);
	printf("�|�C���^s2��\"%s\"���w���Ă��܂��B\n", s2);

	swap_ptr(&s1, &s2);

	puts("\n�|�C���^s1��s2�̒l���������܂����B\n");

	printf("�|�C���^s1��\"%s\"���w���Ă��܂��B\n", s1);
	printf("�|�C���^s2��\"%s\"���w���Ă��܂��B\n", s2);

	return 0;
}
