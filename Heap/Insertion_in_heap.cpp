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

    int deleteNode()
    {
        int ans = arr[1];
        arr[1] = arr[size];
        size--;

        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left < size && arr[left] > arr[largest])
            {
                largest = index;
            }

            if (right < size && arr[right] > arr[largest])
            {
                largest = right;
            }

            if (largest == index)
            {
                return ans;
                ;
            }
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
    }
};

int main()
{
    Heap h;
    h.arr[0] = -1;
    // h.arr[1] = 50;
    // h.arr[2] = 30;
    // h.arr[3] = 70;
    // h.arr[4] = 40;
    // h.arr[5] = 80;
    // h.arr[6] = 100;
    // h.size = 6;
    h.Insert(50);
    h.Insert(30);
    h.Insert(70);
    h.Insert(40);
    h.Insert(80);
    h.Insert(100);

    cout << "Printing the Heap : ";
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }

    cout << "Deleted  Node :" << h.deleteNode() << endl;
    cout << "Printing the Heap : ";
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    // h.Insert(110);
    // cout << endl
    //      << "Printing the Heap After Insertion : ";
    // for (int i = 0; i <= h.size; i++)
    // {
    //     cout << h.arr[i] << " ";
    // }

    return 0;
}