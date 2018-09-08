// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "Card.h"
#include"Card.c"

int main(int argc, char *argv[]) {
    color newColor = RED;
    suit newSuit = HEARTS;
    char newNumber = 2;
    Card c = newCard (newNumber, newColor, newSuit);
    assert (c != NULL);
    assert (cardNumber (c) == newNumber);
    assert (cardColor (c) == newColor);
    assert (cardSuit (c) == newSuit);

    newColor= BLUE;
    newNumber= 7;
    newSuit = CLUBS;
    c = newCard (newNumber, newColor, newSuit);
    assert (c != NULL);
    assert (cardNumber (c) == newNumber);
    assert (cardColor (c) == newColor);
    assert (cardSuit (c) == newSuit);

    printf("all test passed, you are awesome!\n");
    return EXIT_SUCCESS;
}
