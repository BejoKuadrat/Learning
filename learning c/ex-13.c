#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 45

main(){
	int c, ws, wd, state;
	int length, array[MAX], maxlen;
	int i, j, tmp;

	state = IN;
	ws = wd  = length = maxlen = tmp = 0;

	//initialize the array
	for (i = 0; i < MAX; ++i)
		array[i] = 0;

	//count the word length and put it in array
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			++ws;
			state = OUT;
			if (length < MAX){
				if (length > maxlen)
					maxlen = length;
				++array[length];
			}
			length = 0;
		}
		else{
			++wd;
			++length;
			state = IN;
		}
	}

	printf("white spaces: %d | words: %d\n", ws, wd); // print out the counting result
	printf("print horizontally: \n");

	for (i = 1; i <= maxlen; ++i){ // initiate the loop
		printf("%5d %5d ", i, array[i]); // print out the identifier
		if (array[i] > 0) // if the array has value, put it in the temporary variable
			tmp = array[i];
		else		 // if the array has no value, set it back to zero
			tmp = 0;

		while (tmp > 0){ // while the temp variable has value, print out the stars for the graph
			putchar('*');
			--tmp; // keep printing until temp variable reaches zero
		}
		putchar('\n'); // jumps to the next line and then repeat if loop is true
	}

	printf("print vertically: \n");

	for (i = maxlen; i > 0; --i){ // initiate the horizontal value, ++ will result in upside down histogram
		for (j = 0; j <= maxlen ; ++j){ // initiate the vertical value, runs through the list
			if (array[j] >= i) // if the array has value, prints out the stars
				putchar('*');
			else		  // if the array has no value, prints blanks 
				putchar(' ');
		}
		putchar('\n'); // jumps to the next line and then repeat if loop is true
	}
}
// the vertical part can use a bit more fine tuning, but it works well enough

