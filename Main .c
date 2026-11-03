# include <stdio.h>
int main(){

    char gamechoice;
    char player1_name[20];

    // Keep the terminal window at 106x32 for best viewing experience
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Welcome to Ammar's Gaming Arcade! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("\t\t\t\t What game would you like to play?\n"
           "\n"
           "\t\t\t\t           Hangman (h)\n"
           "\t\t\t\t         Tic-Tac-Toe (t)\n"
           "\t\t\t\t        Warmer Colder (w)\n"
           "\t\t\t\t      Rock-Paper-Scissors (r)\n\n");
    printf("\t\t\t\t   Enter your game of choice: ");
    scanf(" %c", &gamechoice);
    printf("\n\n ");

    printf("\t\t\t\tPlayer 1 ... please enter your name: ");
    scanf("%s", &player1_name);
    printf("\n");
    printf("\t\t\t\tPlayer 1's name has been saved as: %s", player1_name);

    if (gamechoice == 'h'){
        
    }
}