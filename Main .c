# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>
# include <ctype.h>

int pointsArr[2][50] = {0};
 
void warmerColder(char player1_name[], char player2_name[]){
 
    int actualNum, guessedNum, guesses, prevGuess, numRounds = 0, roundOverFlag = 0, player1_guesses, player2_guesses;
    int player1_winFlag = 0, player2_winFlag = 0;
    int invalidNumberInput, clearInput;
    char choice1, tempPlayer1_Name[20], tempPlayer2_Name[20], nameSwapVar[20];
 
    do {
        printf("\n\n\n");
        printf("\t\t\t\t\033[1;38;5;231mWelcome to the warmer-colder game!\033[0m\n");
        printf("\n\t\t\t\t\033[1;38;5;159mFor instructions, press \033[1;38;5;231m(i)\033[1;38;5;159m\n"
            "\t\t\t\tTo start playing, press \033[1;38;5;231m(p)\033[1;38;5;159m\n"
            "\t\t\t\tEnter your choice: \033[0m");
        choice1 = _getch();
 
        if (choice1 != 'i' && choice1 != 'I' && choice1 != 'p' && choice1 != 'P'){
            printf("\n\t\t\t\t\033[1;38;5;203mInvalid choice, try again!\033[0m\n");
        }
 
    } while (choice1 != 'i' && choice1 != 'I' && choice1 != 'p' && choice1 != 'P');
 
    if (choice1 == 'i' || choice1 == 'I'){
        printf("\n\n\t\t\t\t\t    \033[1;38;5;220mHow to play:\033[0m\n"
               "\t\033[1;38;5;159m1.  There are 2 rounds.\n"
               "\t2.  Round 1: \033[1;38;5;231m%s\033[1;38;5;159m picks a 1-100 number, \033[1;38;5;231m%s\033[1;38;5;159m guesses.\n"
               "\t3.  If \033[1;38;5;231m%s\033[1;38;5;159m guesses within 10 tries, \033[1;38;5;231m%s\033[1;38;5;159m wins the round.\n"
               "\t4a. After 1st guess: computer says \033[1;38;5;196m\"warm\"\033[1;38;5;159m or \033[1;38;5;33m\"cold\"\033[1;38;5;159m.\n"
               "\t4b. \033[1;38;5;196m\"Warm\"\033[1;38;5;159m = \033[1;38;5;231m%s\033[1;38;5;159m's guess is within 10 of \033[1;38;5;231m%s\033[1;38;5;159m's number.\n"
               "\t4c. \033[1;38;5;33m\"Cold\"\033[1;38;5;159m = \033[1;38;5;231m%s\033[1;38;5;159m's guess is >10 away from \033[1;38;5;231m%s\033[1;38;5;159m's number.\n"
               "\t5a. Next guesses: computer says \033[1;38;5;196m\"getting warmer\"\033[1;38;5;159m or \033[1;38;5;33m\"getting colder\"\033[1;38;5;159m.\n"
               "\t5b. \033[1;38;5;196m\"Getting warmer\"\033[1;38;5;159m = \033[1;38;5;231m%s\033[1;38;5;159m's guess is closer to \033[1;38;5;231m%s\033[1;38;5;159m's number than \033[1;38;5;231m%s\033[1;38;5;159m's previous.\n"
               "\t5c. \033[1;38;5;33m\"Getting colder\"\033[1;38;5;159m = \033[1;38;5;231m%s\033[1;38;5;159m's guess is further from \033[1;38;5;231m%s\033[1;38;5;159m's number than \033[1;38;5;231m%s\033[1;38;5;159m's previous.\n"
               "\t6.  Roles reverse in round 2.\n"
               "\t7.  One succeeds, one fails = successful player wins 3 pts.\n"
               "\t8.  Both succeed in different number of turns = fewer turns wins 1 pts.\n"
               "\t9.  Both succeed in equal turns = 1 pt each.\n"
               "\t10. Both fail = 0 pts.\033[0m\n",
               player1_name, player2_name, player2_name, player2_name, player2_name, player1_name, player2_name, player1_name,
               player2_name, player1_name, player2_name, player2_name, player1_name, player2_name);
 
        printf("\n\t\t\t\t\033[1;38;5;159mTo start the game press any key: \033[0m");
        _getch();
 
    }
 
    strcpy(tempPlayer1_Name, player1_name);
    strcpy(tempPlayer2_Name, player2_name);
 
    // I will use AI over here to get a possible double digit, or triple digit input from player 1 without showing it to the screen
    // This is because _getch() is only for single digit numbers or characters. I need a solution for this.
 
    do {
        numRounds += 1;
        guesses = 0;
 
        if (roundOverFlag == 0){
            printf("\n\n\n\t\t\t\t\033[1;38;5;220mRound 1 begins:\033[0m\n");
        }
        else {
            printf("\n\n\t\t\t\t\033[1;38;5;220mRound 2 begins:\033[0m\n");
        }
 
        // AI start
        do {
            printf("\n\n\t\t\t\t\033[1;38;5;231m%s\033[1;38;5;159m, please enter a number from 1 to 100: \033[0m", tempPlayer1_Name);
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
                printf("\n\t\t\t\t\033[1;38;5;203mInvalid number, please try again!\033[0m\n");
            }
            else {
                printf("\n\t\t\t\t\033[1;38;5;42mThe number has been noted!\033[0m\n\n");
            }
 
        } while (invalidNumberInput == 1 || actualNum > 100 || actualNum < 1);
 
        do {
 
            printf("\t\t\t\t\033[1;38;5;231mCompleted guesses: (%d/10)\033[0m\n", guesses);
            printf("\t\t\t\t\033[1;38;5;231m%s\033[1;38;5;159m, guess a number from 1 to 100: \033[0m", tempPlayer2_Name);
 
            // Used AI to check for letters instead of numbers
 
            if (scanf("%d", &guessedNum) != 1){
                while ((clearInput = getchar()) != '\n' && clearInput != EOF){}
                guessedNum = 0;
                printf("\n\t\t\t\t\033[1;38;5;203mInvalid input, please enter a number!\033[0m\n\n");
            }
            else if (guessedNum > 100 || guessedNum < 1){
                printf("\n\t\t\t\t\033[1;38;5;203mInvalid guess, please try again!\033[0m\n\n");
            }
 
        } while (guessedNum > 100 || guessedNum < 1);
        guesses += 1;
 
        if(guessedNum == actualNum){
            printf("\n\n\t\t\t\t\033[1;38;5;198mWow! You got it first try! The number was %d\033[0m\n", actualNum);
            printf("\t\t\t\t\033[1;38;5;198mThats crazy! It took you %d turn!\033[0m\n", guesses);
 
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
            printf("\t\t\t\t\033[1;38;5;196mWarm!\033[0m\n\n");
        }
        else{
            printf("\t\t\t\t\033[1;38;5;33mCold!\033[0m\n\n");
        }
 
        if (guessedNum != actualNum){
 
            prevGuess = guessedNum;
 
            do {
 
                do {
 
                    if (guesses == 9){
                        printf("\t\t\t\t\033[1;38;5;220mIts your last turn! You need to get it right!\033[0m\n\n");
                    }
 
                    printf("\t\t\t\t\033[1;38;5;231mCompleted guesses: (%d/10)\033[0m\n", guesses);
                    printf("\t\t\t\t\033[1;38;5;231m%s\033[1;38;5;159m, guess a number from 1 to 100: \033[0m", tempPlayer2_Name);
 
                    // Again used AI to check if letters input instead of numbers
                    if (scanf("%d", &guessedNum) != 1){
                        while ((clearInput = getchar()) != '\n' && clearInput != EOF){}
                        guessedNum = 0;
                        printf("\n\t\t\t\t\033[1;38;5;203mInvalid input, please enter a number!\033[0m\n\n");
                    }
                    else if (guessedNum > 100 || guessedNum < 1){
                        printf("\n\t\t\t\t\033[1;38;5;203mInvalid guess, please try again!\033[0m\n\n");
                    }
 
                } while (guessedNum > 100 || guessedNum < 1);
                guesses += 1;
 
                if (guessedNum == actualNum){
                    printf("\n\t\t\t\t\033[1;38;5;198mYou got it! The number was %d!\033[0m\n", actualNum);
                    printf("\t\t\t\t\033[1;38;5;198mIt took you %d turns!\033[0m\n", guesses);
 
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
                    printf("\t\t\t\t\033[1;38;5;196mGetting warmer!\033[0m\n\n");
                }
                else{
                    printf("\t\t\t\t\033[1;38;5;33mGetting colder!\033[0m\n\n");
                }
 
                prevGuess = guessedNum;
 
            } while (guesses < 10 && guessedNum != actualNum);
 
            if (guesses >= 10 && guessedNum != actualNum){
                printf("\t\t\t\t\033[1;38;5;203mYou ran out of turns!\033[0m\n");
                printf("\t\t\t\t\033[1;38;5;203mThe number was: %d\033[0m\n", actualNum);
            }
 
        }
 
        roundOverFlag = 1;
 
        strcpy(nameSwapVar, tempPlayer1_Name);
        strcpy(tempPlayer1_Name, tempPlayer2_Name);
        strcpy(tempPlayer2_Name, nameSwapVar);
 
    } while (numRounds != 2);
 
    if (player1_winFlag == 0 && player2_winFlag == 0){
 
        printf("\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220mBoth players were unable to guess the numbers\033[0m\n");
        printf("\n\t\t\t\t\033[1;38;5;203mBoth players get 0 points :(\033[0m\n");
    }
    else if (player1_winFlag == 1 && player2_winFlag == 0){
 
        printf("\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the number in %d turns!\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s was unable to guess the number\033[0m\n", player1_name, player1_guesses, player2_name);
        printf("\n\t\t\t\t\033[1;38;5;220m%s wins Warmer-Colder and gets 3 points!\033[0m\n", player1_name);
    }
    else if (player1_winFlag == 0 && player2_winFlag == 1){
 
        printf("\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the number in %d turns!\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s was unable to guess the number\033[0m\n", player2_name, player2_guesses, player1_name);
        printf("\n\t\t\t\t\033[1;38;5;220m%s wins Warmer-Colder and gets 3 points!\033[0m\n", player2_name);
    }
    else {
 
        printf("\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the number in %d turns!\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the number in %d turns!\033[0m\n",
               player1_name, player1_guesses, player2_name, player2_guesses);
 
        if (player1_guesses == player2_guesses){
            printf("\n\t\t\t\t\033[1;38;5;220mBoth players took the same amount of turns\033[0m\n"
                "\t\t\t\t\033[1;38;5;220mBoth players get 1 point each!\033[0m");
        }
        else if (player1_guesses < player2_guesses){
            printf("\n\t\t\t\t\033[1;38;5;220m%s took fewer turns!\033[0m"
                   "\n\t\t\t\t\033[1;38;5;220m%s wins Warmer-Colder and gets 1 point\033[0m\n",
                   player1_name, player1_name);
        }
        else if (player1_guesses > player2_guesses){
            printf("\n\t\t\t\t\033[1;38;5;220m%s took fewer turns!\033[0m"
                   "\n\t\t\t\t\033[1;38;5;220m%s wins Warmer-Colder and gets 1 point\033[0m\n",
                   player2_name, player2_name);
        }      
    }
 
}
 
void ticTacToe(char player1_name[], char player2_name[]){}
 
 

void hangmanGallows(int wrongGuesses){
    
    switch (wrongGuesses)
    {
    case 1:
        printf(
        "     ╔═══════════════╗\n"
        "     ║               ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "═════╩═════\n");
        break;
    case 2:
        printf(
        "     ╔═══════════════╗\n"
        "     ║               ║\n"
        "     ║               │\n"
        "     ║              ╭─╮\n"
        "     ║              ╰─╯\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "═════╩═════\n");
        break;
    case 3:
        printf(
        "     ╔═══════════════╗\n"
        "     ║               ║\n"
        "     ║               │\n"
        "     ║              ╭─╮\n"
        "     ║              ╰─╯\n"
        "     ║               ┼\n"
        "     ║               │\n"
        "     ║               ┼\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "═════╩═════\n");
        break;
    case 4:
        printf(
        "     ╔═══════════════╗\n"
        "     ║               ║\n"
        "     ║               │\n"
        "     ║              ╭─╮\n"
        "     ║              ╰─╯\n"
        "     ║             ╭─┼\n"
        "     ║             │ │\n"
        "     ║             ╵ ┼\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "═════╩═════\n");
        break;
    case 5:
        printf(
        "     ╔═══════════════╗\n"
        "     ║               ║\n"
        "     ║               │\n"
        "     ║              ╭─╮\n"
        "     ║              ╰─╯\n"
        "     ║             ╭─┼─╮\n"
        "     ║             │ │ │ \n"
        "     ║             ╵ ┼ ╵\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "     ║\n"
        "═════╩═════\n");
        break;
    case 6:
        printf(
        "     ╔═══════════════╗\n"
        "     ║               ║\n"
        "     ║               │\n"
        "     ║              ╭─╮\n"
        "     ║              ╰─╯\n"
        "     ║             ╭─┼─╮\n"
        "     ║             │ │ │ \n"
        "     ║             ╵ ┼ ╵\n"
        "     ║              ╱\n"
        "     ║             ╱\n"
        "     ║\n"
        "     ║\n"
        "═════╩═════\n");
        break;
    case 7:
        printf(
        "     ╔═══════════════╗\n"
        "     ║               ║\n"
        "     ║               │\n"
        "     ║              ╭─╮\n"
        "     ║              ╰─╯\n"
        "     ║             ╭─┼─╮\n"
        "     ║             │ │ │ \n"
        "     ║             ╵ ┼ ╵\n"
        "     ║              ╱ ╲\n"
        "     ║             ╱   ╲\n"
        "     ║\n"
        "     ║\n"
        "═════╩═════\n");
        break;
    default:
        break;
    }
}


void hangman(char player1_name[], char player2_name[]){

    SetConsoleOutputCP(CP_UTF8);

    int numRounds = 0, roundOverFlag = 0;
    char tempPlayer1_Name[20], tempPlayer2_Name[20], nameSwapVar[20];
    int player1_livesLost = 0, player2_livesLost = 0;
    int player1_winFlag = 0, player2_winFlag = 0;

    printf("\n\n\n");
    printf("\t\t\t\t\033[1;38;5;231mWelcome to the hangman game!\033[0m\n");

    strcpy(tempPlayer1_Name, player1_name);
    strcpy(tempPlayer2_Name, player2_name);

    do {
        numRounds += 1;
        char actualWord[20], hiddenWord[40] = {0};
        int numberFlag = 0, livesLost = 0, foundIndex, turnNum = 1, guesses = 0;
        char guessedLetter;
        int guessed[26] = {0};

        if (roundOverFlag == 0){
            printf("\n\n\n\t\t\t\t\033[1;38;5;220mRound 1 begins:\033[0m\n");
        }
        else {
            printf("\n\n\t\t\t\t\033[1;38;5;220mRound 2 begins:\033[0m\n");
        }

        do {
            numberFlag = 0;

            // add round number printf over here

            // AI Starts here to make sure input is in small letters and no other symbol or number
            printf("\n\n%s, please enter the word you want %s to guess: ", tempPlayer1_Name, tempPlayer2_Name);
            int index = 0;
            char ch;
            
            while (1) {
                ch = _getch();
                if (ch == '\r' || ch == '\n') {
                    for (int i = 0; i < index; i++) {
                        printf("\b \b");
                    }
                    break;
                } else if (ch == '\b') {
                    if (index > 0) {
                        index--;
                        printf("\b \b");
                    }
                } else {
                    actualWord[index] = ch;
                    index++;
                    printf("%c", ch);
                }
            }
            actualWord[index] = '\0';

            if (actualWord[0] == '\0') {
                numberFlag = 1;
                printf("\nYou must enter at least one letter! Try again!\n");
            }
            else {
                for (int i = 0; i < strlen(actualWord); i++){
                    if (actualWord[i] >= 'a' && actualWord[i] <= 'z'){
                        continue;
                    }
                    else {
                        numberFlag = 1;
                        printf("\nYou have entered an invalid word! Try again!\n");
                        break;
                    }
                }
            }
            if (numberFlag != 1) {
                printf("\nThe word has been noted!\n");
            }
        } while (numberFlag == 1);

        // AI ends here

        for (int i = 0 ; i < strlen(actualWord) ; i++) {
            strcat(hiddenWord, "_");
        }

        do {
            printf("\n\n%s, the word you have to guess is: %s (%d)", tempPlayer2_Name, hiddenWord, (int)strlen(hiddenWord));
            printf("\nTurn number: %d , Used lives: (%d/7)\n", turnNum, livesLost);
            printf("Guess a letter: ");
            scanf(" %c", &guessedLetter);

            guessedLetter = tolower((unsigned char)guessedLetter);

            if (guessedLetter < 'a' || guessedLetter > 'z') {
                printf("\nInvalid input! Please enter a letter!\n");
                continue;
            }

            int letterIndex = guessedLetter - 'a';

            if (letterIndex >= 0 && letterIndex < 26 && guessed[letterIndex] == 1) {
                printf("\nYou already tried '%c'!\n", guessedLetter);
                continue;
            }

            if (letterIndex >= 0 && letterIndex < 26) {
                guessed[letterIndex] = 1;
            }

            turnNum += 1;
            char *pos = strchr(actualWord, guessedLetter);

            if (pos != NULL) {
                printf("Nice guess! The letter '%c' was present!", guessedLetter);
                while (pos != NULL) {
                    foundIndex = pos - actualWord;
                    hiddenWord[foundIndex] = guessedLetter;
                    pos = strchr(pos + 1, guessedLetter);
                }
            }
            else {
                livesLost += 1;
                printf("Whoops! The letter '%c' wasnt present!\n\n", guessedLetter);
                hangmanGallows(livesLost);
            }

    
        } while (livesLost < 7 && strcmp(actualWord, hiddenWord) != 0);



        if (strcmp(actualWord, hiddenWord) == 0) {

            printf("\n\nYou got it! The word was \"%s\"", actualWord);
            printf("\nIt took you %d turns, and you lost %d lives in the process\n", turnNum-1, livesLost);

            if (roundOverFlag == 0){
                player2_livesLost = livesLost;
                player2_winFlag = 1;
            }
            else {
                player1_livesLost = livesLost;
                player1_winFlag = 1;
            }
        }
        else {
            printf("\n\nYou ran out of lives! The word was \"%s\"", actualWord);
            printf("\nIt took you %d turns, but you lost all 7 of your lives\n", turnNum-1);
        }

        roundOverFlag = 1;

        strcpy(nameSwapVar, tempPlayer1_Name);
        strcpy(tempPlayer1_Name, tempPlayer2_Name);
        strcpy(tempPlayer2_Name, nameSwapVar);

    } while (numRounds != 2);

    if (player1_winFlag == 0 && player2_winFlag == 0){

        printf("\n\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220mBoth players were unable to guess the words\033[0m\n");
        printf("\n\t\t\t\t\033[1;38;5;203mBoth players get 0 points :(\033[0m\n");
    }
    else if (player1_winFlag == 1 && player2_winFlag == 0){

        printf("\n\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the word with %d lives lost!\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s was unable to guess the word\033[0m\n", player1_name, player1_livesLost, player2_name);
        printf("\n\t\t\t\t\033[1;38;5;220m%s wins Hangman and gets 3 points!\033[0m\n", player1_name);
    }
    else if (player1_winFlag == 0 && player2_winFlag == 1){

        printf("\n\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the word with %d lives lost!\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s was unable to guess the word\033[0m\n", player2_name, player2_livesLost, player1_name);
        printf("\n\t\t\t\t\033[1;38;5;220m%s wins Hangman and gets 3 points!\033[0m\n", player2_name);
    }
    else {

        printf("\n\n\t\t\t\t\t    \033[1;38;5;220mGame Report:\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the word with %d lives lost!\033[0m\n"
               "\t\t\t\t\033[1;38;5;220m%s guessed the word with %d lives lost!\033[0m\n",
               player1_name, player1_livesLost, player2_name, player2_livesLost);

        if (player1_livesLost == player2_livesLost){
            printf("\n\t\t\t\t\033[1;38;5;220mBoth players lost the same amount of lives\033[0m\n"
                "\t\t\t\t\033[1;38;5;220mBoth players get 1 point each!\033[0m");
        }
        else if (player1_livesLost < player2_livesLost){
            printf("\n\t\t\t\t\033[1;38;5;220m%s lost fewer lives!\033[0m"
                   "\n\t\t\t\t\033[1;38;5;220m%s wins Hangman and gets 1 point\033[0m\n",
                   player1_name, player1_name);
        }
        else if (player1_livesLost > player2_livesLost){
            printf("\n\t\t\t\t\033[1;38;5;220m%s lost fewer lives!\033[0m"
                   "\n\t\t\t\t\033[1;38;5;220m%s wins Hangman and gets 1 point\033[0m\n",
                   player2_name, player2_name);
        }      
    }
}

 
 
 
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
                    hangman(player1_name, player2_name);
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
                    ticTacToe(player1_name, player2_name);
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