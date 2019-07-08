#include <stdio.h>

#define CELL_SIZE 10
#define CELLS_NUM 10
#define WORD_MAXSIZE 50

#define MODE_CMD 0
#define MODE_PUT 1
#define MODE_CONTENT 2

int getword(char word[]);
void print_sheet(char cells[]);
int eq(char a[], char b[]);
void print_repeat(char c, int times);

int main()
{
    char cells[CELL_SIZE*CELLS_NUM];
    char word[WORD_MAXSIZE];
    int len;
    int mode = MODE_CMD;
    int cell_ptr = 0;
    int i;

    for(i=0; i<CELLS_NUM; i++) {
        cells[CELL_SIZE*i] = '\0';
    }

    /* Input loop */
    do {
        if(len > 0) {
            if(mode == MODE_CMD) {
                if(eq(word, "q\0")) {
                    return 0;
                } else if(eq(word, "put\0")) {
                    mode = MODE_PUT;
                } else {
                }
            } else if(mode == MODE_PUT) {
                cell_ptr = word[0] - 'a';
                if(cell_ptr<0 || cell_ptr>=CELLS_NUM) return 1;
                mode = MODE_CONTENT;
            } else if(mode == MODE_CONTENT) {
                for(i=0; i<CELL_SIZE-1 && word[i] != '\0'; i++) {
                    cells[cell_ptr*CELL_SIZE + i] = word[i];
                }
                cells[cell_ptr*CELL_SIZE + i] = '\0';
                mode = MODE_CMD;
            } else {
            }
        }
        
        if(mode == MODE_CMD) {
            print_repeat('-', 40);
            print_sheet(cells);
        }

    } while((len=getword(word)) != -1);

    return 0;
}


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


void print_sheet(char cells[])
{
    char c;
    for(int i=0; i<CELLS_NUM; i++) {
        printf("%c: ", i+'a');
        for(int j=0; j<CELL_SIZE; j++) {
            c = cells[i*CELL_SIZE + j];
            if(c == '\0') break;
            printf("%c", c);
        }
        printf("\n");
    }
}


void print_repeat(char c, int times)
{
    for(;times>0;--times) {
        printf("%c", c);
    }
    printf("\n");
}
