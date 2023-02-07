#include <iostream>
#include <stdlib.h>
using namespace std;
int player1_ask()
{
    int pos;
    cout << " \nEnter the position to fill in " << endl;
    cin >> pos;
    system("clear");
    return pos;
}

int player2_ask()
{

    int pos;
    cout << " \nEnter the position to fill in " << endl;
    cin >> pos;
    system("clear");
    return pos;
}
int checkRow(int array[7][7])
{
    for (int i = 6; i >= 0; i--)
    {
        for (int j = 0; j < 7; j++)
        {
            if (array[i][j] == 1 && array[i][j + 1] == 1 && array[i][j + 2] == 1 && array[i][j + 3] == 1)
            {
                cout << "Player 1 wins" << endl;
                return 5;
            }
            if (array[i][j] == 2 && array[i][j + 1] == 2 && array[i][j + 2] == 2 && array[i][j + 3] == 2)
            {
                cout << "Player 2 wins" << endl;
                return 6;
            }
        }
    }
}

int checkDiagonal1(int array[7][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (array[i][j] == 1 && array[i + 1][j + 1] == 1 && array[i + 2][j + 2] == 1 && array[i + 3][j + 3] == 1)
            {
                cout << "Player 1 wins" << endl;
                return 11;
            }
            if (array[i][j] == 2 && array[i + 1][j + 1] == 2 && array[i + 2][j + 2] == 2 && array[i + 3][j + 3] == 2)
            {
                cout << "Player 2 wins" << endl;
                return 12;
            }
        }
    }
}
void display(int display[7][7], int haha, int *check)
{

    for (int i = 6; i >= 0; i--)
    {
        if (display[i][haha - 1] == 0 && *check % 2 != 0)
        {
            display[i][haha - 1] = 1;
            break;
        }

        else if (display[i][haha - 1] == 0 && *check % 2 == 0)
        {

            display[i][haha - 1] = 2;
            break;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {

            if (display[i][j] == 1)
            {
                cout << 'X' << "   |   ";
            }
            else if (display[i][j] == 2)
            {
                cout << 'O' << "   |   ";
            }
            else
            {
                cout << " "
                     << "   |   ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << "       ";
    }
    ++*check;
}

int check_column(int a[7][7]) {

for (int j = 0;j<7;j++) {

    for (int i =0 ;i<7;i++) {


     if (a[i][j] == 1 &&  a[i+1][j] == 1 && a[i+2][j] == 1 && a[i+3][j]==1) {
         printf("\n Player 1 wins \n ");
            return 3;

     }

     if (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2)
     {
            printf("\n Player 2 wins \n ");
            return 4;
     }
    }
}

}

int check_diagonal (int a[7][7]) {
for (int j= 0;j<7;j++) {

    for (int i=0;i<7;i++) {

if (a[i][j] ==1 && a[i+1][j-1]==1 && a[i+2][j-2] == 1 && a[i+3][j-3]==1) {
    printf(" \nPlayer 1 wins ");
    return 9;
    break;
}
if (a[i][j] == 2 && a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2)
{
    printf(" \nPlayer 2 wins ");
    return 10;
    break;
}
    }
}

}

int main()
{
    int go,diag,diag1,row;
    int a[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}};

    int count = 1;
    int *check = &count;
    int player1 = 0, player2 = 0;
    while (player1 == 0 && player2 == 0)
    {
        int haha = player1_ask();
        display(a, haha, check);
        go = check_column(a);
        diag = check_diagonal(a);
        diag1 = checkDiagonal1(a);
        row = checkRow(a);

        if (go == 3 || diag == 9 ||  diag1 = 11 || row == 5)
        {
     break;
        }
        int lol = player2_ask();
        display(a, lol, check);
        go = check_column(a);
        if (go==4 || diag == 10|| diag1 == 12 || row == 6) {
            break;
        }
     
     
    }

    return 0;
}
