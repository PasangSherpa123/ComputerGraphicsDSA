#include <iostream>
using namespace std;
int player_ask()
{
    int pos;
    cout << "Enter the position to fill in " << endl;
    cin >> pos;
    return pos;
}
void display(int display[7][7], int haha)
{

    for (int i = 6; i >= 0; i--)
    {
        if (display[i][haha - 1] == 0)
        {
            display[i][haha - 1] = 1;
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

    int haha = player_ask();

    display(a, haha);

    return 0;
}