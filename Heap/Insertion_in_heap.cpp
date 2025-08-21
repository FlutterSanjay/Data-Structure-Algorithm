// Insertion in MaxHeap
#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[101];
    int size;
    Heap()
    {
        this->size = 0;
    }

    void Insert(int value)
    {

        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
            }
            index = parentIndex;
        }
    }
};

int main()
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "Printing the Heap : ";
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }

    h.Insert(110);
    cout << endl
         << "Printing the Heap After Insertion : ";
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }

    return 0;
}