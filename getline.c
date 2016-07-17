#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_LINE 200

// input: IGHV1-18,IGHJ4,IGHD2-15,CARPIGYCSVGSCYFDCW,2,103_d_CSF_UNS_NA_BCR_IgG
// output: CARPIGYCSVGSCYFDCW
int cdr3_from_line(char * line, char* buffer) {
   int comma_index =0;
   int i = 0;
   int j = 0;
   char ch;
   for (i = 0; line[i] != 0; i++){
       if(line[i] == ',') {
           comma_index++;
           continue;
       }
       if(comma_index == 3) {
           buffer[j] = line[i];
           j++;
       } 
   }
   buffer[j+1] = '\0';
   return 0; 
}

int main(int argc, char * argv[])
   {
     char *filename;
     FILE * fp;
     char * line = NULL;
     size_t len = 0;
     ssize_t read;
     int line_num = 0;
     char * cdr3;

     filename = argv[1];

     fp = fopen(filename, "r");
     if (fp == NULL)
       exit(EXIT_FAILURE);

     while ((read = getline(&line, &len, fp)) != -1) {
            char buffer[MAX_SIZE_OF_LINE];
            cdr3_from_line(line,buffer);
            printf("%s\n", buffer);
     }

     fclose(fp);

     if (line)
       free(line);

     exit(EXIT_SUCCESS);
}



