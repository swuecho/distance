#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256 
#define TOT 1500000
/* can change the buffer size as well */
/* change to accomodate other sizes, change ONCE here */
int read_file_to_arr(char* filename, char** file_lines) {
    char* line = NULL;
    ssize_t read;
    size_t loc_n= 0;

    FILE* fp; 
    fp= fopen(filename, "r");
    if (fp == NULL)
       exit(EXIT_FAILURE);

    int i = 0;
    while ((read = getline(&line, &loc_n, fp)) != -1) {
        strcpy(file_lines[i], line);
        i++;
    } 
     
    fclose(fp);

    if (line)
       free(line);
    return i;
    
}

int main() {
    int total;
    char* filename = "./pb_cdr3_head.csv";

    char **file_lines;
    file_lines = malloc(TOT* sizeof(char*));
    int i = 0;
    for (i = 0; i < TOT; i++)
            file_lines[i] = malloc((BUF+1) * sizeof(char));
    total = read_file_to_arr(filename, file_lines);
    for(i = 0; i < total; i++)
        printf("%s", file_lines[i]);

    //free
    for (i = 0; i < TOT; i++)
            free(file_lines[i]);
    free(file_lines);
    return 0;

}
