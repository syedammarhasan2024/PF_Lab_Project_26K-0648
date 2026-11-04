# include <stdio.h>
int main(){

    char gamechoice;
    char player1_name[20], player2_name[20];
    int points;

    // Keep the terminal window at 106x32 for best viewing experience
    do {    
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Welcome to Ammar's Gaming Arcade! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("\t\t\t\t What game would you like to play?\n"
            "\n"
            "\t\t\t\t           Hangman (h)\n"
            "\t\t\t\t         Tic-Tac-Toe (t)\n"
            "\t\t\t\t        Warmer Colder (w)\n"
            "\t\t\t\t      Rock-Paper-Scissors (r)\n\n");
        printf("\t\t\t\t   Enter your game of choice: ");
        scanf(" %c", &gamechoice);
        printf("\n");

        if (gamechoice != 'h' && gamechoice != 't' && gamechoice != 'w' && gamechoice != 'r'){
            printf("\t\t\t You have entered an invalid choice, please try again! ");
            printf("\n\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n\n\n\n");
        }

    } while (gamechoice != 'h' && gamechoice != 't' && gamechoice != 'w' && gamechoice != 'r');

    printf("\t\t\t\tPlayer 1 ... please enter your name: ");
    scanf("%s", &player1_name);
    printf("\t\t\t\tPlayer 1's name has been saved as: %s", player1_name);
    printf("\n\n");
    printf("\t\t\t\tPlayer 2 ... please enter your name: ");
    scanf("%s", &player2_name);
    printf("\t\t\t\tPlayer 2's name has been saved as: %s", player2_name);
    printf("\n");

    // if (gamechoice == 'h'){
    //     points = hangman(player1_name, player2_name);
    // }
    // else if (gamechoice == 't'){
    //     points = ticTacToe(player1_name, player2_name);
    // }
    // else if (gamechoice == 'w'){
    //     points = warmerColder(player1_name, player2_name);
    // }
    // else if (gamechoice == 'r'){
    //     points = rockPaperScissors(player1_name, player2_name);
    // }

}