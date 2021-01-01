/*
Author: ableach
Date: 31/12/20

Usage:
------
./guess
uses default max tries and range

./guess {a}
./guess {a} {b}
./guess {a} {b} {c}
where
{a} = Max number of tries
{b} = Low range value
{c} = High range value

e.g. 
./guess 5 1 50
5 tries to guess number between 1 and 50

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTRIES 8
#define LOWRANGE 1
#define HIGHRANGE 99

int main(int argc, char *argv[]) {
    /*****************
    * Define variables
    ******************/
    enum boolean {FALSE, TRUE};
    _Bool showSampleData = FALSE;
    _Bool correctGuess = FALSE;
    int guess, guessesRemaining;

    /******************
    * Handle arguments
    *******************/
    int highRange, lowRange, maxTries;
    if ( argc == 4 ) {
        highRange = atoi(argv[3]);
    } else {
        highRange = HIGHRANGE;
    }
    if ( argc >= 3 ) {
        lowRange = atoi(argv[2]);
    } else {
        lowRange = LOWRANGE;
    }
    if ( argc >= 2 ) {
        maxTries = atoi(argv[1]);
    } else {
        maxTries = MAXTRIES;
    }
    
    /***********************
    * Generate random number
    ************************/
    // use traditional method of seeding (requires time.h):
    time_t t;
    srand((unsigned) time(&t));
    // this is an alternative way of seeding using time used by CPU
    //clock_t ticks = clock();
    //srand((unsigned) ticks);
    
    int randomNumber = (rand() % (highRange - lowRange + 1)) + lowRange; 
    //int randomNumber = rand() % 21;
    //printf("rn=%d\n\n", randomNumber);
    
    /*******************
    * Optional Test Data
    ********************/
    if ( showSampleData ) {
        for (int i=0; i<10; i++) {
            randomNumber = (rand() % (highRange - lowRange + 1)) + lowRange; 
            printf("rn=%d\n", randomNumber);
        }
    }
 
    /**************
    * Play the game
    ***************/
    printf("\nIn this game you have %d tries to guess a number between %d and %d.\n", maxTries, lowRange, highRange);
    printf("\nPlease enter your guess: ");

    for ( guessesRemaining = maxTries; guessesRemaining > 0; guessesRemaining-- ) {
        if ( guessesRemaining < maxTries ) {
            printf("You have %d %s remaining. ", guessesRemaining, guessesRemaining == 1 ? "try" : "tries");
            printf("Please try again: ");
        }

        scanf("%d", &guess);
        
        if ( guess == randomNumber ) {
            correctGuess = TRUE;
            break;
        } else if ( guess < randomNumber ) {
            printf("\nYour guess is too low. ");
        } else {
            printf("\nYour guess is too high. ");
        }
    }

    if ( correctGuess ) {
        printf("\nCorrect! Well done.\n");
    } else {
        printf("\n\nThe number was %d. Better luck next time.\n", randomNumber);
    }
    
    return 0;
}