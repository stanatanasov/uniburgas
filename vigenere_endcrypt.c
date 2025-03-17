#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

char* vigenere_encrypt(char* plaintext, char* key)
{
    int text_lenght = strlen(plaintext);
    int key_lenght = strlen(key);

    char* cipher = (char*)malloc(sizeof (char) * (text_lenght - 1));
    memset(cipher, '\0', sizeof (char) * (text_lenght - 1));
    

    for(int i = 0; i < text_lenght; i++)
    {
        if(isalpha(plaintext[i]))
        {
            int shift = tolower (key[i%key_lenght])- 'a';
            if(islower(plaintext[i]))
            {
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift)%26;
                
            }
            else
            {
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift)%26;
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }
    cipher [text_lenght] = '\0';
    return cipher;
}

int read_cipher(char* filename, char* cipher)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening the file.");
        return EXIT_FAILURE;
    }

    if(fgets(cipher,MAXN,fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

void write_file(char* filename, char* text)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

int main()
{
    char text_name[MAXN];
    scanf("%s", text_name);
    

    char key_name[MAXN];
    scanf("%s", key_name);
    char text[MAXN];
    read_cipher(text_name, text);
    char key[MAXN];
    read_cipher(key_name, key);
    char * cipher = vigenere_encrypt(text, key);
    write_file("cipher.txt", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}