#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Node
{
public:
    int arr[7][7];
    int player;
    vector<Node *> children;

    Node(int player, int arr[7][7])
    {
        this->player = player;
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                this->arr[i][j] = arr[i][j];
            }
        }
    }

    void addChild(Node *child)
    {
        children.push_back(child);
    }

    Node *getRandomChild()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, children.size() - 1);
        int randomIndex = dis(gen);
        return children[randomIndex];
    }
};
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
Game(int a[7][7]) {
    
}
    int gameWon()
    {
        int won = 0;
        for (int j = 0; j < 7; j++)
        {

            for (int i = 0; i < 7; i++)
            {

                if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1)
                {
                    won = 1;
                    break;
                    // return 3;
                }

                if (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2)
                {
                    won = 1;
                    break;
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
                    won = 1;
                    break;
                }
                if (a[i][j] == 2 && a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2)
                {
                    won = 1;
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
                    won = 1;
                    break;
                }
                if (a[i][j] == 2 && a[i][j + 1] == 2 && a[i][j + 2] == 2 && a[i][j + 3] == 2)
                {
                    won = 1;
                    break;
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
                    won = 1;
                    break;
                }
                if (a[i][j] == 2 && a[i - 1][j - 1] == 2 && a[i - 2][j - 2] == 2 && a[i - 3][j - 3] == 2)
                {
                    won = 1;
                    break;
                }
            }
        }
        return won;
    }
    int askPos(int player,int a[7][7])
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
        return (player == 1 ? 2 : 1);
    }
    void display(int a[7][7])
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

int main()
{
    Game g;
    int player = 1, won = 0;
    g.display();
    while (won == 0)
    {
        player = g.askPos(player,a);
        g.display(a);
        won = g.gameWon(a);
    }
    cout << endl;
    cout << "Player " << (player - 1) << " wins" << endl;
    return 0;
}