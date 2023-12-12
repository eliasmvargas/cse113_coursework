/**
 * @file gl.c
 * @author Elias Vargas
 * @brief function definition for the printBoardState func.
 * @details Not much here.
 * @todo Nothing here for this file.
 * @bug No bugs in this file.
 * @remark There's very little here.
 * @date 2023-12-06
 * 
 */

#include <stdio.h>


void printBoardState(char **golboard, int nrow, int ncol, char cell) {
    printf("\033[H"); // Sets cursor to homestate
    char boardtranslate[] = {' ', cell};
    char buff[2*(nrow * ncol) + nrow + 1];
    char *buffp = buff;
    int k = 0;
    for (int i = 0; i < nrow; ++i){
        for (int j = 0; j < ncol; ++j){
            *(buffp + k++) = *(boardtranslate + *(*(golboard + i) + j));
            *(buffp + k++) = ' ';
        }

        *(buffp + k++) = '\n';
    }
    *(buffp + k) = 0;
    printf("%s", buff);
}
