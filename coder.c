#include "coder.h"

void mutableCaesar(char* str, const int offset) {
    bool flag = false;
    int offsetEdited = offset % 26;
    int i, k = strlen(str);
    for (i = 0; i < k; ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
            flag = true;
        }
        if(str[i] + offsetEdited > 'z') {
            str[i] -= ('z' - 'a') + 1;
        }
        if(str[i] + offsetEdited < 'a') {
            str[i] += ('z' - 'a') + 1;
        }
        str[i] += offsetEdited;
        if(flag) {
            str[i] -= 'a' - 'A';
            flag = false;
        }
    }
}


char* immutableCaesar(char* str, const int offset) {
    bool flag = false;
    int offsetEdited = offset % 26;
    int i, k = strlen(str);
    char* newStr = malloc (sizeof(char) * (k + 1));
    strcpy(newStr, str);
    for (i = 0; i < k; ++i) {
        if(newStr[i] >= 'A' && newStr[i] <= 'Z') {
            newStr[i] += 'a' - 'A';
            flag = true;
        }
        if(newStr[i] + offsetEdited > 'z') {
            newStr[i] -= ('z' - 'a') + 1;
        }
        if(newStr[i] + offsetEdited < 'a') {
            newStr[i] += ('z' - 'a') + 1;
        }
        newStr[i] += offsetEdited;
        if(flag) {
            newStr[i] -= 'a' - 'A';
            flag = false;
        }
    }
    return newStr;
}


void mutableXor (char* str, const char* key) {
    int i;
    int k = strlen(str);
    int keyLen = strlen(key);
    for (i = 0; i < k; ++i) {
        str[i] ^= key[i % keyLen];
    }
}


char* immutableXor (char* str, const char* key) {
    int i;
    int k = strlen(str);
    int keyLen = strlen(key);
    char* newStr = malloc (sizeof(char) * (k + 1));
    strcpy(newStr, str);
    for (i = 0; i < k; ++i) {
        newStr[i] ^= key[i % keyLen];
    }
    return newStr;
}
