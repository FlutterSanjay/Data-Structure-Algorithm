// STL of Min & Max Heap
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int> pq; for (Max Heap)

    priority_queue<int, vector<int>, greater<int>> pq; // for (Min Heap)
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    pq.pop();

    cout << endl
         << "Top Operation : " << endl;
    cout << pq.top();
    cout << endl;

    cout << "Max Heap is Empty : " << pq.empty();

    return 0;
}