#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"
void basicCurrentPlayerAndTurn (void);
void testCardA (void);
void testCardB (void);
void testCardC (void);
void testCardD (void);
int main (int argc, char *argv[]) {
    printf ("Hello and welcome to GROUP_NAME's Game ADT tests!\n");
    // Basic
    basicCurrentPlayerAndTurn ();
    printf ("All tests passed, you are Awesome!\n");
    return EXIT_SUCCESS;
}
void basicCurrentPlayerAndTurn (void) {
    //Set up the cards
    value values[300];
    color colors[300];
    suit suits[300];
    // Assign card's suit, value and color
    int i = 0;
    while (i < 300) {
        values[i] = 1;
        suits[i] = HEARTS;
        colors[i] = RED;
        i++;
    }
    Game game1 = newGame (300,values, colors, suits);
    // check valid 
    assert (game1 != NULL);
    assert (currentPlayer(game1) == 0);
    assert (currentTurn(game1) == 0);
    assert (playDirection(game1) == CLOCKWISE);
    assert (numTurns(game1) == 0);
    // Check each player's card counts
    assert (playerCardCount(game1, 0) == 7);
    assert (playerCardCount(game1, 1) == 7);
    assert (playerCardCount(game1, 2) == 7);
    assert (playerCardCount(game1, 3) == 7);
    // Check each player's point
    assert (playerPoints(game1, 0) == 0);
    assert (playerPoints(game1, 1) == 0);
    assert (playerPoints(game1, 2) == 0);
    assert (playerPoints(game1, 3) == 0);
    // Player Move
    Card toPlay = handCard (game1, 0);
    playerMove move;
    move.action = PLAY_CARD;
    move.card = toPlay;
    playMove (game1, move);
    // assert (isValidMove == FALSE);
    assert (playerCardCount(game1, 0) == 6);
    playerMove finalMove;
    finalMove.action = END_TURN;
    playMove (game1, finalMove);
}
void testCardA (void){
    //Set up the cards
    value values[300];
    color colors[300];
    suit suits[300];
    // Assign card's suit, value and color
    int i = 0;
    while (i < 300) {
        values[i] = ADVANCE;
        suits[i] = HEARTS;
        colors[i] = RED;
        i++;
    }
    Game game2 = newGame (300, values, colors, suits);
    Card toPlay = handCard (game2, 0);
    playerMove move;
    move.action = PLAY_CARD;
    move.card = toPlay;
    playMove (game2, move);
    playerMove finalMove;
    finalMove.action = END_TURN;
    playMove (game2, finalMove);
    assert (currentPlayer(game2) == 2);
}
void testCardB (void){
    //Set up the cards
    value values[300];
    color colors[300];
    suit suits[300];
    // Assign card's suit, value and color
    int i = 0;
    while (i < 300) {
        values[i] = BACKWARDS;
        suits[i] = HEARTS;
        colors[i] = RED;
        i++;
    }
    Game game2 = newGame (300, values, colors, suits);
    // Check direction 
    assert (playDirection(game2) == CLOCKWISE);
    // Play a B value card which changes direction
    Card toPlay = handCard (game2, 0);
    playerMove move;
    move.action = PLAY_CARD;
    move.card = toPlay;
    playMove (game2, move);
    playerMove finalMove;
    finalMove.action = END_TURN;
    playMove (game2, finalMove);
    assert (playDirection(game2) == ANTICLOCKWISE);
    assert (currentPlayer(game2) == 3);
}

