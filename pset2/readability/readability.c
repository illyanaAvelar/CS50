#include <stdio.h>
#include <cs50.h>

int main()
{
    int i = 0;
    //the words variable starts with 1 because of the last word that will not be considere in the while loop
    float s = 0, l = 0, w = 1;
    string text = "";
    text = get_string("Texto: ");

    //reads the string until the final character
    while (text[i] != '\0')
    {
        //if it is the end of the sentence, add one more sentence
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            s++;
        }
        else
        {
            //if it is the end of a word, add one more word
            //because it needs the blank space, the last word won't be considere, therefore we add this word in the declaration of the variable
            if (text[i] == ' ')
            {
                w++;
            }
            else
            {
                //if it is a letter, add one more
                if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
                {
                    l++;
                }
            }
        }
        i++;
    }

    //now that we have the total in the text, lets find letters per 100 words and sentences per 100 words
    float L = (l / w) * 100;
    float S = (s / w) * 100;

    //and now the Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if (index >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %.0f\n", index);
        }
    }

    return 0;
}