#include <stdio.h>
#include <math.h>


#include "string_func.h"


int Puts(const char* string) {
    if (printf("%s\n", string) == 1) {
        return 1;
    }

    return EOF;
}


char* Strchr(const char* string, int ch) {
    size_t pos = 0;
    while (string[pos] != ch) {
        if (string[pos] == '\0') { break; }
        pos++;
    }
    if (string[pos] == ch) { return (char*)string + pos; }

    return nullptr;
}


size_t Strlen(const char* string) {
    size_t size = 0;

    while (string[size] != '\0') {
        size++;
    }

    return size;
}


char* Strcpy(char* destination, const char* source) {
    size_t pos = 0;

    while (source[pos] != '\0') {
        destination[pos] = source[pos];
        pos++;
    }
    destination[pos] = '\0';

    return destination;
}


char* Strncpy(char* destination, const char* source, size_t n) {
    bool flag = false;

    for (size_t pos = 0; pos < n; pos++) {
        if (source[pos] == '\0') { flag = true; }

        if (flag == true) {
            destination[pos] = '\0';
        } else {
            destination[pos] = source[pos];
        }
    }

    return destination;
}


char* Strcat(char *destination, const char *source) {
    size_t len_d = Strlen(destination),
           len_s = Strlen(source);

    for (size_t pos = 0; pos < len_s + 1; pos++) {
        destination[len_d + pos] = source[pos];
    }

    return destination;
}


char* Strncat(char* destination, const char* source, size_t n) {
    size_t len_d = Strlen(destination),
           max_pos = Strlen(source);

    if (max_pos > n) { max_pos = n; }

    for (size_t pos = 0; pos < max_pos; pos++) {
        destination[pos + len_d] = source[pos];
    }
    destination[len_d + max_pos + 1] = '\0';

    return destination;
}


int Atoi(const char* string) {
    int result = 0;
    size_t pos = 0;

    while (string[pos] != '\0') {
        if (('0' <= string[pos]) && (string[pos] <= '9')) {
            result = result * 10 + string[pos] - '0';
        }
        pos++;
    }

    return result;
}


char* Fgets(char* string, int n, FILE* stream) {
    char a = '\0';

    for (size_t i = 0; i < n; i++) {
        fscanf(stream, "%c", &a);

        if (a == EOF) { return nullptr; }

        if (a != '\n') { string[i] = a; }
        else { break; }
    }

    return string;
}


char* Strdup(const char* source) {
    size_t s_size = Strlen(source);
    const char* str = "";

    if (str == nullptr) { return nullptr; }

    for (size_t i = 0; i < s_size + 1; i++) {
        str[i] = source[i];
    }

    return str;
}
