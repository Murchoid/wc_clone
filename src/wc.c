#include "wc.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parse_args(int argc, char *argv[], int *file_start) {
    int flags = 0;
    *file_start = 1;

    if(argc > 1 && argv[1][0] == '-') {
        for(char *p= argv[1] + 1; *p; p++) {
            switch (*p) {
                case 'l': flags |= FLAG_LINES; break;
                case 'w': flags |= FLAG_WORDS; break;
                case 'c': flags |= FLAG_BYTES; break;
                default:
                    fprintf(stderr, "Unknown option: -%c\n", *p);
                    exit(1);
            }
        }
        *file_start = 2;
    }

    if(flags == 0) {
        flags = FLAG_BYTES | FLAG_LINES | FLAG_WORDS;
    }

    return flags;
}

Counts process_file(FILE *fp) {
    Counts cnt = {0,0,0};

    int ch = 0;
    int mark_word = 0;

    while((ch = fgetc(fp)) != EOF) {
        cnt.bytes++;

        if(ch == '\n') {
            cnt.lines++;
        }
        
        if(isspace(ch)) {
            mark_word = 0;
        } else if(!mark_word) {
            cnt.words++;
            mark_word = 1;
        }
        
        
    }
    cnt.lines++;

    return cnt;

}

void print_counts(Counts c, const char *filename, int flags) {
    if (flags & FLAG_LINES) printf("%8ld ", c.lines);
    if (flags & FLAG_WORDS) printf("%8ld ", c.words);
    if (flags & FLAG_BYTES) printf("%8ld ", c.bytes);
    printf("%s\n", filename);
}
