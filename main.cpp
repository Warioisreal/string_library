#include <stdio.h>
#include <math.h>
#include <string.h>

#include "color_lib.h"
#include "string_func.h"


int main(void) {

    Puts("Hello world!");                                                       // -> Hello world!
//------------------------------------------------------------------------------------
    PrintColorVar(RED, "strchr: %p\n", Strchr("Hello world!", 'v'));            // -> 0x0
    PrintColorVar(BLUE, "strchr: %p\n", Strchr("Hello world!", 'e'));           // -> 0x... (указатель на символ)
//------------------------------------------------------------------------------------
    PrintColorVar(MAGENTA, "strlen: %zu\n", Strlen("Hello world!"));            // -> 12
//------------------------------------------------------------------------------------
    char str[20] = "abc";
    PrintColorVar(GREEN, "strcpy: %s\n", Strcpy(str, "Hello world!"));          // -> Hello world!
//------------------------------------------------------------------------------------
    char str1[10] = "abc";
    char str2[20] = "abc";
    PrintColorVar(CYAN, "strncpy_1: %s\n", Strncpy(str1, "Hello world!", 10));   // -> Hello worl...
    PrintColorVar(GREEN, "strncpy_2: %s\n", Strncpy(str2, "Hello world!", 20)); // -> Hello world! [+ 7 extra '\0']
//------------------------------------------------------------------------------------
    char str3[20] = "Hello ";
    char str4[10] = "world!";
    PrintColorVar(GREEN, "strcat: %s\n", Strcat(str3, str4));                   // -> Hello world!
//------------------------------------------------------------------------------------
    char str5[20] = "Hello ";
    char str6[10] = "world!";
    char str7[20] = "Hello ";
    char str8[10] = "world!";
    PrintColorVar(GREEN, "srtncat_1: %s\n", Strncat(str5, str6, 10));           // -> Hello world!
    PrintColorVar(CYAN, "strncat_2: %s\n", Strncat(str7, str8, 4));             // -> Hello worl
//------------------------------------------------------------------------------------
    const char* str9 = "123abc";
    const char* str10 = "abc";
    PrintColorVar(MAGENTA, "atoi_1: %d\n", Atoi(str9));                         // -> 123
    PrintColorVar(RED, "atoi_2: %d\n", Atoi(str10));                            // -> 0
//------------------------------------------------------------------------------------
    char str11[10] = "abc";
    PrintColor(YELLOW, "enter string (max_size = 9 symbols)\n");

    Fgets(str11, 10, stdin); // input sth

    if (str11[10] != '\0') {
        while (fgetc(stdin) != '\n') { continue; }
        PrintColorVar(CYAN, "fgets: %s\n", str11);                              // first 10 char in ur input and trash
    } else {
        PrintColorVar(GREEN, "fgets: %s\n", str11);                             // ur input
    }

//------------------------------------------------------------------------------------
    char* str_dup = nullptr;
    str_dup = Strdup("abc");

    PrintColorVar(GREEN, "strdup_s: %s\n", str_dup);                            // -> abc
    PrintColorVar(BLUE, "strdup_ad: %p\n", str_dup);                            // -> 0x... (указатель на выделенный адрес строки)

    free(str_dup);
    str_dup = nullptr;
//------------------------------------------------------------------------------------
    size_t size = 5;
    char* lineptr = nullptr;
    lineptr = (char*)calloc(size, sizeof(char));

    PrintColor(YELLOW, "enter string\n");
    Getline(&lineptr, &size, stdin);
    PrintColorVar(GREEN, "getline: %s\n", lineptr);                             // ur input line

    free(lineptr);
    lineptr = nullptr;

    return 0;
}
