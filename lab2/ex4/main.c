#include <stdio.h>
#include <string.h>

// Note that here we can use char str1[] instead of char* str1, same for str2
int alike(char* str1, char* str2) {
    int diff = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            diff++;
        }
    }
    return (strlen(str1) - diff) * 100 / strlen(str1);
}

int main() {
    char str1[] = "hello";
    char str2[] = "hella";
    printf("The similarity between the two strings is %d%%\n", alike(str1, str2));
}