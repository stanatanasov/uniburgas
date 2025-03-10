#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_COUNT 10

char *cezar_decipher(char *cipher, int key)
{
    int length = strlen(cipher);
    char *plaintext = (char *)malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++)
    {
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plaintext[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plaintext[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if (cipher[i] >= '0' && cipher[i] <= '9')
        {
            plaintext[i] = (cipher[i] - '0' - key + 10) % 10 + '0';
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }
    plaintext[length] = '\0';
    return plaintext;
}
int read_cipher(char*filename,char*cipher)
int*count_freaquenc(cipher)

int*freacuency=[int*]malloc(sizeof(int)*ALPHA_LENGTH);
memset(freaquency, 0 sizeof(int)*ALPHA_LENGTH);
int length=strlen(cipher);
for(int i=0;<length;i++)
{
    int position=tolower(cipher[i])-'a';
    freaquency[position]++;
}