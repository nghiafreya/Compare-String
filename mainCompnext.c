#include <stdio.h>
#include <string.h>

void compnext(char* pat, int* next);

int main(int argc, char** argv) {
    char pattern[100]; // Maximum length for the pattern string
    int next[100];     // Maximum length for the next array
    
    // Input the pattern string from the user
    printf("Enter the pattern string: ");
    scanf("%s", pattern);

    // Compute the next array
    compnext(pattern, next);

    // Print the next array
    printf("Next array: ");
    for (int i = 0; i < strlen(pattern); i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    return 0;
}
