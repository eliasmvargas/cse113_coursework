/**
* @file rock-spock.c
* @author Elias Vargas
* @date 9/19/23
* @brief Play Rock-paper-scissors-lizard-Spock against the machine
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define COMPUTER 8088 // case COMPUTER in print_winner() function
#define PLAYER 1000 // case PLAYER in print_winner() function
#define DRAW 3
#define CHOICES 5 // the number of cases minus 'Q' for quit
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'
#define LIZARD 'L'
#define SPOCK 'V'
int win; // stores win 
int id; // used for identifying the print statement based on moves

void move(int who, int move);
int winner(int computer, int player);
void print_winner(int winner);
int nrand(int range);
void seed();


int main(void)
{
    int computer;
    int player;
    int tmp;
    seed();
    player = '\n'; // initializes player int
    while (player != ('Q' | 'q')){ //While loop to keep the game playing
        player = '\n';
        printf("Enter a move:\n");
        printf("R for ROCK\n");
        printf("P for PAPER\n");
        printf("S for SCISSORS\n");
        printf("L for LIZARD\n");
        printf("V for SPOCK\n");
        printf("Q to have SPOCK eat a ROCK while chasing a LIZARD and quit\n");
        printf("Move: ");

        while ((tmp = getchar()) != '\n'){
            tmp = toupper(tmp); //forces player input to be capital
            if(tmp != 'R' && tmp != 'P' && tmp != 'S' && tmp != 'L' && tmp != 'V' && tmp != 'Q'){
                printf("Please input a valid selection: \n");
                getchar();
            } else {
                if (tmp == 'Q' | tmp == 'q'){
                    exit(1);
                }
                player = tmp;
            }
            
        }

        
       // printf("DEBUG %c", player);
        move(PLAYER, player);
        switch(nrand(CHOICES)) {
            case 0:
                computer = ROCK;
                break;
            case 1:
                computer = PAPER;
                break;
            case 2:
                computer = SCISSORS;
                break;
            case 3:
                computer = LIZARD;
                break;
            case 4:
                computer = SPOCK;
                break;
        }

       // printf("DEBUG %c", computer);
        move(COMPUTER, computer);
        winner(computer, player);
        print_winner(win);
       // printf("To quit, enter 'Q', otherwise enter another character: \n");
       // player = getchar();
      }
    return 0;
}
/** prints the player's or computer's move to stdin
* used in debugging
* @param who is it the computer or the player's move?
* @param move what move did they make
* @return void
*/
void move(int who, int move)
{
    if (who == COMPUTER)
        printf("Computer's play is ");
    else
        printf("Player's play is ");

    switch(move) {
        case ROCK:
            printf("ROCK\n");
            break;
        case PAPER:
            printf("PAPER\n");
            break;
        case SCISSORS:
            printf("SCISSORS\n");
            break;
        case SPOCK:
            printf("SPOCK\n");
            break;
        case LIZARD:
            printf("LIZARD\n");
            break;
    }
}
/**
* determines the winner either COMPUTER or PLAYER
* @param computer the computer's move
* @param player the player's move
* @return the winner of the game
*/
int winner(int computer, int player)
{
    switch (player){
        case 'P':
            switch(computer){
                case 'S':
                    win = COMPUTER;
                    id = 1;
                    break;
                case 'R':
                    win = PLAYER;
                    id = 2;
                    break;
                case 'V':
                    win = PLAYER;
                    id = 3;
                    break;
                case 'L':
                    win = COMPUTER;
                    id = 4;
                    break;
                case 'P':
                    win = DRAW;
                    id = 0;
                    break;
            }
            break;
        case 'R':
            switch(computer){
                case 'P':
                    win = COMPUTER;
                    id = 2;
                    break;
                case 'S':
                    win = PLAYER;
                    id = 5;
                    break;
                case 'L':
                    win = PLAYER;
                    id = 6;
                    break;
                case 'V':
                    win = COMPUTER;
                    id = 7;
                    break;
                case 'R':
                    win = DRAW;
                    id = 0;
                    break;
                }
            break;
        case 'S':
            switch(computer){
                case 'S':
                    win = DRAW;
                    id = 0;
                    break;
                case 'R':
                    win = COMPUTER;
                    id = 5;
                    break;
                case 'V':
                    win = COMPUTER;
                    id = 8;
                    break;
                case 'L':
                    win = PLAYER;
                    id = 9;
                    break;
                case 'P':
                    win = PLAYER;
                    id = 1;
                    break;
            }
            break;
        case 'L':
            switch(computer){
                case 'S':
                    win = COMPUTER;
                    id = 9;
                    break;
                case 'R':
                    win = COMPUTER;
                    id = 6;
                    break;
                case 'V':
                    win = PLAYER;
                    id = 10;
                    break;
                case 'L':
                    win = DRAW;
                    id = 0;
                    break;
                case 'P':
                    win = PLAYER;
                    id = 3;
                    break;
            }
            break;
        case 'V':
            switch(computer){
                case 'S':
                    win = PLAYER;
                    id = 8;
                    break;
                case 'R':
                    win = PLAYER;
                    id = 7;
                    break;
                case 'V':
                    win = DRAW;
                    id = 0;
                    break;
                case 'L':
                    win = COMPUTER;
                    id = 10;
                    break;
                case 'P':
                    win = COMPUTER;
                    id = 4;
                    break;
            }
        break;
    //printf("DEBUG %d", win);
    }

return win;
}
/**
* prints the winner of the game to stdin
* @param id Uses the unique situation id to print the correct win statement
* @param win Int that stores whether the computer won, the player won, or if it's a draw.
* @return void
*/
void print_winner(int winner)
{
    switch(id){
            case 1:
                printf("Scissors cut paper \n");
                break;
            case 2:
                printf("Paper covers rock \n");
                break;
            case 3:
                printf("Lizard eats paper \n");
                break;
            case 4:
                printf("Paper disproves spock \n");
                break;
            case 5:
                printf("Rock crushes scissors \n");
                break;
            case 6:
                printf("Rock crushes lizard \n");
                break;
            case 7:
                printf("Spock vaporizes rock \n");
                break;
            case 8:
                printf("Spock smashes scissors \n");
                break;
            case 9:
                printf("Scissors decapitate lizard \n");
                break;
            case 10:
                printf("Lizard poisons spock \n");
                break;
    }
    switch(win){
            case COMPUTER:
                printf("The winner is: Computer! \n");
                break;  

            case PLAYER:
                printf("The winner is: Player! \n");
                break;

            case DRAW:
                printf("It's a draw. \n");
                break;
        }

}
int nrand(int range)
{
return rand() % range;
}
void seed() {
    srand((unsigned int)time(NULL));
}
