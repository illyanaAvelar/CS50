#include <stdio.h>

int main()
{
    char userName[64];

    printf("What's your name?");

    fgets(userName, sizeof(userName), stdin);

    printf("hello, %s\n", userName);

    return 0;
}
