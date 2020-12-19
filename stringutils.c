#include "stringutils.h"

void mutableToUpper(char* str) {
    int key = 'A' - 'a';
    for (int i = 0; i < strlen(str); ++i) {
	    if ((str[i] >= 'a') && (str[i] <= 'z')){
	        str[i] += key;
	    }
    }
}

void mutableToLower(char* str) {
    int key = 'A' - 'a';
    for (int i = 0; i < strlen(str); ++i) {
	    if ((str[i] >= 'A') && (str[i] <= 'Z')){
	        str[i] -= (key);
	    }
    }
}

char* immutableToUpper(const char* str) {
    int key = 'A' - 'a';
    char* strRes = malloc((sizeof(char) * (strlen(str) + 1)));
    for (int i = 0; i < strlen(str); ++i) {
	    if ((str[i] >= 'a') && (str[i] <= 'z')){
	        strRes[i] = str[i] + key;
        }
        else {
	        strRes[i] = str[i];
        }
    }
    return strRes;
}

char* immutableToLower(const char* str) {
    int key = 'A' - 'a';
    char* strRes = malloc((sizeof(char) * (strlen(str) + 1)));
    for (int i = 0; i < strlen(str); ++i) {
	    if ((str[i] >= 'A') && (str[i] <= 'Z')) {
	        strRes[i] = str[i] - key;
	    }
	    else {
	        strRes[i] = str[i];
	    }
    }
    return strRes;
}

void mutableStrip(char* str) {
    int size = strlen(str);
    int left = 0;
    while (str[left] == ' ') {
	    left++;
    }
    int right = 0;
    while (str[size - 1 - right] == ' ') {
	    right++;
    }
    int sizeText = size - left - right;
    for (int i = 0; i < sizeText; ++i) {
	    str[i] = str[left + i];
    }
    str[sizeText] = '\0';
}

char* immutableStrip(const char* str) {
    int size = strlen(str);
    int left = 0;
    while (str[left] == ' ') {
	    left++;
    }
    int right = 0;
    while (str[size - 1 - right] == ' ') {
	    right++;
    }
    int sizeText = size - left - right;
    char* strRes = malloc((sizeof(char) * (size + 1)));
    for (int i = 0; i < sizeText; ++i) {
	    strRes[i] = str[left + i];
    }
    strRes[sizeText] = '\0';
    return strRes;
}

void mutableAllStrip(char* str) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; ++i) {
	if (str[i] != ' ') {
            str[j] = str[i];
            ++j;
	    }
    }
    str[j] = '\0';
}

char* immutableAllStrip(const char* str) {
    int size = strlen(str);
    char* strRes = malloc((sizeof(char) * (size + 1)));
    int j = 0;
    for (int i = 0; i < size; ++i) {
	    if (str[i] != ' ') {
	        strRes[j] = str[i];
	        ++j;
	    }
    }
    strRes[j] = '\0';
    return strRes;
}

void mutableFilter(char* str) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; ++i) {
	    if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))
         || ((str[i] >= '0') && (str[i] <= '9')) || (str[i] == ' '))
            {
	        str[j] = str[i];
	        ++j;
	    }
    }
    str[j] = '\0';
}

char* immutableFilter(const char* str) {
    int size = strlen(str);
    int j = 0;
    char* strRes = malloc((sizeof(char) * (size + 1)));
    for (int i = 0; i < strlen(str); ++i) {
	    if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))
	        || ((str[i] >= '0') && (str[i] <= '9')) || (str[i] == ' '))
        {
            strRes[j] = str[i];
	        ++j;
	    }
    }
    strRes[j] = '\0';
    return strRes;
}

int number(const char* str) {
    int size = strlen(str);
    int sumNumber = 0;
    while ((str[sumNumber] >= '0') && (str[sumNumber] <= '9')) {
	    ++sumNumber;
    }
    if (sumNumber == size) {
	    return 1;
    }
    else {
        return 0;
    }
}

int word(const char* str) {
    int size = strlen(str);
    int sumLetter = 0;
    while (((str[sumLetter] >= 'a') && (str[sumLetter] <= 'z'))
        || ((str[sumLetter] >= 'A') && (str[sumLetter] <= 'Z')))
    {
	    ++sumLetter;
    }
    if (sumLetter == size) {
	    return 1;
    }
    else {
	    return 0;
    }
}
