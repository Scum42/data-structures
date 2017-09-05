#include <iostream>
using namespace std;

#include "Pair.h"
#include "FixedLengthQueue.h"
#include "Queue.h"
#include "LinkedList.h"
using namespace libre_ds;

#include <cstdlib>
#include <ctime>

int main()
{
    srand((unsigned int)time(NULL));

    LinkedList<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.add(i);
    }

    cout << "Iterator test on linked list (should be 0 to 9):\n";
    for (LinkedList<int>::iterator iter = list.begin(); iter != list.end(); iter++)
    {
        cout << (*iter) << ",";
    }

    cin.get();
}
