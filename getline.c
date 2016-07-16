#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// input: IGHV1-18,IGHJ4,IGHD2-15,CARPIGYCSVGSCYFDCW,2,103_d_CSF_UNS_NA_BCR_IgG
// output: CARPIGYCSVGSCYFDCW
char* cdr3_from_line(char * line) {



}

int main(int argc, char * argv[])
   {
     char *filename;
     FILE * fp;
     char * line = NULL;
     size_t len = 0;
     ssize_t read;
     int line_num = 0;

     filename = argv[1];

     fp = fopen(filename, "r");
     if (fp == NULL)
       exit(EXIT_FAILURE);

     while ((read = getline(&line, &len, fp)) != -1) {
            printf("%s", line);
     }

     fclose(fp);

     if (line)
       free(line);

     exit(EXIT_SUCCESS);
}



