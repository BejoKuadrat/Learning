#include <stdio.h>

#define IN 1
#define OUT 0

main(){
	int c, state;

	state = IN;
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			if (state == OUT)
				putchar('\n');
				state = IN;
		}
		else{
			putchar(c);
			state = OUT;
		}
	}
}
