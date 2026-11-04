# include <stdio.h>
# include <conio.h>

int pointsArr[2][50] = {0};

void warmerColder(char player1_name[], char player2_name[]){}



void ticTacToe(char player1_name[], char player2_name[]){}



void hangman(char player1_name[], char player2_name[]){}



void rockPaperScissors(char player1_name[], char player2_name[]){

    int numGames;
    char player1_move, player2_move;

    printf("\n\n\n\n\n");
    printf("Welcome to the rock paper scissors game!\n");
    printf("Enter how many games you want to play: ");
    scanf("%d", &numGames);
    for (int i = 0; i < numGames; i++){
        printf("\n\nGame %d:\n\n", i + 1);

        do {
            printf("Player 1's turn: \n");
            printf("Choose rock (r), paper (p), or scissors (s): ");
            player1_move = _getch();
            if (player1_move != 'r' && player1_move != 'p' && player1_move != 's'){
                printf("\nYours entry was invalid, please try again, player 1\n\n");
            }
            else {
                printf("\nPlayer 1's move has been noted!\n");
            }
        } while (player1_move != 'r' && player1_move != 'p' && player1_move != 's');
    }
}



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

}