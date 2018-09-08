//Mingfang jiao z5142125
//Kai Xiang Yong z5175681
//Van Minh Tran z5135094
//Jiaxi Zhang z5134854
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Card.h"
#define MAX_TURN 200
#define MAX_MOVE 100

typedef struct _player *Player;
typedef struct _node *Node;
typedef struct _node {
    Card card;
    Node next;
} node;
typedef struct _deck{
    Node head;
    int numCard;
} deck;
typedef struct _player{
    int point;
    deck handCards;
} player;
typedef struct _game {
    deck drawDeck;
    deck discardDeck;
    player player1;
    player player2;
    player player3;
    player player0;
    direction currDirection;
    int currTurn;
    int currPlayer;
    int currentDrawTwo;
    int currMove;
    playerMove playerMove[MAX_TURN][MAX_MOVE];
    int turnMoves[MAX_TURN];
    color declare;
    int isDeclared;
    int currTurnMoveLeft;
} game;
void cardPush(deck deck, Card card);
void drawCard(Game games, deck toDeck);
Card getCard(Node node);
void nodePop(deck deck, Card card);
Node newNode(deck deck, Card card);
void nodePush(deck deck, Node node);
void nodePush(deck deck, Node node){
    Node curr = deck.head;
    if (deck.head == NULL){
        deck.head = node;
    } else {
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
    }
}
// Get a card from node
Card getCard (Node node){
    return node->card;
}
// Add a card into a deck (eg. handCards, drawDeck)
void cardPush(deck deck, Card card) {
 int i = 1;
 Node head = deck.head;
 Node newNode = calloc(1, sizeof(node));
 newNode->card = card;
 newNode->next = NULL;
 while (head->next != NULL) {
        head = head->next;
        i++;
 }
 head->next = newNode;
 deck.numCard = i + 1;
}
void nodePop(deck deck, Card card){
    Node curr = deck.head;
    while (cardValue(curr->next->card) != cardValue(card) &&
            cardColor(curr->next->card) != cardColor(card) &&
            cardSuit(curr->next->card) != cardSuit(card)){
        curr = curr->next;
    }
    curr->next = curr->next->next;
}
// Draw a card from drawDeck (toDeck is player's deck)
void drawCard(Game game, deck toDeck) {
    Node curr = game->drawDeck.head;
    while (curr->next->next != NULL);
    game->drawDeck.numCard--;
    curr->next = NULL;
    nodePush(toDeck, curr);
}
Game newGame (int deckSize, value values[], color colors[], suit suits[]){
    Game game = calloc(1, sizeof(game));
    int i = 0;
    while (i < deckSize){
        Card card = newCard(values[i], colors[i], suits[i]);
        cardPush (game->drawDeck, card);
        i++;
    }
    int j = 0;
    while (j<7){
        drawCard(game, game->player0.handCards);
        drawCard(game, game->player1.handCards);       
        drawCard(game, game->player2.handCards);
        drawCard(game, game->player3.handCards);
        j++;
    }
    Node curr = game->drawDeck.head;
    while (curr->next != NULL){
        nodePush(game->discardDeck, curr);
    }
    game->currDirection = CLOCKWISE;
    game->currTurn = 0;
    game->currPlayer = 0;
    game->currentDrawTwo = 0;
    game->isDeclared = FALSE;
    game->currTurnMoveLeft = 1;
    // First card effect
    if (cardValue(curr->card) == ADVANCE){
        game->currPlayer++;
    } else if (cardValue(curr->card) == BACKWARDS){
        game->currDirection = ANTICLOCKWISE;
    } else if (cardValue(curr->card) == DRAW_TWO){
        game->currentDrawTwo = game->currentDrawTwo + 2;
    }
    return game;
}
void destroyGame(Game game){
    free(game);
}
int numCards(Game game){
    Node curr = game->drawDeck.head;
    int i = 0;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    curr = game->discardDeck.head;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    curr = game->player0.handCards.head;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    curr = game->player1.handCards.head;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    curr = game->player2.handCards.head;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    curr = game->player3.handCards.head;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    return i;
}
int numOfSuit(Game game, suit suit){
    Node curr = game->drawDeck.head;
    int i = 0;
    while(curr != NULL){
        if (cardSuit(curr->card) == suit){
            i++;
        }
        curr = curr->next;
    }
    curr = game->discardDeck.head;
    while(curr != NULL){
        if (cardSuit(curr->card) == suit){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player0.handCards.head;
    while(curr != NULL){
        if (cardSuit(curr->card) == suit){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player1.handCards.head;
    while(curr != NULL){
        if (cardSuit(curr->card) == suit){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player2.handCards.head;
    while(curr != NULL){
        if (cardSuit(curr->card) == suit){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player3.handCards.head;
    while(curr != NULL){
        if (cardSuit(curr->card) == suit){
            i++;
        }
        curr = curr->next;
    }
    return i;
}
int numOfColor(Game game, color color){
    Node curr = game->drawDeck.head;
    int i = 0;
    while(curr != NULL){
        if (cardColor(curr->card) == color){
            i++;
        }
        curr = curr->next;
    }
    curr = game->discardDeck.head;
    while(curr != NULL){
        if (cardColor(curr->card) == color){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player0.handCards.head;
    while(curr != NULL){
        if (cardColor(curr->card) == color){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player1.handCards.head;
    while(curr != NULL){
        if (cardColor(curr->card) == color){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player2.handCards.head;
    while(curr != NULL){
        if (cardColor(curr->card) == color){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player3.handCards.head;
    while(curr != NULL){
        if (cardColor(curr->card) == color){
            i++;
        }
        curr = curr->next;
    }
    return i;
}
int numOfValue(Game game, value value){
    Node curr = game->drawDeck.head;
    int i = 0;
    while(curr != NULL){
        if (cardValue(curr->card) == value){
            i++;
        }
        curr = curr->next;
    }
    curr = game->discardDeck.head;
    while(curr != NULL){
        if (cardValue(curr->card) == value){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player0.handCards.head;
    while(curr != NULL){
        if (cardValue(curr->card) == value){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player1.handCards.head;
    while(curr != NULL){
        if (cardValue(curr->card) == value){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player2.handCards.head;
    while(curr != NULL){
        if (cardValue(curr->card) == value){
            i++;
        }
        curr = curr->next;
    }
    curr = game->player3.handCards.head;
    while(curr != NULL){
        if (cardValue(curr->card) == value){
            i++;
        }
        curr = curr->next;
    }
    return i;
}
int currentPlayer(Game game){
    return game->currPlayer;
}
int currentTurn(Game game){
    return game->currTurn;
}
int playerPoints(Game game, int player){
    int points = 7;
    if (player == 0){
        points = game->player0.handCards.numCard;
    } else if (player == 1){
        points = game->player1.handCards.numCard;
    } else if (player == 2){
        points = game->player2.handCards.numCard;
    } else {
        points = game->player3.handCards.numCard;
    }
    return points;
}
direction playDirection(Game game){
    return game->currDirection;
}
Card topDiscard(Game game){
    Node curr = game->discardDeck.head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    return curr->card;
}
// This function returns the number of turns that have occurred in the
// game so far including the current turn.
// When using either the turnMoves or pastMove function,
// the turn number should be less than the number of moves that this
// function returns.
// (i.e. on turn 0 of the game, this should return 1, as there has been
// 1 turn so far including the current turn; if you called pastMove you
// would need to call it on turn 0, as this is the only possible value
// less than 1.)
int numTurns(Game game){
    return game->currTurn + 1;
}
// Get the number of moves that happened on a turn.
// A turn may consist of multiple moves such as drawing cards,
// playing cards, and ending the turn.
int turnMoves(Game game, int turn){
    return game->turnMoves[turn];
}
// Look at a previous move from a specified turn.
playerMove pastMove(Game game, int turn, int move){
    return game->playerMove[turn][move];
}
int playerCardCount(Game game, int player){
    int handCards = 0;
    // Count player's handCards
    if (player == 0){
        int handCards = game->player0.handCards.numCard;
    } else if (player == 1){
        int handCards = game->player1.handCards.numCard;
    } else if (player == 2){
        int handCards = game->player2.handCards.numCard;
    } else {
        int handCards = game->player3.handCards.numCard;
    }
    return handCards;
}
int handCardCount(Game game){
    int player = game->currPlayer;
    int handCards = -1;
    // Count player's handCards
    if (player == 0){
        handCards = game->player0.handCards.numCard;
    } else if (player == 1){
        handCards = game->player1.handCards.numCard;
    } else if (player == 2){
        handCards = game->player2.handCards.numCard;
    } else {
        handCards = game->player3.handCards.numCard;
    }
    return handCards;
}
Card handCard(Game game, int card){
    int player = game->currPlayer;
    int i = 0;
    Node curr = game->player0.handCards.head;
    // Count player's handCards
    if (player == 0){
        curr = game->player0.handCards.head;
        while (i != card){
            curr = curr->next;
            i++;
        }
    } else if (player == 1){
        Node curr = game->player1.handCards.head;
        while (i != card){
            curr = curr->next;
            i++;
        }
    } else if (player == 2){
        Node curr = game->player2.handCards.head;
        while (i != card){
            curr = curr->next;
            i++;
        }
    } else {
        Node curr = game->player3.handCards.head;
        while (i != card){
            curr = curr->next;
            i++;
        }
    }
    return curr->card;
}
////////////////////////////////////////Need Some Work////////////////////////////////////////
// Check if a given move is valid.
//
// If the last player played a 2 (DRAW_TWO),
// the next player must either play a 2
// or draw 2 cards.
// Otherwise, the player must play a card that is either a ZERO
// or that has the same color, value, or suit as the card on the top
// of the discard pile.
//
// If the player plays an ADVANCE, the next player's turn is skipped.
// If the player plays a BACKWARDS, the currDirection of play is reversed.
// If the player plays a CONTINUE, they may play another card.
// If the player plays a DECLARE, they must also state which color
// the next player's discarded card should be.
//
// A player can only play cards from their hand.
// A player may choose to draw a card instead of discarding a card.
// A player must draw a card if they are unable to discard a card.
//
// This check should verify that:
// * The card being played is in the player's hand
// * The player has played at least one card before finishing their turn,
//   unless a draw-two was played, in which case the player may not
//   play a card, and instead must draw the appropriate number of cards.
int isValidMove(Game game, playerMove move){
    // First check the value, suit and color
    int moveLeft = 1;
    Card toPlay = move.card;
    Card discardTop = topDiscard(game);
    // Exceed move allowed
    if (game->currTurnMoveLeft == -1){
        return FALSE;
    }
    if (move.action == PLAY_CARD){
        if (cardValue(toPlay) != cardValue(discardTop)
            && cardColor(toPlay) != cardColor(discardTop)
            && cardSuit(toPlay) != cardSuit(discardTop)){
            if (game->isDeclared == TRUE){
                if (cardColor(toPlay) != game->declare){
                    return FALSE;
                } else {
                    game->declare = FALSE;
                }
            }
        }
        // Draw 2
        if (game->currentDrawTwo != 0){
            if (cardValue(toPlay) != DRAW_TWO){
                if (cardValue(toPlay) != ZERO){
                    if (cardValue(toPlay) == cardValue(discardTop) ||
                        cardColor(toPlay) == cardColor(discardTop) ||
                        cardSuit(toPlay) == cardSuit(discardTop)){
                            game->currentDrawTwo = 0;
                            return TRUE;
                    } else {
                        return FALSE;
                    }
                }
            }
        }
        // Special Cards
        if (cardValue(toPlay) == ADVANCE){
            if (game->currDirection == CLOCKWISE){
                game->currPlayer++;
                game->currPlayer = game->currPlayer%4;
            } else {
                game->currPlayer--;
                if (game->currPlayer == -1){
                    game->currPlayer = 3;
                }
            }
        }
        else if (cardValue(toPlay) == DRAW_TWO){
            game->currentDrawTwo = game->currentDrawTwo + 2;
        }
        else if (cardValue(toPlay) == BACKWARDS){
            if (game->currDirection == CLOCKWISE){
                game->currDirection = ANTICLOCKWISE;
                game->currPlayer = game->currPlayer - 2;
                if (game->currPlayer == -2){
                    game->currPlayer = 2;
                } else if (game->currPlayer == -1){
                    game->currPlayer = 3;
                }
            } else {
                game->currDirection = CLOCKWISE;
                game->currPlayer = (game->currPlayer + 2) % 4;
            }
        }
        else if (cardValue(toPlay) == CONTINUE){
            moveLeft++;
        }
        else if (cardValue(toPlay) == DECLARE){
            game->isDeclared = TRUE;
            game->declare = move.nextColor;
        }
        moveLeft--;
        // Exceed Move Allowed
        if (moveLeft == -1){
            return FALSE;
        }
    } else if (move.action == DRAW_CARD){
        if (game->currentDrawTwo != 0){
            game->currentDrawTwo--;
        } else {
            moveLeft--;
        }
    } else if (move.action == SAY_TRIO){
        if (handCardCount(game) != 3){
            game->currentDrawTwo = game->currentDrawTwo + 4;
        }
    } else if (move.action == SAY_DUO){
        if (handCardCount(game) != 2){
            game->currentDrawTwo = game->currentDrawTwo + 4;
        }
    } else if (move.action == SAY_UNO){
        if (handCardCount(game) != 1){
            game->currentDrawTwo = game->currentDrawTwo + 4;
        }
    } else if (move.action == END_TURN) {
        // No move
        if (moveLeft == 1){
            return FALSE;
        }
    } else {
        return TRUE;
    }
    return TRUE;
}
// Play the given action for the current player
//
// If the player makes the END_TURN move, their turn ends,
// and it becomes the turn of the next player.
// This should _not_ be called by the player AI.
void playMove(Game game, playerMove move) {
    int player = game->currPlayer;
    int currTurn = game->currTurn;
    int currMove = game->currMove;
    game->currTurnMoveLeft = 1;
    if (move.action == DRAW_CARD) {
        game->playerMove[currTurn][currMove].action = DRAW_CARD;
        if (player == 0){
            drawCard(game, game->player0.handCards);
        } else if (player == 1) {
            drawCard(game, game->player1.handCards);
        } else if (player == 2) {
            drawCard(game, game->player2.handCards);
        } else {
            drawCard(game, game->player3.handCards);
        }
    } else if (move.action == SAY_TRIO) {
        game->playerMove[currTurn][currMove].action = SAY_TRIO;
    } else if (move.action == SAY_DUO) {
        game->playerMove[currTurn][currMove].action = SAY_DUO;
    } else if (move.action == SAY_UNO) {
        game->playerMove[currTurn][currMove].action = SAY_UNO;
    } else if (move.action == PLAY_CARD) {
        Card toPlay = move.card;
        if (player == 0){
            nodePop(game->player0.handCards, toPlay);
        } else if (player == 1) {
            nodePop(game->player1.handCards, toPlay);
        } else if (player == 2) {
            nodePop(game->player2.handCards, toPlay);
        } else {
            nodePop(game->player3.handCards, toPlay);
        }
        cardPush(game->discardDeck, toPlay);
        game->playerMove[currTurn][currMove].action = PLAY_CARD;
        game->playerMove[currTurn][currMove].card = toPlay;
        game->currTurnMoveLeft--;
    } else if (move.action == END_TURN) {
        if (game->currDirection == CLOCKWISE){
            game->currPlayer = (game->currPlayer + 1) % 4;
        } else {
            game->currPlayer--;
            if (game->currPlayer == -1){
                game->currPlayer = 3;
            }
        }
        game->playerMove[currTurn][currMove].action = END_TURN;
        game->currMove++;
        game->turnMoves[currTurn] = currMove;
        currTurn++;
    }
}
// Check the game winner.
//
// Returns NOT_FINISHED if the game has not yet finished,
// 0-3, representing which player has won the game, or
// NO_WINNER if the game has ended but there was no winner.
int gameWinner(Game game) {
    int winner = NO_WINNER;
    if (playerPoints(game, 0) == 0){
        winner = 0;
    } else if (playerPoints(game, 1) == 0){
        winner = 1;
    } else if (playerPoints(game, 2) == 0){
        winner = 2;
    } else if (playerPoints(game, 3) == 0){
        winner = 3;
    } else if (game->drawDeck.numCard == 1){
        return NO_WINNER;
    }else {
        winner = NOT_FINISHED;
    }
    return winner;
}
