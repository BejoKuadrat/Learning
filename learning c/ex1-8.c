#include <stdio.h>

/* count lines in input */
main(){
	int c, nl, t, b;

	nl = 0;
	t = 0;
	b = 0;
	while ((c = getchar()) != EOF)
		if ( c == '\n')
			++nl;
		else if (c == ' ')
			++b;
		else if (c == '\t')
			++t;
	printf("new lines: %d\n", nl);
	printf("tabs	 : %d\n", t);
	printf("blanks	 : %d\n", b);
}
