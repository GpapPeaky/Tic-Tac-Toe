#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>

#define TIC_TAC_TOE_BOARD_SIZE 60

/* 3X3 BLOCK TO 1D ARRAY ANALOGY */
    /*
        1 -> 1
        2 -> 5
        3 -> 9
        4 -> 25
        5 -> 29
        6 -> 33
        7 -> 49
        8 -> 53
        9 -> 57
    */

bool isEmptyCell(char array[], int input) {
    switch (input) {
        case 1:
            return (array[1] == ' ');
        case 2:
            return (array[5] == ' ');
        case 3:
            return (array[9] == ' ');
        case 4:
            return (array[25] == ' ');
        case 5:
            return (array[29] == ' ');
        case 6:
            return (array[33] == ' ');
        case 7:
            return (array[49] == ' ');
        case 8:
            return (array[53] == ' ');
        case 9:
            return (array[57] == ' ');
        default:
            return false;
    }
}


int checkWinner(char array[],int N,char play){

    //LINE 1

    if(array[1] == play && array[5] == play && array[9] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    //LINE 2

    if(array[25] == play && array[29] == play && array[33] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    //LINE 3

    if(array[49] == play && array[53] == play && array[57] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    //COLUMN 1

    if(array[1] == play && array[25] == play && array[49] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    //COLUMN 2

    if(array[5] == play && array[29] == play && array[53] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    //COLUMN 3

    if(array[9] == play && array[33] == play && array[57] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    //DIAG 1

    if(array[1] == play && array[29] == play && array[57] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    //DIAG 2

    if(array[9] == play && array[29] == play && array[49] == play){
        printf("\nPlayer %c won\n",play);
        return 0;
    }

    return -1;
}

void printBoard(char array[],int N,char play){

    if(play == 'X' || play == '0'){

        printf("Player %c: ",play);

        for(int i = 0 ; i < N ; i++){
            printf("%c",array[i]);
        }
        return;
    }else{
        for(int i = 0 ; i < N ; i++){
            printf("%c",array[i]);
        }
        return;
    }
}

void game(char array[],char play,int input){

    switch(input){
        case 1:
        if(array[1] == ' '){
            array[1] = play;
            break;
        }else{
            break;
        }

        case 2:
        if(array[5] == ' '){
            array[5] = play;
            break;
        }else{
            break;
        }

        case 3:
        if(array[9] == ' '){
            array[9] = play;
            break;
        }else{
            break;
        }

        case 4:
        if(array[25] == ' '){
            array[25] = play;
            break;
        }else{
            break;
        }

        case 5:
        if(array[29] == ' '){
            array[29] = play;
            break;
        }else{
            break;
        }

        case 6:
        if(array[33] == ' '){
            array[33] = play;
            break;
        }else{
            break;
        }

        case 7:
        if(array[49] == ' '){
            array[49] = play;
            break;
        }else{
            break;
        }

        case 8:
        if(array[53] == ' '){
            array[53] = play;
            break;
        }else{
            break;
        }

        case 9:
        if(array[57] == ' '){
            array[57] = play;
            break;
        }else{
            break;
        }

        default:
            break;
    }

    return;
}

void player(char symb){

    if(symb == 'X'){
        printf("Player X: ");
        return;
    }
    else if(symb == '0'){
        printf("Player 0: ");
        return;
    }else{
        return;
    }
}

int main(void){

    int input; //CELL TO BE CHANGED//

    int turn = 1;

    //PLAYER NAMES//

    const char X = 'X';
    const char O = '0';
    const char E = 'E'; //FOR THE INITIAL PRINT

    /*
    BOARD THAT CONTAINS ALL CHARACTERS TO BE PRINTED...
    CHANGES ARE GOING TO BE HANDLED IN HERE...
    */

    char board[TIC_TAC_TOE_BOARD_SIZE]={' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','\n',
                                        '-','-','-','+','-','-','-','+','-','-','-','\n',
                                        ' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','\n',
                                        '-','-','-','+','-','-','-','+','-','-','-','\n',
                                        ' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',};

   //FIRST PRINT OF BOARD//

   printBoard(board, TIC_TAC_TOE_BOARD_SIZE,E);

    while (turn <= 9) { 

        /* PLAYER X */

        do{
            scanf("%d", &input);

            if(input < 1 || input > 9 || !isEmptyCell(board, input)){
                player(X);
                printf("\n");
                continue;
            }else{
                game(board, X, input);
                printBoard(board, TIC_TAC_TOE_BOARD_SIZE,X);
                if(checkWinner(board, TIC_TAC_TOE_BOARD_SIZE, X) == 0){
                    return 0; 
                }
                break; //EXIT LOOP
            }
        }while(1);

        turn++;

        if(turn > 9){
            printf("\nTie\n");
            return 0; 
        }

        /* PLAYER 0 */

        do{
            scanf("%d", &input);

            if(input < 1 || input > 9 || !isEmptyCell(board, input)){
                player(O);
                printf("\n");
                continue;
            }else{
                game(board, O, input);
                printBoard(board, TIC_TAC_TOE_BOARD_SIZE,O);
                if (checkWinner(board, TIC_TAC_TOE_BOARD_SIZE, O) == 0){
                    return 0; 
                }
                break; //EXIT LOOP
            }
        }while(1);

        turn++;
    }

    return 0;
}
