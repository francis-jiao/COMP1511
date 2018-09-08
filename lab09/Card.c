// The playing card implementation.
//
// This is an implementation of the Card ADT, which represents a single
// playing card in the game of Final Card-Down.
// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)
// Written on 2017-09-??
// Tutor (dayHH-lab)
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "Card.h"

// The following typedef is included in Card.h:
//         typedef struct _card *Card;
// This means that a struct card has to be implemented *somewhere*, but
// not necessarily in the .h file, as we have done with concrete types.
//
// The way we implement this in an ADT is that you design your own card
// struct, with the fields etc that you need to implement your ADT.

typedef struct _card {
    color color;
    suit suit;
    char value;
} card;

// Place the prototypes for your own functions here.
// Don't forget to make them static!

// The interface functions are below. You need to implement these.

// Create a new card.
// These values can only be set at creation time.
// The number should be between 0x0 and 0xF.
Card newCard(char number, color color, suit suit) {
    card *c = calloc(1,sizeof(card));
    c->color = color;
    c->value = number;
    c->suit = suit;
    return c; // Replace this with your own code.
}

// Destroy an existing card.
void destroyCard(Card card) {
    free(card); // Replace this with your own code.
}

// Get the card suit (HEARTS, DIAMONDS, etc).
suit cardSuit(Card card) {
    return card->suit; // Replace this with your own code.
}

// Get the card number (0x0 through 0xF).
char cardNumber(Card card) {
    return card->value; // Replace this with your own code.
}

// Get the card's color (RED, BLUE, etc).
color cardColor(Card card) {
    return card->color; // Replace this with your own code.
}


// Implement your own functions here, don't forget to make them static!

