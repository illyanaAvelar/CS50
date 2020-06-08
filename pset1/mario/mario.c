#include <stdio.h>

int main()
{
    int height = 10;
    char str[100];
    //gets height
    while (height < 1 || height > 8)
    {
        printf("Height: ");
        scanf("%d", &height);
    }

    for (int i = 0; i < height; i++)
    {
        int x = height;
        x--;
        //prints space so that the pyramids stay in center
        for (int j = x; j > i; j--)
        {
            printf(" ");
        }
        //prints left side
        for (int j = i; j >= 0; j--)
        {
            printf("#");
        }
        //prints sapce in between
        printf("  ");
        //prints right side
        for (int j = i; j >= 0; j--)
        {
            printf("#");
        }

        printf("\n");
    }
}