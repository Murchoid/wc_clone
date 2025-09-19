#include "wc.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    int file_start;
    int flags = parse_args(argc, argv, &file_start);

    if(argc == file_start) {
        Counts cnt = process_file(stdin);
        print_counts(cnt,"",flags);
    }else {

        Counts total_count = {0, 0, 0};

        for(int i=file_start; i<argc; i++){

            FILE *fp = fopen(argv[i], "r");

            if(!fp) {
                perror(argv[i]);
                continue;
            }

            Counts cnt = process_file(fp);
            fclose(fp);

            print_counts(cnt, argv[i], flags);

            total_count.lines += cnt.lines;
            total_count.words += cnt.words;
            total_count.bytes += cnt.bytes;

        }

        if(argc -file_start > 1) {
            print_counts(total_count, "Total", flags);
        }
        
    }
}