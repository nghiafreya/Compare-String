#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

extern bool isVerbose;
extern int Ncmp;

bool cmp(char, char);

void compnext(char* pat, int* next);

/**
  * String matching using simple matching method.
  * @param text: text
  * @param pat: search pattern
  * @return The position where the match was successful. -1 if it fails.
  */
  
int kmp(char* text, unsigned int textlen, char* pat, unsigned int patlen) {
    int n = strlen(text);
    int m = strlen(pat);
    int i = 0;
    int j = 0;
    int next[m];    
    Ncmp = 0;
    
    compnext(pat, next);
    
	while (j < n) { //j < textlen
		//pat[i] and text[j] are not the same
		//while loop: find in pattern until find some pat[i] == text[j]
		Ncmp++;
		while (i >= 0 && pat[i] != text[j]) {
			i = next[i] - 1;
            }
						
	 // pat[i] == text[j]
		if (i != m - 1) { 
			i++;
			j++;
		} else {
			return j - m + 1; // success
		}							
			
	}
	return -1; //failed
}