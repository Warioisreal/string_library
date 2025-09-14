#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "string_func.h"
#include "sup_func.h"


int Puts(const char* string) {

    assert (string != nullptr);

    char ch = string[0];
    size_t pos = 0;

    while (ch != '\0') {
        if (putchar(ch) == EOF) { return EOF; }
        pos++;
        ch = string[pos];
    }

    if (pos > 0) {
        putchar('\n');
        return 1;
    }

    return EOF;
}

//------------------------------------------------------------------------------------

char* Strchr(const char* string, int ch) {

    assert (string != nullptr);

    const char* picked_ch = string;

    while (*picked_ch != ch) {
        if (*picked_ch == '\0') { break; }
        picked_ch++;
    }
    if (*picked_ch == ch) { return (char*)picked_ch; }

    return nullptr;
}

//------------------------------------------------------------------------------------

size_t Strlen(const char* string) {

    assert (string != nullptr);

    size_t size = 0;

    while (string[size] != '\0') {
        size++;
    }

    return size;
}

//------------------------------------------------------------------------------------

char* Strcpy(char* destination, const char* source) {

    assert (destination != nullptr);
    assert (source != nullptr);
    assert(destination != source);

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

    assert (destination != nullptr);
    assert (source != nullptr);
    assert(destination != source);

    bool null_met = false;

    for (size_t pos = 0; pos < n; pos++) {
        if (source[pos] == '\0') { null_met = true; }

        if (null_met == true) {
            destination[pos] = '\0';
        } else {
            destination[pos] = source[pos];
        }
    }

    return destination;
}

//------------------------------------------------------------------------------------

char* Strcat(char *destination, const char *source) {

    assert (destination != nullptr);
    assert (source != nullptr);
    assert(destination != source);

    size_t len_d = Strlen(destination),
           pos   = 0;

    while (source[pos] != '\0') {
        destination[len_d + pos] = source[pos];
        pos++;
    }
    destination[len_d + pos] = '\0';

    return destination;
}

//------------------------------------------------------------------------------------

char* Strncat(char* destination, const char* source, size_t n) {

    assert (destination != nullptr);
    assert (source != nullptr);
    assert(destination != source);

    size_t len_d = Strlen(destination),
           pos   = 0;

    while (source[pos] != '\0' && pos < (n - 1)) { // n задаётся с запасом на \0
        destination[pos + len_d] = source[pos];
        pos++;
    }
    destination[len_d + pos] = '\0';

    return destination;
}

//------------------------------------------------------------------------------------

int Atoi(const char* string) {

    assert (string != nullptr);

    int result = 0;
    int sign = 11;
    size_t pos = 0;
    char ch = string[pos];

    while (ch != '\0') {
        if (isspace(ch)) {
            if (abs(sign) == 1) { return 0; }
        }
        else if (ch == '-' && abs(sign) != 1) {
            sign = -1;
        }
        else if (ch == '+' && abs(sign) != 1) {
            sign = 1;
        }
        else if ('0' <= ch && ch <= '9') {
            result = result * 10 + GetDigit(ch);
        }
        else { return 0; }

        pos++;
        ch = string[pos];
    }

    if (abs(sign) == 1) { result *= sign; }

    return result;
}

//------------------------------------------------------------------------------------

char* Fgets(char* string, int n, FILE* stream) {

    assert (string != nullptr);
    assert (stream != nullptr);

    char ch = '\0';

    for (int i = 0; i < n; i++) {

        ch = (char)fgetc(stream);

        if (ch == EOF) { return nullptr; }

        if (ch != '\n') { string[i] = ch; }
        else {
            string[i] = '\0';
            break;
        }
    }
    string[n - 1] = '\0';

    return string;
}

//------------------------------------------------------------------------------------

char* Strdup(const char* source) {

    assert (source != nullptr);

    char* new_string = nullptr;

    new_string = (char*)calloc(Strlen(source) + 1, sizeof(char));

    if (new_string != nullptr) {
        Strcpy(new_string, source);
    }

    return new_string;
}

//------------------------------------------------------------------------------------

int Getline(char** lineptr, size_t* n, FILE* source) {

    assert (n != nullptr);
    assert (source != nullptr);

    if (*lineptr == nullptr) {
        *lineptr = (char*)calloc(*n + 1, sizeof(char));
    }

    char ch = (char)fgetc(source);
    size_t pos = 0;

    while (ch != '\n' && ch != EOF) {
        *lineptr[pos] = ch;
        pos++;
        ch = (char)fgetc(source);
        if (pos > *n) {
            *lineptr = (char*)realloc(*lineptr, 2 * (*n));

            if (*lineptr == nullptr) { return -1; }
            else { *n *= 2; }
        }
    }

    if (pos == 0) { return -1; }

    *lineptr[pos] = '\0';

    return (int)pos;
}
