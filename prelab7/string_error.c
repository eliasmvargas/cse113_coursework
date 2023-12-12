#include <stdio.h>

int main(void)
{
	//char s[] = "c run, run c run";
	 char *s = "c run, run c run"; /* This is a pointer to a string literal, and if you attemp to modify will result in a segmetation fault */


	char *p = s; 		/* p points to the beginning of s */

	printf("the original string:\n");
		printf("%s\n", s);

	while (*p != '\0') { 	/* dereference what p points to */
		if (*p == 'r')
			*p = 'f'; /* change the value */
		p++; 		/* increment the address */
	}

	printf("\nthe changed string:\n");
	printf("%s\n", s);

	return 0;
}
