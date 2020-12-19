#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringutils.h"

char* caesarEncoder(const char* str, int offset) {
    char* strRes = immutableStrip(str);
    mutableToLower(strRes);
    for (int i = 0; i < strlen(strRes); ++i) {
	    strRes[i] = (str[i] + (offset % 26));
    }

    return strRes;
}

char* xorEncoder(const char* str, const char* password) {
    char* strRes = immutableStrip(str);
    mutableToLower(strRes);
    int k = 0;
    for (int i = 0; i < strlen(strRes); ++i) {
        strRes[i] = (strRes[i] ^ password[k]);
        k = (k + 1) % strlen(password);
    }

    return strRes;
}

int main() {
    char cipher[6];
    printf("Enter cipher (Caesar or XOR): ");
    scanf("%s", cipher);
    char text[200];
    printf("Enter text: ");
    scanf("%s", text);

    if (whatCipher(cipher, "Caesar") == 0) {
	    int offset;
	    printf("Enter offset: ");
	    scanf("%d", &offset);
	    printf("%s\n", caesarEncoder(text, offset));
    }

	else if (whatCipher(cipher, "XOR") == 0) {
	    char password[200];
	    printf("Enter password: ");
       	scanf("%s", password);
        printf("%s\n", xorEncoder(text, password));
    }

    else {
	    printf("Incorrect data");
    }

    return 0;
}
