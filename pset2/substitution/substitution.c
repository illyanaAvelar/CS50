#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LENGTH 26

bool is_valid_key(string key);
string apply_cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./cipher key\n");
        return 1;
    }

    string key = argv[1];

    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = apply_cipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != ALPHABET_LENGTH)
    {
        return false;
    }

    bool char_used[ALPHABET_LENGTH] = {false};

    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';

        if (char_used[index])
        {
            return false;
        }

        char_used[index] = true;
    }

    return true;
}

string apply_cipher(string plaintext, string key)
{
    int length = strlen(plaintext);
    char *ciphertext = malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            bool is_lowercase = islower(plaintext[i]);
            int alpha_index = tolower(plaintext[i]) - 'a';
            char cipher_char = key[alpha_index];

            ciphertext[i] = is_lowercase ? tolower(cipher_char) : toupper(cipher_char);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[length] = '\0';
    return ciphertext;
}
