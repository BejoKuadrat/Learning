#include <stdio.h>

main(){
	int c, cnt;

	cnt = 0;
	while ((c = getchar()) != EOF){
		if (c == ' '){
			if (cnt == 0){
				cnt = 1;
				putchar(c);
			}
		}
		if (c != ' '){
			cnt = 0;
			putchar(c);
		}
	}
}
