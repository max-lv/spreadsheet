
#include <stdio.h>
#include "constants.h"

int getword(char word[]);
int eq(char a[], char b[]);
void print_repeat(char c, int times);


int getword(char word[])
{
    int i=0;
    char c;
    while((c = getchar()) != ' ' && c != '\n' && c != EOF && i < WORD_MAXSIZE-1) {
        word[i] = c;
        ++i;
    }

    if(c==EOF) return -1;

    word[i] = '\0';
    return i;
}


int eq(char a[], char b[])
{
    int i=0;
    while(a[i] != '\0' && b[i] != '\0') {
        if(a[i] != b[i]) return 0;
        ++i;
    }
    if(a[i] == '\0' && b[i] == '\0')
        return 1;
    return 0;
}


void print_repeat(char c, int times)
{
    for(;times>0;--times) {
        printf("%c", c);
    }
    printf("\n");
}

