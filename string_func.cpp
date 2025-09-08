#include <stdio.h>
#include <math.h>
#include <string.h>

#include "string_func.h"

//------------------------------------------------------------------------------------

int Puts(const char* string) {
    char symbol = string[0];
    size_t pos = 0;

    while (symbol != '\0') {
        putchar(symbol);
        pos++;
        symbol = string[pos];
    }

    if (pos > 0) {
        putchar('\n');
        return 1;
    }

    return EOF;
}

//------------------------------------------------------------------------------------

char* Strchr(const char* string, int ch) {
    size_t pos = 0;
    while (string[pos] != ch) {
        if (string[pos] == '\0') { break; }
        pos++;
    }
    if (string[pos] == ch) { return (char*)string + pos; }

    return nullptr;
}

//------------------------------------------------------------------------------------

size_t Strlen(const char* string) {
    size_t size = 0;

    while (string[size] != '\0') {
        size++;
    }

    return size;
}

//------------------------------------------------------------------------------------

char* Strcpy(char* destination, const char* source) {
    size_t pos = 0;

    while (source[pos] != '\0') {
        destination[pos] = source[pos];
        pos++;
    }
    destination[pos] = '\0';

    return destination;
}

//------------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------

char* Strcat(char *destination, const char *source) {
    size_t len_d = Strlen(destination),
           len_s = Strlen(source);

    for (size_t pos = 0; pos < len_s + 1; pos++) {
        destination[len_d + pos] = source[pos];
    }

    return destination;
}

//------------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------

char* Fgets(char* string, int n, FILE* stream) {
    char a = '\0';

    for (int i = 0; i < n; i++) {
        fscanf(stream, "%c", &a);

        if (a == EOF) { return nullptr; }

        if (a != '\n') { string[i] = a; }
        else { break; }
    }

    return string;
}

//------------------------------------------------------------------------------------

char* Strdup(const char* source) {
    char* new_string;

    new_string = (char*)calloc(Strlen(source) + 1, sizeof(char));

    if (new_string != nullptr) {
        Strcpy(new_string, source);
    }

    return new_string;
}

//------------------------------------------------------------------------------------

int Getline(char* string, FILE* source) {
    char symbol = (char)fgetc(source);
    int pos = 0;

    while (symbol != '\n' && symbol != EOF) {
        string[pos] = symbol;
        pos++;
        symbol = (char)fgetc(source);
    }

    string[pos] = '\0';

    return pos;
}
