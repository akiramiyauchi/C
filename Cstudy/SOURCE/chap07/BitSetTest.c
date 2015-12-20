/* �r�b�g�x�N�g���ɂ�鐮���W���̗��p�� */

#include <stdio.h>
#include "BitSet.h"

enum { ADD, RMV, SCH };

/*--- �f�[�^�Ǎ��� ---*/
int scan_data(int sw)
{
	int data;

	switch (sw) {
	 case ADD: printf("�ǉ�����f�[�^�F");  break;
	 case RMV: printf("�폜����f�[�^�F");  break;
	 case SCH: printf("�T������f�[�^�F");  break;
	}
	scanf("%d", &data);

	return data;
}

int main(void)
{
	BitSet s1 = BitSetNull;
	BitSet s2 = BitSetNull;

	while (1) {
		int m, x, idx;

		printf("s1 = ");   PrintLn(s1);
		printf("s2 = ");   PrintLn(s2);
		printf("(1)s1�ɒǉ� (2)s1����폜 (3)s1����T�� (4)s1��s2 (5)�e�퉉�Z\n"
			   "(6)s2�ɒǉ� (7)s2����폜 (8)s2����T�� (9)s2��s1 (0)�I���F");
		scanf("%d", &m);

		if (m == 0) break;

		switch (m) {
		 case 1: x = scan_data(ADD);  Add(&s1, x);		break;	/* s1�ɒǉ� */

		 case 2: x = scan_data(RMV);  Remove(&s1, x);	break;	/* s1����폜 */

		 case 3: x = scan_data(SCH);  idx = IsMember(s1, x);	/* s1����T��*/
				 printf("s1�Ɋ܂܂�Ă���%s�B\n", idx != 0 ? "��" : "����"); break;

		 case 4: s1 = s2;	break;		/* s2��s1�ɑ�� */

		 case 5: printf("s1 == s2 = %s\n", s1 == s2 ? "true" : "false");
				 printf("s1 &  s2 = ");  PrintLn(s1 & s2);
				 printf("s1 |  s2 = ");  PrintLn(s1 | s2);
				 printf("s1 -  s2 = ");  PrintLn(s1 & ~s2);
				 printf("s1 �� s2 = ");  PrintLn(s1 & ~s2 | ~s1 & s2);	/* �Ώۍ� */
				 break;

		 case 6: x = scan_data(ADD);  Add(&s2, x);		break;	/* s2�ɒǉ� */

		 case 7: x = scan_data(RMV);  Remove(&s2, x);	break;	/* s2����폜 */

		 case 8: x = scan_data(SCH);  idx = IsMember(s2, x);	/* s2����T�� */
				 printf("s2�Ɋ܂܂�Ă���%s�B\n", idx != 0 ? "��" : "����"); break;

		 case 9: s2 = s1;	break;		/* s1��s2�ɑ�� */
		}
	}

	return 0;
}
