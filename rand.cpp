#include<iostream>
#include<random>
#include<math.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 7);

    for (int i = 0; i < 10; i++)
    {
        cout << dis(gen) << endl;
    }
    return 0;
}