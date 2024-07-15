#include <cs50.h>
#include <stdio.h>

int main()
{
    int i = 0;
    float totalSentences = 0, totalLetters = 0, words = 1;
    string text = "";
    text = get_string("Texto: ");

    while (text[i] != '\0')
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            totalSentences++;
        }
        else
        {
            if (text[i] == ' ')
            {
                words++;
            }
            else
            {
                if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
                {
                    totalLetters++;
                }
            }
        }
        i++;
    }

    float lettersPer100Words = (totalLetters / words) * 100;
    float sentencesPer100Words = (totalSentences / words) * 100;

    float ColemanLiauIndex = 0.0588 * lettersPer100Words - 0.296 * sentencesPer100Words - 15.8;

    if (ColemanLiauIndex <= 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if (ColemanLiauIndex >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %.0f\n", ColemanLiauIndex);
        }
    }

    return 0;
}
