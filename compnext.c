#include <string.h>
#include <stdio.h>

int max(int left, int right) {
	if (left >= right) {
		return left;
	} else {
		return right;
	}
}

void compnext(char* pat, int* next) {  
    for (int a = 0; a < strlen(pat); a++) {
        next[a] = 0;
    }
    
	int i = 1; //i is index of pat'
	int j = 0; //j is index of pat

	
	while (i < strlen(pat)) {
		j = 0;
		while (j < i) j++;
		
		while (pat[j] == pat[j - i] && j < strlen(pat)) j++;
		
		//pat[j] != pat[j - i]		
			printf("j is %d , i is %d \n", j, i);
		    int k = max(0, j - i + 1);
		    printf("k is %d \n", k);
		    if (k >= next[j]) {	
				next[j] = k;				 
		 
			}
		i++;
	}
	
}