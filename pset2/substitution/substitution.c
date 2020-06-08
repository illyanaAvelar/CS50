#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//recives the key to use for the substitution
int main(int argc, string argv[])
{
    //the text that will be encrypted
    string plaintext;

    //alphabets for comparison
    char lower [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upper [] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int j = 0;

    //id there is no arguments
    if (argc != 2)
    {
        printf("Error!\n");
        return 1;
    }

    //if there is an argument, that should be my cipher
    char *cipher = malloc(strlen(argv[1]) + 1);
    strcpy(cipher, argv[1]);

    //if the cipher doesn't have 26 letters, it wont be possible to replace any letter
    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        //comparing all of the letters with each other to see if they are all diferent
        for (int i = 0; i < 26; i++)
        {
            for (j = 1; j < 26; j++)
            {
                if ((cipher[i] == cipher [j] && i != j))
                {
                    printf("Error!");
                    return 1;
                }
            }

            //they also need to be differente from any other symbol
            if (((int)cipher[i] < 65) || ((int)cipher[i] > 122) || (((int)cipher[i] > 90) && ((int)cipher[i] < 96)))
            {
                return 1;
            }
        }
    }
    j = 0;
    plaintext = get_string("plaintext: ");

    //while there are still a letter to be replaced
    while (plaintext [j] != '\0')
    {
        for (int i = 0; i < 26; i++)
        {
            //we find wich letter that is, and then if it is lower or upper case
            if (plaintext[j] == upper[i] || plaintext[j] == lower[i])
            {
                if ((int)plaintext[j] > 96 && (int)cipher[i] < 96)
                {
                    plaintext[j] = cipher[i];
                    plaintext[j] = tolower(plaintext[j]);
                }
                else
                {
                    if ((int)plaintext[j] < 96 && (int)cipher[i] > 96)
                    {
                        plaintext[j] = cipher[i];
                        plaintext[j] = toupper(plaintext[j]);
                    }
                    else
                    {
                        plaintext[j] = cipher[i];
                    }
                }
                //atfter replacing each letter, we break the for loop
                break;
            }
        }

        j++;
    }

    printf("ciphertext: %s\n", plaintext);

    free(cipher);

    return 0;
}