#include <iostream>

#include "pqueue.h"

using namespace std;

int main() {
    pqueue<string, int> q;

    q.enqueue("rhodes  ", 1);
    q.enqueue("college ", 2);
    q.enqueue("computer", 4);
    q.enqueue("science ", 3);
    q.enqueue("is      ", 3);
    q.enqueue("awesome ", 2);

    while (!q.empty())
    {
        string s = q.dequeue();
        cout << "dequeued: " << s << endl;
    }

    return 0;
}
