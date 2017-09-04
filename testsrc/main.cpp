#include <iostream>
using namespace std;

#include "Pair.h"
#include "FixedLengthQueue.h"
#include "Queue.h"
using namespace libre_ds;

#include <cstdlib>
#include <ctime>

int main()
{
    srand((unsigned int)time(NULL));

    Queue<int> q;
    for (int i = 0; i < 1000; i++)
    {
        bool shouldPush = rand() % 2 == 1;

        if (shouldPush || q.isEmpty())
        {
            q.push(i);
        }
        else
        {
            q.pop();
        }
    }

    cout << "Q: ";
    while (!q.isEmpty()) cout << q.pop() << ",";

    cin.get();
}
