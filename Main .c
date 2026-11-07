# include <stdio.h>
# include <string.h>
# include <conio.h>

int pointsArr[2][50] = {0};

void warmerColder(char player1_name[], char player2_name[]){}



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
    printf("\t\t\t\tWelcome to the rock paper scissors game!\n");
    printf("\t\t\t\tEnter how many games you want to play: ");
    numGames = _getch() - '0';

    do {

        printf("\n\n\t\t\t\tGame %d:\n\n", gamesCount + 1);

        do {
            printf("\t\t\t\t%s's turn: \n", player1_name);
            printf("\t\t\t\tChoose rock (r), paper (p), or scissors (s): ");
            player1_move = _getch();
            if (player1_move != 'r' && player1_move != 'p' && player1_move != 's'){
                printf("\n\t\t\t\tYour entry was invalid, please try again, %s\n\n", player1_name);
            }
            else {
                printf("\n\t\t\t\t%s's move has been noted!\n\n", player1_name);
            }
        } while (player1_move != 'r' && player1_move != 'p' && player1_move != 's');

        do {
            printf("\t\t\t\t%s's turn: \n", player2_name);
            printf("\t\t\t\tChoose rock (r), paper (p), or scissors (s): ");
            player2_move = _getch();
            if (player2_move != 'r' && player2_move != 'p' && player2_move != 's'){
                printf("\n\t\t\t\tYour entry was invalid, please try again, %s\n\n", player2_name);
            }
            else {
                printf("\n\t\t\t\t%s's move has been noted!\n", player2_name);
            }
        } while (player2_move != 'r' && player2_move != 'p' && player2_move != 's');

        winner = rockPaperScissorsWinChecker(player1_move, player2_move);

        if (winner == 0){
            printf("\n\t\t\t\tBoth %s and %s chose (%c)\n", player1_name, player2_name, player1_move);
            printf("\t\t\t\tThis makes it a tie! Try again!");
        }
        else if (winner == 1){
            printf("\n\t\t\t\t%s chose (%c) while %s chose (%c)\n", player1_name, player1_move, player2_name, player2_move);
            printf("\t\t\t\t%s won this round!", player1_name);
            gamesCount += 1;
            player1_rock_paper_scissors_points += 1;
        }
        else {
            printf("\n\t\t\t\t%s chose (%c) while %s chose (%c)\n", player1_name, player1_move, player2_name, player2_move);
            printf("\t\t\t\t%s won this round!", player2_name);
            gamesCount += 1;
            player2_rock_paper_scissors_points += 1;
        }
    
    } while (gamesCount < numGames);

    printf("\n\n\n\t\t\t\t\t   Final Score: \n"
           "\t\t\t\t\t   %s ==> %d wins\n"
           "\t\t\t\t\t   %s ==> %d wins\n",
           player1_name, player1_rock_paper_scissors_points, player2_name, player2_rock_paper_scissors_points);
        
    if (player1_rock_paper_scissors_points == player2_rock_paper_scissors_points){
        printf("\n\n\t\t\t\tBoth players get 1 point as the final scores are tied");
    }
    else if (player1_rock_paper_scissors_points > player2_rock_paper_scissors_points){
        char temp_name[20]; 
        strcpy(temp_name, player1_name);
        printf("\n\n\t\t\t\t%s WINS ROCK PAPER SCISSORS AND EARNS 3 POINTS!\n", strupr(temp_name));
        //add points to array
    }
    else {
        char temp_name[20]; 
        strcpy(temp_name, player2_name);
        printf("\n\n\t\t\t\t%s WINS ROCK PAPER SCISSORS AND EARNS 3 POINTS!\n", strupr(temp_name));
        //add points to array
    }
}



int main(){

    char gamechoice = 'z';

    do {
        char gamechoice, menuChoice;
        char player1_name[20], player2_name[20];

        // Keep the terminal window at 106x32 for best viewing experience
        do {    
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Welcome to Ammar's Gaming Arcade! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n");
            printf("\t\t\t\t What game would you like to play?\n"
                "\n"
                "\t\t\t\t           Hangman (h)\n"
                "\t\t\t\t         Tic-Tac-Toe (t)\n"
                "\t\t\t\t        Warmer Colder (w)\n"
                "\t\t\t\t     Rock-Paper-Scissors (r)\n"
                "\t\t\t\t      To exit the game (e)\n\n");
            printf("\t\t\t\t  Enter your game of choice: ");
            scanf(" %c", &gamechoice);
            printf("\n");

            if (gamechoice != 'h' && gamechoice != 't' && gamechoice != 'w' && gamechoice != 'r' && gamechoice != 'e'){
                printf("\t\t\t You have entered an invalid choice, please try again! ");
                printf("\n\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\n\n");
            }

        } while (gamechoice != 'h' && gamechoice != 't' && gamechoice != 'w' && gamechoice != 'r' && gamechoice != 'e');

        if (gamechoice == 'e'){

            printf("\n\n\t\t\t\t\tGame exited :(\n\n");

            break;
        }

        printf("\t\t\t      Player 1 ... please enter your name: ");
        scanf("%s", player1_name);
        printf("\t\t\t      Player 1's name has been saved as: %s", player1_name);
        printf("\n\n");
        printf("\t\t\t      Player 2 ... please enter your name: ");
        scanf("%s", player2_name);
        printf("\t\t\t      Player 2's name has been saved as: %s", player2_name);
        printf("\n");

        if (gamechoice == 'h'){
            hangman(player1_name, player2_name);
        }
        else if (gamechoice == 't'){
            ticTacToe(player1_name, player2_name);
        }
        else if (gamechoice == 'w'){
            warmerColder(player1_name, player2_name);
        }
        else if (gamechoice == 'r'){
            rockPaperScissors(player1_name, player2_name);
        }

        do {

            do {
                printf("\n\n\t\t\t\tPress (a) to play again\n"
                    "\t\t\t\tPress (m) to go to the main menu\n"
                    "\t\t\t\tEnter your choice: ");
                menuChoice = _getch();

            } while (menuChoice != 'a' && menuChoice != 'm');

            if (menuChoice == 'a'){
                rockPaperScissors(player1_name, player2_name);
            }
            else {

                printf("\n\n\t\t\t\tReturning to main menu ...\n\n");

                continue;
            }

        } while (menuChoice == 'a');

    } while (gamechoice != 'e');
}