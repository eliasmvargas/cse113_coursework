/**
 * @file gl.h
 * @author Elias Vargas
 * @brief Function prototypes for the source code.
 * @date 2023-12-06
 * 
 */

#ifndef GOLFUNC
#define GOLFUNC

void printBoardState(char **golboard, int nrow, int ncol, char cell);
void u_temp(int rows, int cols);
void initBoard(char boardInitState);
int _countCellNeighbours(char** board, int i, int j);
void hedge(char** temp, char** board, int nRows, int nCols);
void evolveBoard(char** board, char** temp, int nRows, int nCols, int i, int j);

#endif