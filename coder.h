#ifndef CODER
#define CODER

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void mutableCaesar(char* string, const int offset);
char* immutableCaesar(char* string, const int offset);

void mutableXor (char* string, const char* key);
char* immutableXor (char* string, const char* key);

#endif
