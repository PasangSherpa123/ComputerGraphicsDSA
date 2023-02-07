#include <iostream>
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

int check_column(int a[7][7])
{

    for (int j = 0; j < 7; j++)
    {

        for (int i = 0; i < 7; i++)
        {

            if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1)
            {
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

int check_diagonal(int a[7][7])
{
    for (int j = 0; j < 7; j++)
    {

        for (int i = 0; i < 7; i++)
        {

            if (a[i][j] == 1 && a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 1 && a[i + 3][j - 3] == 1)
            {
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
    int go, diag;
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
    while (player1 == 0 || player2 == 0)
    {
        int haha = player1_ask();
        display(a, haha, check);
        go = check_column(a);
        diag = check_diagonal(a);

        if (go == 3 || go == 4 || diag == 9 || diag == 10)
        {
            break;
        }
        int lol = player2_ask();
        display(a, lol, check);
        go = check_column(a);
        if (go == 3 || go == 4 || diag == 9 || diag == 10)
        {
            break;
        }
    }

    return 0;
}
