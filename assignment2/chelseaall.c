#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "Game.h"
#include "Card.h"

typedef struct _card {
    color thisCardColor;
    suit thisCardSuit;
    value thisCardValue;
}card;

void theThird (void);
void theFirst(void);
void theSecond(void);

int main(int argc, char *argv[]){
    printf("Welcome to the Uno game ADT test\n");
    theFirst();
    theSecond();
    printf("Awesome!!! Congratulations!!!  You have passed all test.\n");
    return EXIT_SUCCESS;
}


void theFirst(void){
    printf("There are 50 cards, half of them are RED 1 HEARTS and others are RED 3 HEARTS.\n");
    value values[50];
    suit suits[50];
    color colors[50];
    
    int i = 0;
    while (i < 50){
        if(i % 2 == 0){
            values[i] = ONE;
            suits[i] = HEARTS;
            colors[i] = RED;
        } else {
            values[i] = THREE;
            suits[i] = HEARTS;
            colors[i] = RED;
        }
        i++;
    }
    void theThird (void){
        value values[36] = {2,3,1,0,1,CONTINUE,2,4,8,2,9,6,8,5,DECLARE,6,3,3,0,3,7,BACKWARDS,9,6,7,CONTINUE,4,ADVANCE,4,4,4,8,5,5,DECLARE,7};
        suit suits[36] = {HEARTS,HEARTS,HEARTS,HEARTS,DIAMONDS,DIAMONDS,DIAMONDS,DIAMONDS,CLUBS,CLUBS,CLUBS,CLUBS,SPADES,SPADES,SPADES,SPADES,QUESTIONS,QUESTIONS,QUESTIONS,QUESTIONS,HEARTS,HEARTS,HEARTS,HEARTS,DIAMONDS,DIAMONDS,DIAMONDS,DIAMONDS,CLUBS,CLUBS,CLUBS,CLUBS,SPADES,SPADES,SPADES,SPADES};
        color colors[36] = {BLUE,RED,YELLOW,BLUE,BLUE,PURPLE,YELLOW,PURPLE,RED,RED,YELLOW,YELLOW,YELLOW,BLUE,GREEN,RED,RED,BLUE,YELLOW,YELLOW,YELLOW,GREEN,GREEN,YELLOW,GREEN,GREEN,PURPLE,GREEN,PURPLE,RED,BLUE,BLUE,GREEN,BLUE,BLUE,RED};
        printf("A very basic test for currentPlayer and currentTurn : \n");
        printf("This is a desk contains 30 cards.");

        Game game = newGame (36, values, colors, suits);

        assert(numCards(game) == 36);
        assert(numOfSuit(game, HEARTS) == 8);
        assert(numOfColor(game,RED) == 7);
        assert(numOfValue(game,1) == 2);
        assert(currentPlayer(game) == 0);
        assert(currentTurn(game) == 0);

        //topDiscard is (2,HEARTS,BLUE)
        Card testCard0 = topDiscard(game);
        assert(testCard0->thisCardValue == 4);
        assert(testCard0->thisCardSuit == CLUBS);
        assert(testCard0->thisCardColor == PURPLE);

        Card testCard1 = handCard(game, 0);
        assert(testCard1->thisCardValue == 2);
        assert(testCard1->thisCardSuit == HEARTS);
        assert(testCard1->thisCardColor == BLUE);

        //check if the first card (2,HEARTS,BLUE) in player0's hand is valid to play
        playerMove move00;
        move00.action = PLAY_CARD;
        Card card00ToPlay = handCard(game, 0);
        move00.card = card00ToPlay;
        assert(isValidMove(game, move00) == FALSE);

        //check if the second card (1,DIAMONDS,BLUE) in player0's hand is valid to play
        card00ToPlay = handCard(game, 1);
        move00.card = card00ToPlay;
        assert(isValidMove(game, move00) == FALSE);

        //player0 play a valid card (8,CLUBS,RED)
        card00ToPlay = handCard(game, 2);
        move00.card = card00ToPlay;
        assert(isValidMove(game, move00) == TRUE);

        playMove(game, move00);

        assert(playerCardCount(game, 0) == 6);

        playerMove finalMove;
        finalMove.action = END_TURN;
        playMove(game, finalMove);
       
        assert(currentPlayer(game) == 1);
        assert(currentTurn(game) == 1);

        Card testCard2 = topDiscard(game);
        assert(testCard2->thisCardValue == 8);
        assert(testCard2->thisCardSuit == CLUBS);
        assert(testCard2->thisCardColor == RED);

        //player1 play a valid card (2,CLUBS,RED)
        playerMove move10;
        move10.action = PLAY_CARD;
        Card card10ToPlay = handCard(game, 2);
        move10.card = card10ToPlay;
        assert(isValidMove(game, move10) == TRUE);

        playMove(game, move10);
        playMove(game, finalMove);

        Card testCard3 = topDiscard(game);
        assert(testCard3->thisCardValue == 2);

        //player2 play a valid card (2,DIAMONDS,YELLOW)
        playerMove move20;
        move20.action = PLAY_CARD;
        move20.card = handCard(game, 1);
        playMove(game, move20);

        playMove(game, finalMove);

        assert(currentPlayer(game) == 3);

        //player3 has to draw 4 cards
        playerMove move30;
        playerMove move31;
        playerMove move32;
        playerMove move33;
        move30.action = DRAW_CARD;
        move31.action = DRAW_CARD;
        move32.action = DRAW_CARD;
        move33.action = DRAW_CARD;
        playMove(game, move30);
        playMove(game, move31);
        playMove(game, move32);
        playMove(game, move33);

        assert(handCardCount(game) == 11);

        playMove(game, finalMove);

        //all of the players had a turn so it's now turn4
        assert(currentTurn(game) == 4);

        //player0 plays a valid card(8,SPADES,YELLOW)
        playerMove move40;
        move40.action = PLAY_CARD;
        Card card40ToPlay = handCard(game, 2);
        move40.card = card40ToPlay;
        assert(isValidMove(game, move40) == TRUE);
        playMove(game, move40);
        playMove(game, finalMove);

        //player1 plays a valid card(4,PURPLE,DIAMONDS)
        playerMove move50;
        move50.action = PLAY_CARD;
        Card card50ToPlay = handCard(game, 1);
        move50.card = card50ToPlay;
        assert(isValidMove(game, move50) == TRUE);
        playMove(game, move40);

        //and player1 still need to play an additional card, he plays(4,PURPLE,DIAMONDS)
        playerMove move51;
        move51.action = PLAY_CARD;
        Card card51ToPlay = handCard(game, 4);
        assert(card51ToPlay->thisCardValue == CONTINUE);
        move51.card = card51ToPlay;
        playMove(game, move51);
        assert(playDirection(game) == CLOCKWISE);

        //he still need to play another one and chack if the first card(3,HEARTS,RED) is valid
        playerMove move52;
        move52.action = PLAY_CARD;
        Card card52ToPlay = handCard(game, 0);
        move52.card = card52ToPlay;
        assert(isValidMove(game, move52) == FALSE);

        // then he plays the valid (B,HEARTS,GREEN) and the direction is reversed and there are three cards left so he said TRIO
        card52ToPlay = handCard(game, 3);
        move52.card = card52ToPlay;
        playMove(game, move52);
        assert(playDirection(game) == ANTICLOCKWISE);
        playerMove move53;
        move53.action = SAY_TRIO;
        playMove(game, move53);

        playMove(game, finalMove);

        //it's now player0's turn again cuz the direction is reversed
        assert(currentPlayer(game) == 0);

        //player0 plays (7,DIAMONDS,GREEN)
        playerMove move60;
        move60.action = PLAY_CARD;
        Card card60ToPlay = handCard(game, 4);
        move60.card = card60ToPlay;
        playMove(game, move60);
        playMove(game, finalMove);

        //it's now turn7 so there are 8 turns
        assert(numTurns(game) == 8);
        //turn5 has 5 moves and the move2 is PLAY_CARD
        assert(turnMoves(game, 5) == 5);
        assert(pastMove(game, 4, 2).action == PLAY_CARD);
        //it's now player3's turn
        assert(currentPlayer(game) == 3);

        //player3 plays (4,PURPLE,DIAMONDS)
        playerMove move70;
        move70.action = PLAY_CARD;
        move70.card = handCard(game, 1);
        playMove(game, move70);
        playMove(game, finalMove);

        Card testCard4 = topDiscard(game);
        assert(testCard4->thisCardValue == 4);
        assert(testCard4->thisCardColor == PURPLE);
        assert(testCard4->thisCardSuit == DIAMONDS);

        //player2 plays (4,PURPLE,DIAMONDS)
        playerMove move80;
        move80.action = PLAY_CARD;
        move80.card = handCard(game, 4);
        playMove(game, move80);
        playMove(game, finalMove);

        assert(currentPlayer(game) == 1);

        //player1 don't have valid card to play and therefore draw a card (5,BLUE,SPADES)
        playerMove move90;
        move90.action = DRAW_CARD;
        playMove(game, move90);

        Card testCard5 = handCard(game, 3);
        assert(testCard5->thisCardValue == 5);
        assert(testCard5->thisCardColor == BLUE);
        assert(testCard5->thisCardSuit == SPADES);
        playMove(game, finalMove);

        //player0 plays a (1,BLUE,DIAMONDS)
        playerMove move100;
        move100.action = PLAY_CARD;
        move100.card = handCard(game, 1);
        playMove(game, move100);
        //three cards left so player0 said TRIO
        playerMove move101;
        move101.action = SAY_TRIO;
        playMove(game, move101);
        playMove(game, finalMove);

        assert(currentTurn(game) == 10);
        assert(pastMove(game, 10, 1).action == SAY_TRIO);

        //player3 played the first card in hand(0,BLUE,DIAMONDS)
        playerMove move110;
        move110.action = PLAY_CARD;
        move110.card = handCard(game, 0);
        assert(isValidMove(game, move110) == TRUE);
        playMove(game, move110);
        playMove(game, finalMove);

        //player2 Draws a card
        playerMove move120;
        move120.action = DRAW_CARD;
        playMove(game, move120);
        //check the 6th card i.e. card5 in player2's hand is (D,BLUE,SPADES)
        Card testCard6 = handCard(game, 5);
        assert(testCard6->thisCardValue == DECLARE);
        playMove(game, finalMove);

        //player1 plays (5,BLUE,SPADES)
        playerMove move130;
        move130.action = PLAY_CARD;
        move130.card = handCard(game, 1);
        playMove(game, move130);
        playerMove move131;
        move131.action = SAY_TRIO;
        playMove(game, move131);
        playMove(game, finalMove);

        assert(currentPlayer(game) == 0);
        //player0 plays (2,BLUE,HEARTS)
        playerMove move140;
        move140.action = PLAY_CARD;
        move140.card = handCard(game, 0);
        playMove(game, move140);
        playerMove move141;
        move141.action = SAY_DUO;
        playMove(game, move141);
        playMove(game, finalMove);

        //player3 plays (6,YELLOW,HEARTS)
        playerMove move150;
        move150.action = PLAY_CARD;
        move150.card = handCard(game, 3);
        playMove(game, move150);
        Card testCard7 = topDiscard(game);
        assert(testCard7->thisCardValue == 6);
        assert(testCard7->thisCardColor == BLUE);
        assert(testCard7->thisCardSuit == DIAMONDS);
        playMove(game, finalMove);

    //it's player2's turn ANTICLOCKWISE

        //player2 plays the first card in hand(1,YELLOW,HEARTS)
        playerMove move160;
        move160.action = PLAY_CARD;
        move160.card = handCard(game, 0);
        playMove(game, move160);
        playMove(game, finalMove);

        assert(playerCardCount(game, 0) == 2);
        assert(playerCardCount(game, 1) == 3);
        assert(playerCardCount(game, 2) == 5);
        assert(playerCardCount(game, 3) == 8);

        //player1 plays the first card in hand (3,RED,HEARTS), then he has two cards left therefore say DUO
        playerMove move170;
        move170.action = PLAY_CARD;
        move170.card = handCard(game, 0);
        playMove(game, move170);
        playerMove move171;
        move171.action = SAY_DUO;
        playMove(game, move171);
        playMove(game, finalMove);

        //player0 plays the first card in hand (3,RED,QUESTION), then he has one card left therefore say UNO
        playerMove move180;
        move180.action = PLAY_CARD;
        move180.card = handCard(game, 0);
        playMove(game, move180);
        playerMove move181;
        move181.action = SAY_UNO;
        playMove(game, move181);
        playMove(game, finalMove);

        assert(currentTurn(game) == 19);
        assert(currentPlayer(game) == 3);
        //player3 play the first card in hand (6,YELLOW,CLUBS)
        playerMove move190;
        move190.action = PLAY_CARD;
        move190.card = handCard(game, 0);
        playMove(game, move190);
        playMove(game, finalMove);

        Card testCard8 = topDiscard(game);
        assert(testCard8->thisCardValue == 6);
        assert(testCard8->thisCardSuit == CLUBS);
        assert(testCard8->thisCardColor == YELLOW);
        assert(pastMove(game, 18, 1).action == SAY_UNO);
        assert(pastMove(game, 19, 1).action == END_TURN);
        assert(numTurns(game) == 21);

        //player2 plays the first card in hand (9,YELLOW,CLUBS);
        playerMove move200;
        move200.action = PLAY_CARD;
        move200.card = handCard(game, 0);
        playMove(game, move200);
        playMove(game, finalMove);

        assert(currentPlayer(game) == 1);
        //player1 doesn't have a valid card to play then draw a card to get three cards in hand
        playerMove move210;
        move210.action = DRAW_CARD;
        playMove(game, move210);
        playerMove move211;
        move211.action = SAY_TRIO;
        playMove(game, move211);
        playMove(game, finalMove);

        //player0 plays the last card(7,YELLOW,HEARTS) and wins!!
        playerMove move220;
        move220.action = PLAY_CARD;
        move220.card = handCard(game, 0);
        playMove(game, move220);
        //make sure there is no more cards in player0's hand
        assert(handCardCount(game) == 0);
        assert(currentTurn(game) == 22);
        playMove(game, finalMove);

        assert(playerCardCount(game, 1) == 3);
        assert(playerCardCount(game, 2) == 4);
        assert(playerCardCount(game, 3) == 7);
        assert(playerPoints(game, 0) == 0);
        assert(playerPoints(game, 1) == 3);
        assert(playerPoints(game, 2) == 4);
        assert(playerPoints(game, 3) == 7);
        assert(gameWinner(game) == 0);
}





//













    //test1
    Game game1 = newGame(50, values, colors, suits);
    printf("Check the first player is 0\n");
    assert(currentPlayer(game1) == 0);
    printf("The turn number should start at 0 once the game has started.\n");
    assert(currentTurn(game1) == 0);
    assert(playDirection(game1)== CLOCKWISE);
    printf("The value of first card");
    Card firstCard = handCard(game1,0);
    assert(firstCard->thisCardValue == ONE);
    printf("The num color of first card");
    assert(numOfColor(game1,RED) == 50);
    printf("The num suit of first card");
    assert(numOfSuit(game1,HEARTS) == 50);
    printf("The num value of first card");
    assert(numOfValue(game1,ONE) == 25);
    assert(playerCardCount(game1,0) == 7);
    playerMove moveOfPlay0;
    Card testCard = newCard(ONE,RED,HEARTS);
    assert(testCard -> thisCardValue == ONE);
    assert(testCard -> thisCardSuit == HEARTS);
    assert(testCard -> thisCardColor == RED);
    moveOfPlay0.card = testCard;
    moveOfPlay0.action = PLAY_CARD;
    playMove(game1,moveOfPlay0);
    assert(isValidMove(game1,moveOfPlay0) == TRUE);
    moveOfPlay0.action = END_TURN;
    playMove(game1,moveOfPlay0);
    assert(isValidMove(game1,moveOfPlay0) == TRUE);
    assert(currentTurn(game1) == 0);
    assert(numTurns(game1) == 1);
    //test2
    printf("Check the second player is 1\n");
    assert(currentPlayer(game1) == 1);
    printf("The turn number should start at 1 once the game has started.\n");
    assert(currentTurn(game1) == 1);
    assert(playDirection(game1)== CLOCKWISE);
    printf("The value of second card");
    Card secondCard = handCard(game1,1);
    assert(secondCard->thisCardValue == THREE);
    printf("The num color of second card");
    assert(numOfColor(game1,RED) == 50);
    printf("The num suit of second card");
    assert(numOfSuit(game1,HEARTS) == 50);
    printf("The num value of second card");
    assert(numOfValue(game1,THREE) == 25);
    assert(playerCardCount(game1,0) == 6);
    assert(playerCardCount(game1,1) == 7);
    playerMove moveOfPlay1;
    Card newSecondCard = newCard(THREE, RED, HEARTS);
    moveOfPlay1.card = newSecondCard;
    moveOfPlay1.action = PLAY_CARD;
    playMove(game1,moveOfPlay1);
    assert(isValidMove(game1,moveOfPlay1) == TRUE);
    moveOfPlay0.action = END_TURN;
    playMove(game1,moveOfPlay1);
    assert(isValidMove(game1,moveOfPlay1) == TRUE);
    assert(currentTurn(game1) == 1);
    assert(numTurns(game1) == 2);
}
void theSecond(void){
    printf("There are 28 cards.one is red hearts 3, one is backwards red clubs and others are 3 purple clubs.\n");
    value values[28];
    suit suits[28];
    color colors[28];
    
    int i = 0;
    values[i] = THREE;
    suits[i] = HEARTS;
    colors[i] = RED;
    int j = 1;
    values[j] = BACKWARDS;
    suits[j] = CLUBS;
    colors[j] = RED;
    int l = 2;
    while(l < 25){
        values[l] = THREE;
        suits[l] = CLUBS;
        colors[l] = PURPLE;
        l++;
    }
    //test1
    Game game2 = newGame(25, values, colors, suits);
    printf("Check the first player is 0\n");
    assert(currentPlayer(game2) == 0);
    printf("The turn number should start at 0 once the game has started.\n");
    assert(currentTurn(game2) == 0);
    assert(playDirection(game2)== CLOCKWISE);
    printf("The value of first card");
    Card firstCard = handCard(game2,0);
    assert(firstCard->thisCardValue == THREE);
    printf("The num color of first card");
    assert(numOfColor(game2,RED) == 2);
    printf("The num suit of first card");
    assert(numOfSuit(game2,HEARTS) == 1);
    printf("The num value of first card");
    assert(numOfValue(game2,THREE) == 24);
    assert(playerCardCount(game2,0) == 7);
    playerMove moveOfPlay0;
    Card testCard = newCard(THREE,RED,HEARTS);
    assert(testCard -> thisCardValue == THREE);
    assert(testCard -> thisCardSuit == HEARTS);
    assert(testCard -> thisCardColor == RED);
    moveOfPlay0.card = newCard(THREE,RED,HEARTS);
    moveOfPlay0.action = PLAY_CARD;
    playMove(game2,moveOfPlay0);
    assert(isValidMove(game2,moveOfPlay0) == TRUE);
    moveOfPlay0.action = END_TURN;
    playMove(game2,moveOfPlay0);
    assert(isValidMove(game2,moveOfPlay0) == TRUE);
    assert(currentTurn(game2) == 0);
    assert(numTurns(game2) == 1);
    //test2
    printf("Check the second player is 1\n");
    assert(currentPlayer(game2) == 1);
    printf("The turn number should start at 1 once the game has started.\n");
    assert(currentTurn(game2) == 1);
    assert(playDirection(game2)== CLOCKWISE);
    printf("The value of second card");
    Card secondCard = handCard(game2,1);
    assert(secondCard->thisCardValue == BACKWARDS);
    printf("The num color of second card");
    assert(numOfColor(game2,PURPLE) == 23);
    printf("The num suit of second card");
    assert(numOfSuit(game2,CLUBS) == 24);
    printf("The num value of second card");
    assert(numOfValue(game2, BACKWARDS) == 1);
    assert(playerCardCount(game2,0) == 6);
    assert(playerCardCount(game2,1) == 7);
    playerMove moveOfPlay1;
    Card testSecondCard = newCard(THREE,RED,HEARTS);
    assert(testSecondCard -> thisCardValue == THREE);
    assert(testSecondCard -> thisCardSuit == HEARTS);
    assert(testSecondCard -> thisCardColor == RED);
    moveOfPlay1.card = testSecondCard;
    moveOfPlay1.action = PLAY_CARD;
    playMove(game2,moveOfPlay1);
    assert(isValidMove(game2,moveOfPlay1) == TRUE);
    moveOfPlay1.action = END_TURN;
    assert(playDirection(game2) == ANTICLOCKWISE);
    playMove(game2,moveOfPlay1);
    assert(isValidMove(game2,moveOfPlay1) == TRUE);
    assert(currentTurn(game2) == 1);
    assert(numTurns(game2) == 2);
    assert(currentPlayer(game2) == 0);
    assert(playDirection(game2) == ANTICLOCKWISE);
}

