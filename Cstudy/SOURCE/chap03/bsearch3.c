/* bsearch�֐��𗘗p�����\���̂̔z�񂩂�̒T�� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];	/* ���O */
	int  height;	/* �g�� */
	int  weight;	/* �̏d */
} Person;

/*--- Person�^�̔�r�֐��i���O�����j---*/
int npcmp(const Person *x, const Person *y)
{
	return strcmp(x->name, y->name);
}

int main(void)
{
	Person x[]= {					/* �z��̗v�f�͖��O�̏����� */
		{"ABE",      179, 79},		/* ����ł��Ȃ���΂Ȃ�Ȃ� */
		{"NANGOH",   172, 63},
		{"SHIBATA",  176, 52},
		{"SUGIYAMA", 165, 51},
		{"TAKAOKA",  181, 73},
		{"TSURUMI",  172, 84},
	};
	int nx = sizeof(x) / sizeof(x[0]);		/* �z��x�̗v�f�� */
	int retry;

	puts("���O�ɂ��T�����s���܂��B");

	do {
		Person temp, *p;

		printf("���O : ");
		scanf("%s", temp.name);

		p = bsearch(&temp, x, nx, sizeof(Person),
					(int (*)(const void *, const void *))npcmp);

		if (p == NULL)
			puts("�T���Ɏ��s���܂����B");
		else {
			puts("�T������!! �ȉ��̗v�f�������܂����B");
			printf("x[%d] : %s %dcm %dkg\n",
						(int)(p - x), p->name, p->height, p->weight);
		}

		printf("������x�T�����܂����H(1)�͂��^(0)������ : ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
