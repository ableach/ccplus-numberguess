/*
Author: ableach
Date: 31/12/20
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTRIES 8
#define LOWRANGE 1
#define HIGHRANGE 99

int main() {
    /*****************
    * Define variables
    ******************/
    enum boolean {FALSE, TRUE};
    _Bool showSampleData = FALSE;
    _Bool correctGuess = FALSE;
    int guess, guessesRemaining;
    
    /***********************
    * Generate random number
    ************************/
    // use traditional method of seeding (requires time.h):
    time_t t;
    srand((unsigned) time(&t));
    // this is an alternative way of seeding using time used by CPU
    //clock_t ticks = clock();
    //srand((unsigned) ticks);
    
    int randomNumber = (rand() % (HIGHRANGE - LOWRANGE + 1)) + LOWRANGE; 
    //int randomNumber = rand() % 21;
    //printf("rn=%d\n\n", randomNumber);
    
    /*******************
    * Optional Test Data
    ********************/
    if ( showSampleData ) {
        for (int i=0; i<10; i++) {
            randomNumber = (rand() % (HIGHRANGE - LOWRANGE + 1)) + LOWRANGE; 
            printf("rn=%d\n", randomNumber);
        }
    }
 
    /**************
    * Play the game
    ***************/
    printf("\nIn this game you have %d tries to guess a number between %d and %d.\n", MAXTRIES, LOWRANGE, HIGHRANGE);
    printf("\nPlease enter your guess: ");
    for ( guessesRemaining = MAXTRIES; guessesRemaining > 0; guessesRemaining-- ) {
        if ( guessesRemaining < MAXTRIES ) {
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