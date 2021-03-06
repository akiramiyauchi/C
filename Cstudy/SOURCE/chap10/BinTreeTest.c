/* QͺTυΨΜpα */

/* K10-1ΜΦPrintTreeReverseΖ
   K10-3ΜΦGetMinNode,GetMaxNodeΜeXgπList10-3ΙΗΑ */

#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- j[ ---*/
typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT, PRINT_REV, GET_MIN, GET_MAX
} Menu;

/*--- j[Iπ ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n(1)}ό (2)ν (3)Tυ (4)\¦ (5)t\¦ (6)Ε¬ (7)Εε (0)IΉF");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > GET_MAX);
	return (Menu)ch;
}

/*--- CΦ ---*/
int main(void)
{
	Menu    menu;
	BinNode *root = NULL;		/* QͺTυΨΜͺΦΜ|C^ */

	do {
		Member x;
		BinNode *temp;

		switch (menu = SelectMenu()) {
		 /*--- m[hΜ}ό ---*/
		 case ADD :
				x = ScanMember("}ό", MEMBER_NO | MEMBER_NAME);
				root = Add(root, &x);
				break;

		 /*--- m[hΜν ---*/
		 case REMOVE :
				x = ScanMember("ν", MEMBER_NO);
				Remove(&root, &x);
				break;

		 /*--- m[hΜTυ ---*/
		 case SEARCH :
				x = ScanMember("Tυ", MEMBER_NO);
				if ((temp = Search(root, &x)) != NULL)
					PrintLnMember(&temp->data);
				break;

		 /*--- Sm[hΜ\¦ ---*/
		 case PRINT :
				puts("yκ\z");
				PrintTree(root);
				break;
		
		/*--- Sm[hΜt\¦ ---*/
		 case PRINT_REV :
				puts("ytκ\z");
				PrintTreeReverse(root);
				break;

		/*--- Ε¬L[l ---*/
		 case GET_MIN :
				if ((temp = GetMinNode(root)) != NULL)
					PrintLnMember(&temp->data);
				break;

		/*--- Εε«’L[l ---*/
		 case GET_MAX :
				if ((temp = GetMaxNode(root)) != NULL)
					PrintLnMember(&temp->data);
				break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}
