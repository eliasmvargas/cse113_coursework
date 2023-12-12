/**
 * @file life.c
 * @author Elias Vargas
 * @brief A model simulation of Conway's game of life written in C. The game accepts command-line arguments of different types.
 * @details The basis of this program is the data type char** which is a 2d array. Every logic piece in this program is designed to work with this specific array type.
 * @todo Finish implementing .lif file import. Currently it imports correctly and reads just fine, but the logic of implementing it is still very poor. Also freeing the malloced memory.
 * @bug Nothing prevents the code from running currently. Stronger data validation should be implemented in the future, however. BIG HOWEVER- There is a very bad memory leak problem.
 * @remark I've tried a multitude of different ways and implementing for loops for clearing the malloc memory, and none of the ways was able to work without breaking the code entirely. As for now the program runs somewhat okay, though inefficient.
 * @date 2023-12-06
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "gl.h"

char boardInitState = 'r';
int i, j;
int counter;
int nRows = 40; //array rows
int nCols = 40; //array columns
int xcor; // x coordinate from -o arg
int ycor; // y coordinate from -o arg
char **board; //current board
char **temp; //temporary/prev board
int evolutions = 100; //# of cycles
int timeBetweenEvolutions = 20000; // time in microseconds
int randomSeed = 100;
char cellAscii = 'x';
char *edgeType;
FILE * import_lf;
int x,y;

/**
 * @brief Initializes and updates the temporary board for evolutions
 * 
 * @param rows 
 * @param cols 
 */
void u_temp(int rows, int cols){
    temp = malloc(nRows * sizeof(char *));
    for (i = 0; i < nRows; i++)
    {
        temp[i] = malloc(nCols * sizeof(char));
        for (j = 0; j < nCols; j++)
        {
            temp[i][j] = 0;
        }
    }
}

/**
 * @brief Initializes the current board array
 * 
 * @param boardInitState 
 */
void initBoard(char boardInitState){
    // board with random cells initiated
    if (boardInitState == 'r')
    {
        srand(randomSeed);
        int x;
        board = malloc(nRows * sizeof(char *));
        for (i = 0; i < nRows; i++)
        {
            board[i] = malloc(nCols * sizeof(char));
            for (j = 0; j < nCols; j++)
            {
                x = rand() % 2;
                if (x == 1)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
    }
    // board with just glider gun initiated
    else if (boardInitState == 'g')
    {
        board = malloc(nRows * sizeof(char *));
        for (i = 0; i < nRows; i++)
        {
            board[i] = malloc(nCols * sizeof(char));
            for (j = 0; j < nCols; j++)
            {
                board[i][j] = 0;
            }
        }

        board[1][25] = 1;
        board[2][23] = 1;
        board[2][25] = 1;
        board[3][13] = 1;
        board[3][14] = 1;
        board[3][21] = 1;
        board[3][22] = 1;
        board[3][35] = 1;
        board[3][36] = 1;
        board[4][12] = 1;
        board[4][16] = 1;
        board[4][21] = 1;
        board[4][22] = 1;
        board[4][35] = 1;
        board[4][36] = 1;
        board[5][1] = 1;
        board[5][2] = 1;
        board[5][11] = 1;
        board[5][17] = 1;
        board[5][21] = 1;
        board[5][22] = 1;
        board[6][1] = 1;
        board[6][2] = 1;
        board[6][11] = 1;
        board[6][15] = 1;
        board[6][17] = 1;
        board[6][18] = 1;
        board[6][23] = 1;
        board[6][25] = 1;
        board[7][11] = 1;
        board[7][17] = 1;
        board[7][25] = 1;
        board[8][12] = 1;
        board[8][16] = 1;
        board[9][13] = 1;
        board[9][14] = 1;
    }
}

/**
 * @brief Counts cell neighbors
 * 
 * @param board current board
 * @param i row
 * @param j col
 * @return count
 */
int _countCellNeighbours(char** board, int i, int j){
    // I know this is not technically linux kernel coding style but I'd argue it is very readable considering all of the if statements have the same output.
    int counter = 0;
    if(i - 1 > 0){
        if (board[i - 1][j] == 1) counter++;
        if ((j - 1 > 0) && (board[i - 1][j - 1] == 1)) counter++;
        if ((j + 1 < nCols) && (board[i - 1][j + 1] == 1)) counter++;
    }
    if (i + 1 < nRows){
        if (board[i + 1][j] == 1) counter++;
        if ((j - 1 > 0) && (board[i + 1][j - 1] == 1)) counter++;
        if ((j + 1 < nCols) && (board[i + 1][j + 1] == 1)) counter++;
    }
    if ((j + 1 < nCols) && (board[i][j + 1] == 1)) counter++;
    if ((j - 1 > 0) && (board[i][j - 1] == 1)) counter++;
    return counter;
}

/**
 * @brief Implements the hedge edge type
 * 
 * @param nRows 
 * @param nCols 
 */
void hedge(char** temp, char** board, int nRows, int nCols){
    int k, t;
    int h_Rows = nRows + 2;
    int h_Cols = nCols + 2;

    temp = malloc(h_Rows * sizeof(char *));
    for (k = 0; k < h_Rows; k++){
        temp[k] = malloc(h_Cols * sizeof(char));
    }

    for (k = 0; k < nRows; k++){
        for(t = 0; t < nCols; t++){
            temp[k + 1][t + 1] = board[k][t];
        }
    }
}

/**
 * @brief Evolves the temp board and then copies the temp to current board
 * 
 * @param board current board 
 * @param temp 
 * @param nRows 
 * @param nCols 
 * @param i 
 * @param j 
 */
void evolveBoard(char** board, char** temp, int nRows, int nCols, int i, int j)
{
    for (i = 0; i < nRows; i++){
        for (j = 0; j < nCols; j++){
            hedge(temp, board, nRows, nCols);
            // evolve_cell function
            int nb = _countCellNeighbours(board, i,j);
            if (board[i][j] == 1) {
                if ((nb < 2) || (nb > 3)){
                    temp[i][j] = 0;
                }
                else if (nb == 2 || nb == 3){
                    temp[i][j] = 1;
                }
            }
            else if (nb == 3){
                temp[i][j] = 1;
            }

        }
    }
    // update board function
    size_t n = ((sizeof(char) * nRows) * nCols);
    memcpy(board, temp, n); 
    
    // update board functions
}


int main(int argc, char *argv[])
{
    char** arg_pcount;
    int e;
    int opt;
    printf("\033c");     // clears the terminal
    printf("\033[?25l"); // makes cursor invisible

    // prints out the chosen command arguments
    arg_pcount = argv + 1;
    printf("Initialized arguments: \n");
    while (*arg_pcount != NULL){
        if(**arg_pcount == '-'){
            printf(" \n");
        }
        printf("%s", *arg_pcount);
        arg_pcount++;
    }

    while ((opt = getopt(argc, argv, "a:c:e:f:gh:s:w:o:H")) != -1)
    {
        switch (opt)
        {
        case ':': // data validation
            printf("option needs a value\n");
            break;
        case '?':  // data validation
            printf("unknown option: %c\n", optopt);
            break;
        case 'a': //ascii character 
            cellAscii = optarg[0];
            break;
        case 'c': //number of cycles
            evolutions = atoi(optarg);
            break;
        case 'e': //edge types
            edgeType = optarg;
            break;
        case 'f': //filename of a life file
            import_lf = fopen(optarg, "r");
            break;
        case 'g': //glider gun start seed
            boardInitState = 'g';
            break;
        case 'h': //height
            nRows = atoi(optarg);
            break;
        case 's': //random seed value
            randomSeed = atoi(optarg);
            break;
        case 'w': //width
            nCols = atoi(optarg);
            break;        
        case 'o': //initial x,y from file
            fscanf(import_lf, "%d,%d", &x, &y);
            break;
        case 'H': //print out a usage info
            printf("\n Command line arguments: \n -a <character> Chooses live cell character \n -c <number> chooses number of cycles to perform \n -e <edge type> chooses edge type. Available types: hedge \n -f <filename> chooses life file to import, acceptable version: 1.06 \n -g Uses glider gun seed \n -h <number> chooses grid height \n -s <number> chooses seed value for random function \n -w <number> chooses grid width \n -o <number,number> chooses x,y coordinates for origin according to file using. \n Do not use spaces between x and y, use commas \n -H prints help list for arguments");
            printf("\033[?25h"); // makes cursor visible
            //memory freeing

            exit(0);
            break;
        }
    }
    if((opt = getopt(argc, argv, "a:c:e:f:gh:s:w:o:H") == -1)){
        printf("\n \n ... ... ... \n Use -H for list of args.\n");
        usleep(1000000);
        printf("\033c");     // clears the terminal
        printf("\n \n ... ... ... \n Program will now start \n");
        usleep(2000000);
    }
   
    initBoard(boardInitState);
    for (e = 0; e < evolutions; e++)
    {
        usleep(timeBetweenEvolutions);
        u_temp(nRows, nCols);
        evolveBoard(board, temp, nRows, nCols, i, j);
        printBoardState(board, nRows, nCols, cellAscii);
    }
    printf("\033[?25h"); // makes cursor visible
    /*
    for (int k = 0; k < nRows; k++){
        free(board[k]);
        free(temp[k]);
    } 
    */
    free(board);
    free(temp);


    return 0;
}