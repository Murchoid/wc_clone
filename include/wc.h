#ifndef WC_CLONE_H
#define WC_CLONE_H

#include <stdio.h>

typedef struct {
    long lines;
    long words;
    long bytes;
}Counts;

#define FLAG_LINES  1   
#define FLAG_WORDS  2   
#define FLAG_BYTES  4   
#define BUFFER_SIZE 16384

int parse_args(int argc, char *argv[], int *file_start);
Counts process_file(FILE *fp);
void print_counts(Counts cnt, const char *filename, int flags);

#endif