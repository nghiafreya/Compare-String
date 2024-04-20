#include <stdlib.h>
#include <stdbool.h>

extern bool isVerbose;
extern int Ncmp;

bool cmp(char, char);

/**
  * String matching using simple matching method.
  * @param text: text
  * @param pat: search pattern
  * @return The position where the match was successful. -1 if it fails.
  */
  
int naive(char* text, unsigned int textlen, char* pat, unsigned int patlen) {
    int i = 0; //i is the index of pattern
    int j = 0; //j is the index of text
    while (j < textlen) {
    Ncmp++;
    	if (pat[i] != text[j]) {
    		j = j - i + 1; //j firstly moves to the POSITION right next to the recent first matching character, then keeps going to the next position until a matching character is found
		i = 0; //i will remains 0 until a matching character is found
		}	else {
			if (i == patlen - 1) { //all pat[i]s are the same to text[j]s, which means pattern has found in text
				return j - patlen + 1; //the position of the pattern in texts
			} else {
				i++;
				j++;
			}
		}
	}
	return -1; //failed
}