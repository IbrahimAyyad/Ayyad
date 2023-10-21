#include<stdio.h>
#define size 9
char board[9];
char name1[50];
char name2[50]={'B','o','t'};
int m=0; //counter
int c=0; //counter
int count=0; //counter
int Num1=0,Num2=0; //counters for game if they play again
int currentPlayer; //to choose player who will play
static int gameover; //to detect win or lose or draw
int move=1; // counter
void Initialize_board(void);
void Print_Board(void);
int Check_win();
void Player_Move(int n);
void Bot_Easy_mode(void);
int Win_Game(void);
int Block_Win(void);
void Bot_Hard_mode(void);
void Initialize_board(void) {
    for (char i = 0; i < size; i++) {
        board[i] = '1' + i;
    }
}
void Print_Board(void)
{
    system("cls||clear");
    printf("----------------------------\n");
    printf("----TIC-TAC-TOE GAME----\n");
    printf("---- %s [X] : %s [O] ----\n",name1,name2);
    printf("------  %d  : %d  -------\n",Num1,Num2);
    printf("----------------------------\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("----------------------------\n");
    if(count == 1)
    {
         printf("Invalid move, try again\n");
         count--;
    }
}
int Check_win(void)
{
    for(int j=0;j<size;j++)
    {
        if ( (board[0] == board[1] && board[1] == board[2] ) ||
             ( board[3] == board[4] && board[4] == board[5] ) ||
             ( board[6] == board[7] && board[7] == board[8] ))
        {
            return 1; //row win
        }
        else if( (board[0] == board[3] && board[3] == board[6] ) || ( (board[1] == board[4] && board[4] == board[7] ) ) || ( (board[2] == board[5] && board[5] == board[8] ) ) )
        {
            return 1; //column win
        }
        else if( (board[0] == board[4] && board[4] == board[8] ) || ( board[2] == board[4] && board[4] == board[6] ) )
        {
            return 1; //diagonal win
        }
        else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
                   board[3] != '4' && board[4] != '5' && board[5] != '6' &&
                   board[6] != '7' && board[7] != '8' && board[8] != '9')
                   {
            return 2; // Draw
                   }
        else
        {
            return 0 ;//game not finish
        }
    }
}
void Player_Move(int n)
{
    if (n < 0 || n > 9 || board[n-1] == 'X' || board[n-1] == 'O')
        {

        count=1;

        }
    else
        {
        if (currentPlayer == 1)
            {
            board[n-1] = 'X';
            currentPlayer = 2;
            }
        else
            {
            board[n-1] = 'O';
            currentPlayer = 1;
            }
       }
}
void Bot_Easy_mode(void)
{
    for (int i = 0; i < size; i++)
        {
        if (board[i] != 'X' && board[i] != 'O')
        {
            board[i] = 'O'; //fill any available square
            break;
        }
        }
}
int Win_Game(void)
 {
    for (int i = 0; i < size; i++)
        {
        if (board[i] != 'X' && board[i] != 'O')
        {
            // assume putting 'O' to see if it wins
            char original = board[i];
            board[i] = 'O';

            if (Check_win() == 1)
                {
                // It's a winning move dont change the last move
                return 1;
                }

            // Reset the square to its original
            board[i] = original;
        }
        }
    return 0;  // No winning moves found
}

int Block_Win(void) {
    for (int i = 0; i < size; i++)
        {
        if (board[i] != 'X' && board[i] != 'O')
            {
            // assume putting 'O' to see to see if it blocks the opponent
            char original = board[i];
            board[i] = 'X';

            if (Check_win() == 1)
                {
                // It's a blocking move, don't change it
                board[i] = 'O';
                return 1;
                }

            // Reset the square to its original
            board[i] = original;
           }
        }
    return 0;
}


void Bot_Hard_mode(void) {
    if (move == 1) {
        // If board[4] not equal "X"put 'O'  in it else put 'O' in corner
        if (board[4] != 'X') {
            board[4] = 'O';
            move++;
        }
        else
        {
            if (board[0] != 'X') {
                board[0] = 'O';
            } else if (board[2] != 'X') {
                board[2] = 'O';
            } else if (board[6] != 'X') {
                board[6] = 'O';
            } else {
                board[8] = 'O';
            }
            move++;
        }
    } else if (move == 2) {
        if (Block_Win()) {
            // If there's a blocking move, make it
            move++;
        } else {
            // if not play in the corner
            if (board[0] != 'X') {
                board[0] = 'O';
            } else if (board[2] != 'X') {
                board[2] = 'O';
            } else if (board[6] != 'X') {
                board[6] = 'O';
            } else {
                board[8] = 'O';
            }
            move++;
        }
    } else {
        if (Win_Game()) {
        } else if (Block_Win()) {
        } else {
            Bot_Easy_mode();
        }

    }
}
