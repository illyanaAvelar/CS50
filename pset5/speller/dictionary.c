#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 64000;
unsigned int count = 0;
node *table[N];

bool check(const char *word)
{
    int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    unsigned int base_power = 1;
    int P = 31;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int char_value = (toupper(word[i]) - 'A');

        if (char_value < 0 || char_value > 25)
        {
            continue;
        }

        hash = (hash + (char_value + 1) * base_power) % N;
        base_power = (base_power * P) % N;
    }

    return hash;
}

bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");

    char word[LENGTH + 1];

    if (source == NULL)
    {
        return false;
    }

    while (fscanf(source, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);

        int index = hash(word);

        n->next = table[index];
        table[index] = n;

        count++;
    }

    fclose(source);
    return true;
}

unsigned int size(void)
{
    return count;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            node *temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = NULL;
    }
    return true;
}