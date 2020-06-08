#include <stdio.h>
#include <cs50.h>

int size(long unsigned int number);
int mult(long unsigned int number);

int number_size = 0;

int main()
{
    long unsigned int card_number = 0;
    int flag = 0;

    card_number = get_long("Number: ");

    //calculates the number of digits so we know if it is valid and what type it is
    size(card_number);

    //if it doesnt have any of the expected sizes, we don't need to go through the rest of the algorithm
    if ((number_size != 15 && number_size != 16 && number_size != 13) || card_number == 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        //check the start of the number
        if (number_size == 13)
        {
            //we divide the number of the card so we can get the first or the first two digits and compare
            if (card_number / 1000000000000 == 4)
            {
                //it is a VISA card
                flag = 3;
            }
        }
        if (number_size == 15)
        {
            if ((card_number / 10000000000000 == 34) || (card_number / 10000000000000 == 37))
            {
                //it is an AMERICAN EXPRESS card
                flag = 1;
            }
        }
        if (number_size == 16)
        {
            if (card_number / 1000000000000000 == 4)
            {
                //it is a VISA card
                flag = 3;
            }
            else
            {
                if ((card_number / 100000000000000 == 51) || (card_number / 100000000000000 == 52) || (card_number / 100000000000000 == 53)
                    || (card_number / 100000000000000 == 54) || (card_number / 100000000000000 == 55))
                {
                    //it is a MASTERCARD
                    flag = 2;
                }
            }
        }

        //checking if is a valid card number
        int total = mult(card_number);
        while (card_number > 0)
        {
            //getting a digit every two digits
            total = total + (card_number % 10);
            card_number = card_number / 100;
        }

        //checking if it is a valid card by the end of the number generate by the Luhn's Algorithm
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
            //if is non of the expected card types
            if (flag == 0)
            {
                printf("INVALID\n");
            }
        }
        else
            //if it failed on the Luhn's Algorithm
        {
            printf("INVALID\n");
        }
    }
    return 0;
}

//counts the number of digits
int size(long unsigned int number)
{
    if (number > 0)
    {
        number = number / 10;
        number_size ++;
        size(number);
    }

    return 0;
}

//multiplies each other digit by 2
int mult(long unsigned int number)
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