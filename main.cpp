#include <iostream>
#include <stdlib.h>
using namespace std;
class Game
{
private:
    int a[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}};

public:
    int gameWon()
    {
        int won = 0;
        // int check_column(int a[7][7])
        // {
        // Check column

        for (int j = 0; j < 7; j++)
        {

            for (int i = 0; i < 7; i++)
            {

                if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1)
                {
                    printf("\n Player 1 wins column \n ");
                    won = 1;
                    break;
                    // return 3;
                }

                if (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2)
                {
                    printf("\n Player 2 wins column \n ");
                    won = 1;
                    break;
                    // return 4;
                }
            }
        }
        // }
        // check diagonal
        for (int j = 0; j < 7; j++)
        {

            for (int i = 0; i < 7; i++)
            {

                if (a[i][j] == 1 && a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 1 && a[i + 3][j - 3] == 1)
                {
                    printf(" \nPlayer 1 wins diagonal ");
                    won = 1;
                    // return 9;
                    break;
                }
                if (a[i][j] == 2 && a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2)
                {
                    printf(" \nPlayer 2 wins diagonal");
                    won = 1;
                    // return 10;
                    break;
                }
            }
        }
        // check row
        for (int i = 6; i >= 0; i--)
        {
            for (int j = 0; j < 7; j++)
            {
                if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i][j + 2] == 1 && a[i][j + 3] == 1)
                {
                    printf("\n Player 1 wins row");
                    won = 1;
                    break;
                    // return 5;
                }
                if (a[i][j] == 2 && a[i][j + 1] == 2 && a[i][j + 2] == 2 && a[i][j + 3] == 2)
                {
                    printf("\n player 2 wins  row");
                    won = 1;
                    break;
                    // return 6;
                }
            }
        }
        // check diagonal 1
        for (int j = 0; j < 7; j++)
        {

            for (int i = 0; i < 7; i++)
            {

                if (a[i][j] == 1 && a[i - 1][j - 1] == 1 && a[i - 2][j - 2] == 1 && a[i - 3][j - 3] == 1)
                {
                    cout << "Player 1 wins diagonal" << endl;
                    won = 1;
                    break;
                    // return 11;
                }
                if (a[i][j] == 2 && a[i - 1][j - 1] == 2 && a[i - 2][j - 2] == 2 && a[i - 3][j - 3] == 2)
                {
                    won = 1;
                    break;
                    cout << "Player 2 wins diagonal" << endl;
                    // return 12;
                }
            }
        }
        return won;
    }
    int askPos(int player)
    {
        int pos;
        cout << " \nEnter the position to fill in " << endl;
        cin >> pos;
        system("clear");
        for (int i = 6; i >= 0; i--)
        {
            if (a[i][pos - 1] == 0)
            {
                a[i][pos - 1] = player;
                break;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {

                if (a[i][j] == 1)
                {
                    cout << 'X' << "   |   ";
                }
                else if (a[i][j] == 2)
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
    }
};
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
                cout << 'X' << " | ";
            }
            else if (display[i][j] == 2)
            {
                cout << 'O' << " | ";
            }
            else
            {
                cout << " "
                     << " | ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << "   ";
    }
    ++*check;
}
int check_column(int a[7][7])
{

    for (int j = 0; j < 7; j++)
    {

        for (int i = 0; i < 7; i++)
        {

            if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1)
            {
                printf("\n Player 1 wins column \n ");
                return 3;
            }

            if (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2)
            {
                printf("\n Player 2 wins column \n ");
                return 4;
            }
        }
    }
}

int check_diagonal(int a[7][7])
{
    for (int j = 0; j < 7; j++)
    {

        for (int i = 0; i < 7; i++)
        {

            if (a[i][j] == 1 && a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 1 && a[i + 3][j - 3] == 1)
            {
                printf(" \nPlayer 1 wins diagonal ");
                return 9;
                break;
            }
            if (a[i][j] == 2 && a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2)
            {
                printf(" \nPlayer 2 wins diagonal");
                return 10;
                break;
            }
        }
    }
}

int checkRow(int array[7][7])
{
    for (int i = 6; i >= 0; i--)
    {
        for (int j = 0; j < 7; j++)
        {
            if (array[i][j] == 1 && array[i][j + 1] == 1 && array[i][j + 2] == 1 && array[i][j + 3] == 1)
            {
                printf("\n Player 1 wins row");
                return 5;
            }
            if (array[i][j] == 2 && array[i][j + 1] == 2 && array[i][j + 2] == 2 && array[i][j + 3] == 2)
            {
                printf("\n player 2 wins  row");
                return 6;
            }
        }
    }
}

int checkDiagonal1(int array[7][7])
{

    for (int j = 0; j < 7; j++)
    {

        for (int i = 0; i < 7; i++)
        {

            if (array[i][j] == 1 && array[i - 1][j - 1] == 1 && array[i - 2][j - 2] == 1 && array[i - 3][j - 3] == 1)
            {
                cout << "Player 1 wins diagonal" << endl;
                return 11;
            }
            if (array[i][j] == 2 && array[i - 1][j - 1] == 2 && array[i - 2][j - 2] == 2 && array[i - 3][j - 3] == 2)
            {
                cout << "Player 2 wins diagonal" << endl;
                return 12;
            }
        }
    }
}
int main()
{
    int haha, lol;
    int go, diag, diag1, row;
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
        haha = player1_ask();
        display(a, haha, check);
        go = check_column(a);
        diag = check_diagonal(a);
        row = checkRow(a);
        diag1 = checkDiagonal1(a);
        if (go == 3)

        {
            break;
        }
        if (diag == 9)
        {
            break;
        }
        if (row == 5)
            break;
        if (diag1 == 11)
            break;
        lol = player2_ask();
        display(a, lol, check);
        go = check_column(a);
        diag = check_diagonal(a);
        row = checkRow(a);
        diag1 = checkDiagonal1(a);
        if (go == 4)
        {
            break;
        }
        if (diag == 10)
            break;
        if (row == 6)
            break;
        if (diag1 == 12)
            break;
    }
}