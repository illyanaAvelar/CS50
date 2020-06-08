#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    BYTE buffer[512];
    int images = 0;
    char filename[8];
    FILE *image = NULL;
    size_t read = 1;

    // if there is no second argument, return with error
    if (argc < 2)

    {
        printf("ERROR!\n");
        return 1;
    }

    // if unable to open file, return with error
    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        printf("ERROR!\n");
        return 2;
    }

    // until rach the end of the file
    while (read != 0 && !feof(file))
    {
        //read the memory card
        read = fread(buffer, sizeof(BYTE), 512, file);

        //if it starts like a jpeg, and there is an image open
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) && image != NULL)
        {
            fclose(image);
            images++;
        }

        //if it starts like a jpeg
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {
            //then we open the image
            sprintf(filename, "%03i.jpg", images);
            image = fopen(filename, "w");
        }

        //write when we have an open image
        if (image != NULL)
        {
            fwrite(buffer, sizeof(BYTE), read, image);
        }

    }
    //close all files
    fclose(image);
    fclose(file);

    return 0;
}