#include <cs50.h>
#include <stdio.h>

int luhnsAlgorithm(long unsigned int number);
int getSize(long unsigned int number);
int size = 0;

int main()
{
    long unsigned int card_number = 0;
    int flag = 0;
    card_number = get_long("Number: ");
    getSize(card_number);

    if ((size != 15 && size != 16 && size != 13) || card_number == 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        if (size == 13)
        {
            if (card_number / 1000000000000 == 4)
            {
                flag = 3;
            }
        }
        if (size == 15)
        {
            if ((card_number / 10000000000000 == 34) || (card_number / 10000000000000 == 37))
            {
                flag = 1;
            }
        }
        if (size == 16)
        {
            if (card_number / 1000000000000000 == 4)
            {
                flag = 3;
            }
            else
            {
                if ((card_number / 100000000000000 >= 51) && (card_number / 100000000000000 <= 55))
                {
                    flag = 2;
                }
            }
        }

        int total = luhnsAlgorithm(card_number);
        while (card_number > 0)
        {
            total = total + (card_number % 10);
            card_number = card_number / 100;
        }

        if (total % 10 == 0)
        {
            if (flag == 1)
            {
                printf("AMEX\n");
            }
            if (flag == 2)
            {
                printf("MASTERCARD\n");
            }
            if (flag == 3)
            {
                printf("VISA\n");
            }
            if (flag == 0)
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    return 0;
}

int getSize(long unsigned int number)
{
    if (number > 0)
    {
        number = number / 10;
        size++;
        getSize(number);
    }

    return 0;
}

int luhnsAlgorithm(long unsigned int number)
{
    int total = 0;
    number = number / 10;
    while (number > 0)
    {
        int aux = (number % 10) * 2;

        if (aux > 9)
        {
            total = (aux % 10) + total;
            total = (aux / 10) + total;
        }
        else
        {
            total = aux + total;
        }

        number = number / 100;
    }
    return total;
}
