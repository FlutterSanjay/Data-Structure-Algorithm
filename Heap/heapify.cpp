// Heapify - Uska use hota hai node ko uske current position mai pahucha do
#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    int largest = index;

    if (leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    if (rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        index = largest;
        Heapify(arr, n, index);
    }
}

void HeapifyBuild(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        Heapify(arr, n, i);
    }
}

int main()
{
    int arr[6] = {-1, 12, 15, 13, 11, 14};
    int n = 5;
    HeapifyBuild(arr, n);

    cout << "Printing the Heap tree :" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return -1;
}