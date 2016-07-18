// from http://www.mitbbs.com/article_t/JobHunting/33205831.html
// author @featen
// 5) Programming test: Write a function that will operate on a C-string and 
// convert all instances of "AB" to "C" without using a second string for 
// temporary storage. 
//
// Use the following function signature:
//
//       void translate(char *str)
//
// So for example:
//
//      char astring[] = "helloABworld";
//
//      translate(astring);
//
//      // Now astring holds "helloCworld";
//
//      Your function should handle strings of arbitrary length. If you have any 
//      questions about the problem, make reasonable assumptions and state your 
//      assumptions in your reply.  
//
void translate(char *str)
{
    char *s, *d;
    if (!str)
        return;

    d = s = str;
    while (*s) {
        if (*s == 'A' && *(s+1) == 'B') {
            *d++ = 'C';
            s += 2;
        } else {
            *d++ = *s++;
        }
    }
    *d = 0;
}

