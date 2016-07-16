#include <stdio.h>

int main(int argc, char **argv) {
        char *str1= "ABCDEDF";
        char *str2= "ABDCEDF";
        int len = 7;
        int distance = 0;
        distance = hamming_distance(str1, str2, len);
        printf("%s %s %d\n", str1, str2, distance);
        return 0;
}

int hamming_distance(const char* str1, const char* str2, int len) {
    int num_mismatches = 0;
    while (len) {
        if (*str1 != *str2)
            ++num_mismatches;
        --len;
        ++str1; // how this works
        ++str2;
    }
    return num_mismatches;
}
