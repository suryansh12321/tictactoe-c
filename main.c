#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void printBoard() {
    printf("\033[H\033[J"); 
    printf("\n=== Tic-Tac-Toe ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}


int checkWin() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return -1;             }
        }
    }
    return 0; 
}

int main() {
    int player = 1; 
    int choice;
    int row, col;
    char mark;
    int status = -1; 

    // 
    while (status == -1) {
        printBoard();
        
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
            
            
            status = checkWin();
            
            player++; 
        } 
        else {
            printf("Invalid move! That spot is taken or out of bounds.\n");
            printf("Press Enter to try again...");
            getchar();
            getchar();
        }
    }

    
    printBoard();
    if (status == 1) {
       
        printf("==> Player %d wins! <==\n\n", --player);
    } else {
        printf("==> Game Draw! <==\n\n");
    }

    return 0;
}