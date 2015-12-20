/* int型集合IntSetの利用例（その１）*/

#include <stdio.h>
#include "IntSet.h"

int main(void)
{
	IntSet s1, s2, s3;
	Initialize(&s1, 24);
	Initialize(&s2, 24);
	Initialize(&s3, 24);

	Add(&s1, 10);	   /* s1 = {10}					*/
	Add(&s1, 15);	   /* s1 = {10, 15}				*/
	Add(&s1, 20);	   /* s1 = {10, 15, 20}			*/
	Add(&s1, 25);	   /* s1 = {10, 15, 20, 25}		*/

	Assign(&s2, &s1);  /* s2 = {10, 15, 20, 25}		*/
	Add(&s2, 12);	   /* s2 = {10, 15, 20, 25, 12} */
	Remove(&s2, 20);   /* s2 = {10, 15, 12, 25}		*/

	Assign(&s3, &s2);  /* s3 = {10, 15, 12, 25}		*/

	printf("s1 = ");   PrintLn(&s1);
	printf("s2 = ");   PrintLn(&s2);
	printf("s3 = ");   PrintLn(&s3);

	printf("集合s1に15は含まれ%s。\n", IsMember(&s1, 15) > 0 ? "る" : "ない");
	printf("集合s2に25は含まれ%s。\n", IsMember(&s2, 25) > 0 ? "る" : "ない");
	printf("集合s1とs2は等し%s。\n", Equal(&s1, &s2) ? "い" : "くない");
	printf("集合s2とs3は等し%s。\n", Equal(&s2, &s3) ? "い" : "くない");

	Terminate(&s1);
	Terminate(&s2);
	Terminate(&s3);

	return 0;
}
