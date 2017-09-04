#include <iostream>
#include <string>
using namespace std;

#include "Pair.h"
using namespace libre_ds;

int main()
{
    Pair<int, float> p1;
    p1.first = 4;
    p1.second = 3425.341f;

    Pair<char, string> p2('?', "test");

    cout << "P1: " << p1.first << ", " << p1.second << endl;
    cout << "P2: " << p2.first << ", " << p2.second << endl;

    cin.get();
}
