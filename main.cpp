#include <iostream>
using namespace std;
int player1_ask()
int player1_ask()
{
    int pos;
    cout << " \nEnter the position to fill in " << endl;
    cin >> pos;
    return pos;
}

int player2_ask()
{

    int pos;
    cout << " \nEnter the position to fill in " << endl;
    cin >> pos;
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

void play_game()
{
}

int main()
{
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
        int lol = player2_ask();
        display(a, lol, check);
    }

    return 0;
}
