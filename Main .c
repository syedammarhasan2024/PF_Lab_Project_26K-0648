# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>

int pointsArr[2][50] = {0};

void warmerColder(char player1_name[], char player2_name[]){

    int actualNum, guessedNum, guesses, prevGuess, numRounds = 0, roundOverFlag = 0, player1_guesses, player2_guesses;
    int player1_winFlag = 0, player2_winFlag = 0;
    int invalidNumberInput, clearInput;
    char choice1, tempPlayer1_Name[20], tempPlayer2_Name[20], nameSwapVar[20];

    do {
        printf("\n\n\n");
        printf("\t\t\t\t\033[1;38;5;231mWelcome to the warmer-colder game!\033[0m\n");
        printf("\nFor instructions, press (i)\n"
            "To start playing, press (p)\n"
            "Enter your choice: ");
        choice1 = _getch();

        if (choice1 != 'i' && choice1 != 'I' && choice1 != 'p' && choice1 != 'P'){
            printf("Invalid choice, try again!\n");
        }

    } while (choice1 != 'i' && choice1 != 'I' && choice1 != 'p' && choice1 != 'P');

    if (choice1 == 'i' || choice1 == 'I'){
        printf("\n\nHow to play:\n"
               "1.  There are 2 rounds.\n"
               "2.  Round 1: %s picks a 1-100 number, %s guesses.\n"
               "3.  If %s guesses within 10 tries, %s wins the round.\n"
               "4a. After 1st guess: computer says \"warm\" or \"cold\".\n"
               "4b. \"Warm\" = %s's guess is within 10 of %s's number.\n"
               "4c. \"Cold\" = %s's guess is >10 away from %s's number.\n"
               "5a. Next guesses: computer says \"getting warmer\" or \"getting colder\".\n"
               "5b. \"Getting warmer\" = %s's guess is closer to %s's number than %s's previous.\n"
               "5c. \"Getting colder\" = %s's guess is further from %s's number than %s's previous.\n"
               "6.  Roles reverse in round 2.\n"
               "7.  One succeeds, one fails = successful player wins 3 pts.\n"
               "8.  Both succeed in different number of turns = fewer turns wins 1 pts.\n"
               "9.  Both succeed in equal turns = 1 pt each.\n"
               "10. Both fail = 0 pts.\n",
               player1_name, player2_name, player2_name, player2_name, player2_name, player1_name, player2_name, player1_name,
               player2_name, player1_name, player2_name, player2_name, player1_name, player2_name);

        printf("\nTo start the game press any key: ");
        _getch();


    }

    strcpy(tempPlayer1_Name, player1_name);
    strcpy(tempPlayer2_Name, player2_name);

    // I will use AI over here to get a possible double digit, or triple digit input from player 1 without showing it to the screen
    // This is because _getch() is only for single digit numbers or characters. I need a solution for this.

    do {
        numRounds += 1;
        guesses = 0;

        if (roundOverFlag == 1){
            printf("\nRound 2 begins:\n");
        }

        // AI start
        do {
            printf("\n\n\n%s, please enter a number from 1 to 100: ", tempPlayer1_Name);
            actualNum = 0;
            int digitsEntered = 0;
            char ch;

            invalidNumberInput = 0;

            while (1) {
                ch = _getch();
                if (ch == '\r' || ch == '\n') {
                    
                    if (digitsEntered > 0 || invalidNumberInput == 1) {
                        for (int i = 0; i < digitsEntered; i++) {
                            printf("\b \b");
                        }
                        break;
                    }
                } else if (ch == '\b') {
                    if (digitsEntered > 0) {
                        actualNum /= 10;
                        digitsEntered--;
                        printf("\b \b");
                    }
                } else if (ch >= '0' && ch <= '9') {
                    if (digitsEntered < 3) {
                        actualNum = (actualNum * 10) + (ch - '0');
                        digitsEntered++;
                        printf("%c", ch);
                    }
                    else {
                        
                        invalidNumberInput = 1;
                    }
                }
                else {
                    
                    invalidNumberInput = 1;
                }
            }
            // AI end
            if (invalidNumberInput == 1 || actualNum > 100 || actualNum < 1){
                printf("\n\nInvalid number, please try again!\n\n");
            }
            else {
                printf("\nThe number has been noted!\n\n");
            }

        } while (invalidNumberInput == 1 || actualNum > 100 || actualNum < 1);

        do {
            printf("%s, guess a number from 1 to 100: ", tempPlayer2_Name);

            // Used AI to check for letters instead of numbers

            if (scanf("%d", &guessedNum) != 1){
                while ((clearInput = getchar()) != '\n' && clearInput != EOF){}
                guessedNum = 0;
                printf("\n\nInvalid input, please enter a number!\n\n");
            }
            else if (guessedNum > 100 || guessedNum < 1){
                printf("\n\nInvalid guess, please try again!\n\n");
            }

        } while (guessedNum > 100 || guessedNum < 1);
        guesses += 1;

        if(guessedNum == actualNum){
            printf("\n\nWow! You got it first try! The number was %d\n", actualNum);
            printf("It took you %d turn!\n", guesses);

            if (roundOverFlag == 0){
                player2_guesses = guesses;
                player2_winFlag = 1;
            }
            else {
                player1_guesses = guesses;
                player1_winFlag = 1;
            }

        }
        else if (abs(actualNum - guessedNum) <= 10){
            printf("Warm!\n\n");
        }
        else{
            printf("Cold!\n\n");
        }

        if (guessedNum != actualNum){

            prevGuess = guessedNum;

            do {

                do {

                    if (guesses == 9){
                        printf("\nIts your last turn! You need to get it right!\n\n");
                    }

                    printf("%s, guess a number from 1 to 100: ", tempPlayer2_Name);

                    // Again used AI to check if letters input instead of numbers
                    if (scanf("%d", &guessedNum) != 1){
                        while ((clearInput = getchar()) != '\n' && clearInput != EOF){}
                        guessedNum = 0;
                        printf("\n\nInvalid input, please enter a number!\n\n");
                    }
                    else if (guessedNum > 100 || guessedNum < 1){
                        printf("\n\nInvalid guess, please try again!\n\n");
                    }

                } while (guessedNum > 100 || guessedNum < 1);
                guesses += 1;

                if (guessedNum == actualNum){
                    printf("You got it! The number was %d!\n", actualNum);
                    printf("It took you %d turns!\n", guesses);

                    if (roundOverFlag == 0){
                        player2_guesses = guesses;
                        player2_winFlag = 1;
                    }
                    else {
                        player1_guesses = guesses;
                        player1_winFlag = 1;
                    }


                }
                else if (abs(actualNum - guessedNum) <= abs(actualNum - prevGuess)){
                    printf("Getting warmer!\n\n");
                }
                else{
                    printf("Getting colder!\n\n");
                }

                prevGuess = guessedNum;

            } while (guesses < 10 && guessedNum != actualNum);

            if (guesses >= 10 && guessedNum != actualNum){
                printf("\n\nYou ran out of turns!\n\n");
            }

        }

        roundOverFlag = 1;

        strcpy(nameSwapVar, tempPlayer1_Name);
        strcpy(tempPlayer1_Name, tempPlayer2_Name);
        strcpy(tempPlayer2_Name, nameSwapVar);

    } while (numRounds != 2);

    if (player1_winFlag == 0 && player2_winFlag == 0){

        printf("\nGame Report:\n"
               "Both players were unable to guess the numbers\n");
        printf("\nBoth players get 0 points :(\n");
    }
    else if (player1_winFlag == 1 && player2_winFlag == 0){

        printf("\nGame Report:\n"
               "%s guessed the number in %d turns!\n"
               "%s was unable to guess the number\n", player1_name, player1_guesses, player2_name);
        printf("\n%s wins Warmer-Colder and gets 3 points!\n", player1_name);
    }
    else if (player1_winFlag == 0 && player2_winFlag == 1){

        printf("\nGame Report:\n"
               "%s guessed the number in %d turns!\n"
               "%s was unable to guess the number\n", player2_name, player2_guesses, player1_name);
        printf("\n%s wins Warmer-Colder and gets 3 points!\n", player2_name);
    }
    else {

        printf("\nGame Report:\n"
               "%s guesses the number in %d turns!\n"
               "%s guessed the number in %d turns!\n",
               player1_name, player1_guesses, player2_name, player2_guesses);

        if (player1_guesses == player2_guesses){
            printf("\nBoth players took the same amount of turns\n"
                "Both players get 1 point each!");
        }
        else if (player1_guesses < player2_guesses){
            printf("\n%s took fewer turns!\n"
                   "\n%s wins Warmer-Colder and gets 1 point\n",
                   player1_name, player1_name);
        }
        else if (player1_guesses > player2_guesses){
            printf("\n%s took fewer turns!\n"
                   "\n%s wins Warmer-Colder and gets 1 point\n",
                   player2_name, player2_name);
        }      
    }

}

void ticTacToe(char player1_name[], char player2_name[]){}



void hangman(char player1_name[], char player2_name[]){}




int rockPaperScissorsWinChecker(char player1_move, char player2_move){
    
    if (player1_move == player2_move){
        return 0;
    }
    else if ((player1_move == 'r' && player2_move == 's') || (player1_move == 'p' && player2_move == 'r') || (player1_move == 's' && player2_move == 'p')){
        return 1;
    }
    else {
        return 2;
    }
}

void rockPaperScissors(char player1_name[], char player2_name[]){

    int numGames, gamesCount = 0;
    char player1_move, player2_move;
    int winner, player1_rock_paper_scissors_points = 0, player2_rock_paper_scissors_points = 0;

    printf("\n\n\n");
    printf("\t\t\t\t\033[1;38;5;231mWelcome to the rock paper scissors game!\033[0m\n");
    printf("\t\t\t\t\033[1;38;5;159mEnter how many games you want to play: \033[0m");
    numGames = _getch() - '0';

    do {

        printf("\n\n\t\t\t\t\033[1;38;5;220mGame %d:\033[0m\n\n", gamesCount + 1);

        do {
            printf("\t\t\t\t\033[1;38;5;231m%s\033[1;38;5;159m's turn: \033[0m\n", player1_name);
            printf("\t\t\t\t\033[1;38;5;159mChoose rock \033[1;38;5;231m(r)\033[1;38;5;159m, paper \033[1;38;5;231m(p)\033[1;38;5;159m, or scissors \033[1;38;5;231m(s)\033[1;38;5;159m: \033[0m");
            player1_move = _getch();
            if (player1_move != 'r' && player1_move != 'p' && player1_move != 's'){
                printf("\n\t\t\t\t\033[1;38;5;203mYour entry was invalid, please try again, %s\033[0m\n\n", player1_name);
            }
            else {
                printf("\n\t\t\t\t\033[1;38;5;42m%s's move has been noted!\033[0m\n\n", player1_name);
            }
        }   while (player1_move != 'r' && player1_move != 'p' && player1_move != 's');

        do {
            printf("\t\t\t\t\033[1;38;5;231m%s\033[1;38;5;159m's turn: \033[0m\n", player2_name);
            printf("\t\t\t\t\033[1;38;5;159mChoose rock \033[1;38;5;231m(r)\033[1;38;5;159m, paper \033[1;38;5;231m(p)\033[1;38;5;159m, or scissors \033[1;38;5;231m(s)\033[1;38;5;159m: \033[0m");
            player2_move = _getch();
            if (player2_move != 'r' && player2_move != 'p' && player2_move != 's'){
                printf("\n\t\t\t\t\033[1;38;5;203mYour entry was invalid, please try again, %s\033[0m\n\n", player2_name);
            }
            else {
                printf("\n\t\t\t\t\033[1;38;5;42m%s's move has been noted!\033[0m\n", player2_name);
            }
        } while (player2_move != 'r' && player2_move != 'p' && player2_move != 's');

        winner = rockPaperScissorsWinChecker(player1_move, player2_move);

        if (winner == 0){
            printf("\n\t\t\t\t\033[1;38;5;231mBoth %s and %s chose (%c)\033[0m\n", player1_name, player2_name, player1_move);
            printf("\t\t\t\t\033[1;38;5;231mThis makes it a tie! Try again!\033[0m");
        }
        else if (winner == 1){
            printf("\n\t\t\t\t\033[1;38;5;198m%s chose (%c) while %s chose (%c)\033[0m\n", player1_name, player1_move, player2_name, player2_move);
            printf("\t\t\t\t\033[1;38;5;198m%s won this round!\033[0m", player1_name);
            gamesCount += 1;
            player1_rock_paper_scissors_points += 1;
        }
        else {
            printf("\n\t\t\t\t\033[1;38;5;198m%s chose (%c) while %s chose (%c)\033[0m\n", player1_name, player1_move, player2_name, player2_move);
            printf("\t\t\t\t\033[1;38;5;198m%s won this round!\033[0m", player2_name);
            gamesCount += 1;
            player2_rock_paper_scissors_points += 1;
        }
    
    } while (gamesCount < numGames);

    printf("\n\n\n\t\t\t\t\t\033[1;38;5;220m    Final Score: \033[0m\n"
           "\t\t\t\t\t    \033[1;38;5;220m%s ==> %d wins\033[0m\n"
           "\t\t\t\t\t    \033[1;38;5;220m%s ==> %d wins\033[0m\n",
           player1_name, player1_rock_paper_scissors_points, player2_name, player2_rock_paper_scissors_points);
        
    if (player1_rock_paper_scissors_points == player2_rock_paper_scissors_points){
        printf("\n\n\t\t\t\t\033[1;38;5;75mTHE SCORES ARE TIED, SO BOTH PLAYERS EARN 1 POINT\033[0m");
        //add points to array
    }
    else if (player1_rock_paper_scissors_points > player2_rock_paper_scissors_points){
        char temp_name[20]; 
        strcpy(temp_name, player1_name);
        printf("\n\n\t\t\t\t\033[1;38;5;220m%s WINS ROCK PAPER SCISSORS AND EARNS 3 POINTS!\033[0m\n", strupr(temp_name));
        //add points to array
    }
    else {
        char temp_name[20]; 
        strcpy(temp_name, player2_name);
        printf("\n\n\t\t\t\t\033[1;38;5;220m%s WINS ROCK PAPER SCISSORS AND EARNS 3 POINTS!\033[0m\n", strupr(temp_name));
        //add points to array
    }
}



int main(){

    char gamechoice = 'z';

    do {
        char menuChoice;
        char player1_name[20], player2_name[20];

        // Keep the terminal window at 106x32 for best viewing experience
        do {    
            printf("\n\033[1;38;5;75m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[1;38;5;220m Welcome to Ammar's Gaming Arcade! \033[1;38;5;75m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n");
            printf("\n");
            printf("\t\t\t\t \033[1;38;5;231mWhat game would you like to play?\033[0m\n"
                "\n"
                "\t\t\t\t          \033[1;38;5;159mHangman \033[1;38;5;231m(h)\033[0m\n"
                "\t\t\t\t         \033[1;38;5;159mTic-Tac-Toe \033[1;38;5;231m(t)\033[0m\n"
                "\t\t\t\t        \033[1;38;5;159mWarmer Colder \033[1;38;5;231m(w)\033[0m\n"
                "\t\t\t\t     \033[1;38;5;159mRock-Paper-Scissors \033[1;38;5;231m(r)\033[0m\n"
                "\t\t\t\t       \033[1;38;5;203mTo exit the game \033[1;38;5;231m(e)\033[0m\n\n");
            printf("\t\t\t\t  \033[1;38;5;231mEnter your game of choice: \033[0m");
            scanf(" %c", &gamechoice);
            printf("\n");

            if (gamechoice != 'h' && gamechoice != 't' && gamechoice != 'w' && gamechoice != 'r' && gamechoice != 'e'){
                printf("\t\t\t\033[1;38;5;203m You have entered an invalid choice, please try again! \033[0m");
                printf("\n\n");
                printf("\033[1;38;5;75m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m");
                printf("\n\n\n\n");
            }

        } while (gamechoice != 'h' && gamechoice != 't' && gamechoice != 'w' && gamechoice != 'r' && gamechoice != 'e');

        if (gamechoice == 'e'){

            printf("\n\n\t\t\t\t\t\033[1;38;5;203mGame exited :(\033[0m\n\n");

            break;
        }

        printf("\t\t\t       \033[1;38;5;159mPlayer 1 ... please enter your name: \033[0m");
        scanf("%s", player1_name);
        printf("\t\t\t       \033[1;38;5;42mPlayer 1's name has been saved as: \033[1;38;5;231m%s\033[0m", player1_name);
        printf("\n\n");
        printf("\t\t\t       \033[1;38;5;159mPlayer 2 ... please enter your name: \033[0m");
        scanf("%s", player2_name);
        printf("\t\t\t       \033[1;38;5;42mPlayer 2's name has been saved as: \033[1;38;5;231m%s\033[0m", player2_name);
        printf("\n");

        if (gamechoice == 'h'){

            hangman(player1_name, player2_name);

            do {

                do {
                    printf("\n\n\t\t\t\t\033[1;38;5;159mPress \033[1;38;5;231m(a)\033[1;38;5;159m to play again\n"
                        "\t\t\t\tPress \033[1;38;5;231m(m)\033[1;38;5;159m to go to the main menu\033[0m\n"
                        "\t\t\t\t\033[1;38;5;159mEnter your choice: \033[0m");
                    menuChoice = _getch();

                    if (menuChoice != 'a' && menuChoice != 'm'){
                        printf("\n\t\t\t\t\033[1;38;5;203mYou have entered an invalid choice, try again.\033[0m\n");
                    }

                } while (menuChoice != 'a' && menuChoice != 'm');

                if (menuChoice == 'a'){
                    warmerColder(player1_name, player2_name);
                }
                else {

                    printf("\n\n\t\t\t\t\033[1;38;5;231mReturning to main menu ...\033[0m\n\n");

                    continue;
                }

            } while (menuChoice == 'a');

        }

        else if (gamechoice == 't'){

            ticTacToe(player1_name, player2_name);

            do {

                do {
                    printf("\n\n\t\t\t\t\033[1;38;5;159mPress \033[1;38;5;231m(a)\033[1;38;5;159m to play again\n"
                        "\t\t\t\tPress \033[1;38;5;231m(m)\033[1;38;5;159m to go to the main menu\033[0m\n"
                        "\t\t\t\t\033[1;38;5;159mEnter your choice: \033[0m");
                    menuChoice = _getch();

                    if (menuChoice != 'a' && menuChoice != 'm'){
                        printf("\n\t\t\t\t\033[1;38;5;203mYou have entered an invalid choice, try again.\033[0m\n");
                    }

                } while (menuChoice != 'a' && menuChoice != 'm');

                if (menuChoice == 'a'){
                    warmerColder(player1_name, player2_name);
                }
                else {

                    printf("\n\n\t\t\t\t\033[1;38;5;231mReturning to main menu ...\033[0m\n\n");

                    continue;
                }

            } while (menuChoice == 'a');

        }

        else if (gamechoice == 'w'){

            warmerColder(player1_name, player2_name);

            do {

                do {
                    printf("\n\n\t\t\t\t\033[1;38;5;159mPress \033[1;38;5;231m(a)\033[1;38;5;159m to play again\n"
                        "\t\t\t\tPress \033[1;38;5;231m(m)\033[1;38;5;159m to go to the main menu\033[0m\n"
                        "\t\t\t\t\033[1;38;5;159mEnter your choice: \033[0m");
                    menuChoice = _getch();

                    if (menuChoice != 'a' && menuChoice != 'm'){
                        printf("\n\t\t\t\t\033[1;38;5;203mYou have entered an invalid choice, try again.\033[0m\n");
                    }

                } while (menuChoice != 'a' && menuChoice != 'm');

                if (menuChoice == 'a'){
                    warmerColder(player1_name, player2_name);
                }
                else {

                    printf("\n\n\t\t\t\t\033[1;38;5;231mReturning to main menu ...\033[0m\n\n");

                    continue;
                }

            } while (menuChoice == 'a');

        }

        else if (gamechoice == 'r'){

            rockPaperScissors(player1_name, player2_name);

            do {

                do {
                    printf("\n\n\t\t\t\t\033[1;38;5;159mPress \033[1;38;5;231m(a)\033[1;38;5;159m to play again\n"
                        "\t\t\t\tPress \033[1;38;5;231m(m)\033[1;38;5;159m to go to the main menu\033[0m\n"
                        "\t\t\t\t\033[1;38;5;159mEnter your choice: \033[0m");
                    menuChoice = _getch();

                    if (menuChoice != 'a' && menuChoice != 'm'){
                        printf("\n\t\t\t\t\033[1;38;5;203mYou have entered an invalid choice, try again.\033[0m\n");
                    }

                } while (menuChoice != 'a' && menuChoice != 'm');

                if (menuChoice == 'a'){
                    rockPaperScissors(player1_name, player2_name);
                }
                else {

                    printf("\n\n\t\t\t\t\033[1;38;5;231mReturning to main menu ...\033[0m\n\n");

                    continue;
                }

            } while (menuChoice == 'a');

        }

    } while (gamechoice != 'e');
}