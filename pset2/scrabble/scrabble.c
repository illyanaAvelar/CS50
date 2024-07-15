#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LETTERS_OF_THE_ALPHABET 26

int calculate_score(const char *word) {
    int points[LETTERS_OF_THE_ALPHABET] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;
    while (*word) {
        if (isalpha(*word)) {
            score += points[toupper(*word) - 'A'];
        }
        word++;
    }
    return score;
}

int main() {

    char player1word[100], player2word[100];

    printf("Player 1: ");
    scanf("%s", player1word);
    printf("Player 2: ");
    scanf("%s", player2word);

    int score1 = calculate_score(player1word);
    int score2 = calculate_score(player2word);

    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}
