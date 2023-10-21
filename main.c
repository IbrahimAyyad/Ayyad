#include"headear.h"
#include"Function_Definition.h"


int main()
{
    printf("--------- Welcome to Tie-Tac-Toe game-------\n");
    do{
    //system("cls");
    int x;
    printf("please choose the mode :\n  1- single player mode\n  2- multi player mode \n ");
    scanf("%d",&x);
    if( x == 1)
    {
        system("cls||clear");
        int q,error;
        do{
       // system("cls");
        error=0;
        printf(" 1-easy Ai mode \n 2-hard Ai mode\n");
        scanf("%d",&q);
        if(q == 1)
        {
        system("cls||clear");
        printf("Please enter your name player 1: ");
        scanf("%s", name1);
        printf(" %s : X\n %s : O\n",name1,name2);
        int n;
        currentPlayer=1;
        do{
        Initialize_board();
        Print_Board();
        do
        {
            if (currentPlayer == 1)
            {
            printf("%s's turn \n enter from(1-9)\n:",name1);
            scanf("%d",&n);
            Player_Move(n);
            Print_Board();
            }
            else
            {
                printf("%s's turn \n ",name2);
                Bot_Easy_mode();
                currentPlayer--;
                Print_Board();
            }
            gameover=Check_win();
        }while(gameover == 0);
                if(gameover == 1 && currentPlayer == 2)
        {
            printf("Game over\n%s (X) won\n",name1,Num1,Num2);
            Num1++;
        }
        else if (gameover == 1 && currentPlayer == 1)
        {
            printf("Game over\n%s (O) won\n",name2,Num1,Num2);
            Num2++;
        }
        else
        {
            printf("Game over\nits  draw\n",Num1,Num2);
        }
       // Print_Board();
        do{
        if(c > 0)
        {
            system("cls||clear");
            printf("Invalid input Try again \n");
        }
       printf(" 1- play again\n 2-leave mode \n 3-get out\n:");
        scanf("%d",&m);
        c++;
          }while(m <1 || m>3);
          c=0;
        }while(m == 1);
        Num1=0;
        Num2=0;
        }
        else if(q == 2)
        {
        system("cls||clear");
        printf("Please enter your name player 1: ");
        scanf("%s", name1);
        printf(" %s : X\n %s : O\n",name1,name2);
        int n;
        currentPlayer=1;
        do{
        Initialize_board();
        Print_Board();
        do
        {
            if (currentPlayer == 1)
            {
            printf("%s's turn \n enter from(1-9)\n:",name1);
            scanf("%d",&n);
            Player_Move(n);
            Print_Board();
            }
            else
            {
                printf("%s's turn \n ",name2);
                Bot_Hard_mode();
                currentPlayer--;
                Print_Board();
            }
            gameover=Check_win();
        }while(gameover == 0);
                if(gameover == 1 && currentPlayer == 2)
        {
            printf("Game over\n%s (X) won\n",name1,Num1,Num2);
            Num1++;
        }
        else if (gameover == 1 && currentPlayer == 1)
        {
            printf("Game over\n%s (O) won\n",name2,Num1,Num2);
            Num2++;
        }
        else
        {
            printf("Game over\nits  draw\n",Num1,Num2);
        }
        move=1;
        do{
        //system("cls");
        if(c > 0)
        {
            system("cls||clear");
            printf("Invalid input Try again .\n");
        }
        printf("choose\n 1- play again\n 2-leave mode \n 3-get out\n:");
        scanf("%d",&m);
        c++;
          }while(m <1 || m>3);
          c=0;
        }while(m == 1);
        Num1=0;
        Num2=0;
        }
        else
        {
            printf("Invalid input try again .\n");
            error++;
        }
    }while(error != 0);
}

    else if(x == 2)
    {
        system("cls||clear");
        printf("Please enter your name player 1: ");
        scanf("%s", name1);
        printf("Please enter your name player 2: ");
        scanf("%s", name2);
        printf(" %s : X\n %s : O\n",name1,name2);
        int n;
        currentPlayer=1;
        do
        {
        Initialize_board();
        Print_Board();
        do
        {
            if (currentPlayer == 1)
            {
                 printf("%s's turn \n enter from(1-9)\n:",name1);
            }
            else
            {
                printf("%s's turn \n enter from(1-9)\n:",name2);
            }
            scanf("%d",&n);
            Player_Move(n);
            Print_Board();
            gameover=Check_win();
        }while(gameover == 0);
        if(gameover == 1 && currentPlayer == 2)
        {
            printf("Game over\n%s (X) won\n",name1,Num1,Num2);
            Num1++;
            //currentPlayer=2;
        }
        else if (gameover == 1 && currentPlayer == 1)
        {
            printf("Game over\n%s (O) won\n",name2,Num1,Num2);
            Num2++;
           // currentPlayer=;
        }
        else
        {
            printf("Game over\nits  draw\n",Num1,Num2);
            if(currentPlayer == 1)
            {
                currentPlayer++;
            }
            else
            {
                currentPlayer--;
            }

        }
       // Print_Board();
        do{
        if(c > 0)
        {
            system("cls||clear");
            printf("Invalid input Try again \n");
        }
        printf(" 1- play again\n 2-leave mode \n 3-get out \n:");
        scanf(" %d",&m);
        c++;
          }while(m <1 || m>3);
          c=0;
        }while(m == 1);
        if(m == 3)
        {
            return 0;
        }
        Num1=0;
        Num2=0;

    }
    else
    {
        printf("Invalid input try again .\n");
    }
    }while(m != 3);
    return 0;

}

