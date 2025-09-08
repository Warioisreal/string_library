#include <stdio.h>
#include <string.h>

#include "string_func.h"


int main(void) {

    Puts("Hello world!");                                          // -> Hello world!

    printf("strchr: %p\n", Strchr("Hello world!", 'v'));           // -> 0x... (указатель на символ)

    printf("strlen: %zu\n", Strlen("Hello world!"));               // -> 12

    char str[20] = "abc";
    printf("strcpy: %s\n", Strcpy(str, "Hello world!"));           // -> Hello world!

    char str1[10] = "abc";
    char str2[20] = "abc";
    printf("strncpy_1: %s\n", Strncpy(str1, "Hello world!", 10));  // -> Hello worl...
    printf("strncpy_2: %s\n", Strncpy(str2, "Hello world!", 20));  // -> Hello world! [+ 7 extra '\0']

    char str3[20] = "Hello ";
    char str4[10] = "world!";
    printf("strcat: %s\n", Strcat(str3, str4));                    // -> Hello world!

    char str5[20] = "Hello ";
    char str6[10] = "world!";
    char str7[20] = "Hello ";
    char str8[10] = "world!";
    printf("srtncat_1: %s\n", Strncat(str5, str6, 10));            // -> Hello world!
    printf("strncat_2: %s\n", Strncat(str7, str8, 4));             // -> Hello worl

    const char* str9 = "123abc";
    const char* str10 = "abc";
    printf("%d\n", Atoi(str9));                                    // -> 123
    printf("%d\n", Atoi(str10));                                   // -> 0

    char str11[10] = "abc";
    Fgets(str11, 10, stdin); // input sth
    printf("%s\n", str11);                                         // ur input if char_ct <= 9 | first 10 char in ur input and trash | EOF if char_ct = 0


    /*
    Strdup();
    Getline();
    */
    return 0;
}
