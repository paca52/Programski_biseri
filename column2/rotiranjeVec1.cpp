#include <iostream>
#include <cstring>

void reverse(char *str, int start, int end) {
    while(start < end) {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
     
        start++;
        end--;
    }
}

void rotateNTimes(char *str, int times) {
    reverse(str, 0, times-1);
    reverse(str, times, strlen(str) - 1);
    reverse(str, 0, strlen(str)-1);
}

int main(void) {

    char str[] = "abcdef";

    rotateNTimes(str, 3); // abcdef -> defabc
    puts(str);

    return 0;
}
