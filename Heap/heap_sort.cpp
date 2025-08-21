// Heap Sort
#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex <= n && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largest])
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

void heapSort(int arr[], int n)
{

    while (n != 1)
    {
        swap(arr[1], arr[n--]);
        Heapify(arr, n, 1);
    }
}

int main()
{
    int arr[] = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    HeapifyBuild(arr, n);
    heapSort(arr, n);
    cout << "Printing the Heap Tree : " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}