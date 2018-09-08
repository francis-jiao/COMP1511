// An initial A.I. player for Final Card-Down.
//
// Van Minh Tran (z5135094)
// Mingfang Jiao (z5142125)

#include "Game.h"
#include "player.h"
#include "Card.h"
#define pending 7

#define NOT_FOUND -1

// Find a card in the player's hand that matches the specified color,
// if such a card exists.
// Returns the card index, or NOT_FOUND if no matching card was found.
static int findMatchingCardColor (Game game, color color);

// Do two cards match on either value, color, or suit?
// Returns TRUE if they match any of the above features, and
// FALSE if they don't match on any of the above features.
static int doCardsMatch (Card first, Card second);

// Determine whether the player can currently draw a card.
// If they can't draw a card, they should probably end their turn.
static int canDrawCard (Game game);

// Determine whether the current player should SAY_UNO.
// There are two different situations where it could be a
// valid move to SAY_UNO.
// For now, just deal with the simple situation: "claim card".
// Note: there are several possible ways to determine this.
static int shouldSayUNO (Game game);

// Determine whether the current player should SAY_UNO.
// There are two different situations where it could be a
// valid move to SAY_DUO.
// For now, just deal with the simple situation: "claim card".
// Note: there are several possible ways to determine this.
static int shouldSayDUO (Game game);

// Determine whether the current player should SAY_UNO.
// There are two different situations where it could be a
// valid move to SAY_TRIO.
// For now, just deal with the simple situation: "claim card".
// Note: there are several possible ways to determine this.
static int shouldSayTRIO (Game game);


// This function is to be implemented by the A.I.
// It will be called when the player can make an action on their turn.
//
// !!!!!   The function is called repeatedly, until   !!!!!
// !!!!!      they make the action `END_TURN`.        !!!!!
//
// If the player's turn is skipped, this funciton
// is *not* called for that player.
//
// Don't forget about the `isValidMove` function -- it's a handy way
// to work out before you play a move whether or not it will be valid
// (and you should only ever be making valid moves).
//
// You can also use it to help you work out where you are at in the
// game, without needing to look through all of the previous state
// yourself --
//
// Looking at the diagram of valid moves at any given point in the game,
// we can see that at the start of the game, it's valid to:
//   - call somebody out for forgetting to SAY_UNO / SAY_DUO / SAY_TRIO,
//   - draw a card,
//   - play a card, *if* you have a valid card that you can play.
//
// It's not valid to end your turn unless you've done some other
// action/s (again, see the diagram).
//
// We can take advantage of that for our very simple A.I. to determine
// where we are at in our turn, and thus what move we should make.


playerMove decideMove(Game game) {
    int currentMove=0;// Start out by making a move struct, to say what our move is.
    playerMove move;
    int myround=0;

    // Set our move to be END_TURN, and check whether that's
    // a valid move -- if it is, then just end our turn (for now).
    move.action = END_TURN;
    int canPlay = pending;
    int canDraw = pending;
    int cansayuno = pending;
    int cansayduo = pending;
    int cansaytrio = pending;
    // If it's not valid to end turn, we must need to make
    // some other action...
    //
    // What actions are valid at this point?
    if (isValidMove(game, move) == FALSE) {       
        move.action = PLAY_CARD;
        int i =0;
        canPlay = FALSE;
        while(i< handCardCount(game) && canPlay == FALSE) {
            move.card = handCard(game,i);
            if(isValidMove(game,move) == TRUE) {
                canPlay = TRUE;
            }
            i++;
        }
        if(canPlay == FALSE) {
            move.action = DRAW_CARD;
            canDraw = FALSE;
            if(isValidMove(game,move) == TRUE) {
                canDraw = TRUE;
            }
        }
        if(canPlay == FALSE && canDraw == FALSE) {
            move.action = SAY_UNO;
            cansayuno = FALSE;
            if(shouldSayUNO(game) == TRUE) {
                cansayuno = TRUE;
            }
        }
        if(canPlay == FALSE && canDraw == FALSE && cansayuno == FALSE) {
            move.action = SAY_DUO;
            cansayduo = FALSE;
            if(shouldSayDUO(game)== TRUE) {
                cansayduo = TRUE;
            }
        }
        if(canPlay == FALSE && canDraw == FALSE && cansayuno == FALSE && cansayduo == FALSE) {
            move.action = SAY_TRIO;
            cansayduo = FALSE;
            if(shouldSayTRIO(game) == TRUE) {
                cansayduo = TRUE;
            }
        }
    }
    currentMove++;
    if(move.action == SAY_UNO) {
        if(pastMove(game,currentTurn(game),currentMove).action == SAY_UNO) {
            move.action = END_TURN;
        }
    }
    if(move.action == SAY_DUO) {
        if(pastMove(game,currentTurn(game),currentMove).action == SAY_DUO) {
            move.action = END_TURN;
        }
    }
    if(move.action == SAY_TRIO) {
        if(pastMove(game,currentTurn(game),currentMove).action == SAY_TRIO) {
            move.action = END_TURN;
        }
    }
    if(move.action == END_TURN) {
        myround++;
        currentMove = 0;
    }
    return move;
}

       // Valid actions include:
        //   - play a card,
        //   - draw a card,
        //   - call the previous play out for forgetting to SAY_UNO etc.
        //
        // The easiest thing here is to draw a card, since we don't
        // need to try to work out if we have a valid card, etc.


// Find a card in the player's hand that matches the specified color,
// if such a card exists.
// Returns the card index, or NOT_FOUND if no matching card was found.
static int findMatchingCardColor (Game game, color color){
    int i = 0;
    while(i < handCardCount(game) && cardColor(handCard(game, i)) != color) {
        i++;
    }
    if(i == handCardCount(game)){
        return NOT_FOUND;
    } else {
        return i;
    }
}

// Do two cards match on either value, color, or suit?
// Returns TRUE if they match any of the above features, and
// FALSE if they don't match on any of the above features.
static int doCardsMatch (Card first, Card second)  {
    int state = FALSE;
    if(cardValue(second) != 2) {
        if(cardColor(first) == cardColor(second) || cardSuit(first) == cardSuit(second) || cardValue(first) == cardValue(second)) {
            state = TRUE;
        }
    } else {
        if(cardValue(first) == cardValue(second)){
            state = TRUE;
        }
    }
    return state;
}

// Determine whether the player can currently draw a card.
// If they can't draw a card, they should probably end their turn.
static int canDrawCard (Game game) {
    int i = 0;
    int turn = currentTurn(game);
    int state = TRUE;
    while(i < turnMoves(game, turn)) {
        if(pastMove(game, turn, i).action == PLAY_CARD){
            state = FALSE;
        }
        i++;
    }
    return state;
}

/*static int canPlayCard(Game game) {
    int state = FALSE;
    int i=0;
    int turn = currentTurn(game);
    turn --;
    while(i<turnMoves(game,turn)) {
        if(pastMove(game,turn,i).action== PLAY_CARD) {
            card temp = pastMove(game,turn,i).card;
            int handcardcount = handCardCount(game);
            int cardnum = 0;
            while(cardnum < handcard) {
                if(doCardsMatch(temp,handCard(game,cardnum)==TRUE) {
                    state = TRUE;
                    move.action=PLAY_CARD;
                    int playcard = move.card;
                    if(handCard(game,cardnum)->cardColor == temp->cardColor) {
                        cardColor(move.card) = temp->cardColor(temp);
                    } else if(cardValue(handCard(game,cardnum)) == cardValue(temp)) {
                        cardValue(move.card) = cardValue(temp);
                    } else if(cardSuit(handCard(game,cardnum)) == cardSuit(temp)) {
                        cardSuit(move.card) = cardSuit(temp);
                    }
                }
                cardnum++;
            }
        }
        i++;
    }
*/

                        


// Determine whether the current player should SAY_UNO.
// There are two different situations where it could be a
// valid move to SAY_UNO.
// For now, just deal with the simple situation: "claim card".
// Note: there are several possible ways to determine this.
static int shouldSayUNO (Game game){
    int state = FALSE;
    if(handCardCount(game) == 3) {
        state = TRUE;
    }
    return state;
}

// Determine whether the current player should SAY_UNO.
// There are two different situations where it could be a
// valid move to SAY_DUO.
// For now, just deal with the simple situation: "claim card".
// Note: there are several possible ways to determine this.
static int shouldSayDUO (Game game) {
    int state = FALSE;
    if(handCardCount(game) == 2) {
        state = TRUE;
    }
    return state;
}

// Determine whether the current player should SAY_UNO.
// There are two different situations where it could be a
// valid move to SAY_TRIO.
// For now, just deal with the simple situation: "claim card".
// Note: there are several possible ways to determine this.
static int shouldSayTRIO (Game game){
    int state = FALSE;
    if(handCardCount(game) == 1) {
        state = TRUE;
    }
    return state;
}
/*static int isValidMove (Game game, playerMove move) {
    int state = FALSE;
    if(move.action == DRAW_CARD) {
        if(canDrawCard(game) == TRUE) {
            state = TRUE;
        }
    } else if (move.action == PLAY_CARD) {
        if(doCardsMatch(move.card, topDiscard(game)) == TRUE){
            state = TRUE;
        }
    } else if(move.action == END_TURN) {
        int turn = currentTurn(game);
        int move = turnMoves(game, turn)-1;
        while(move >= 0){
            if(pastMove(game, turn, move).action == PLAY_CARD || pastMove(game, turn, move).action == DRAW_CARD) {
                state = TRUE;
            }
            move--;
        }
    } else if(move.action == SAY_UNO) {
        if(shouldSayUNO == TRUE) {
            state = TRUE;
        }
    } else if(move.action == SAY_DUO) {
        if(shouldSayDUO == TRUE) {
            state = TRUE;
        }
    } else if(move.action == SAY_TRIO) {
        if(shouldSayTRI0 == TRUE) {
            state = TRUE;
        }
    }
    return state;
}*/
