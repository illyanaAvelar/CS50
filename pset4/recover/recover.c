#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char filename[8];
    int fileIndex = 0;
    bool foundImage = false;

    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (foundImage)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", fileIndex);
            fileIndex++;

            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file.\n");
                return 1;
            }

            foundImage = true;
        }

        if (foundImage)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
