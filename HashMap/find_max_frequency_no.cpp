// find the max frequency no using HashMaps
#include <bits/stdc++.h>
using namespace std;

int MaxFrequency(vector<int> &arr)
{
    // creating Unordered_map
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 2};
    int result = MaxFrequency(arr);
    cout << " Maximum Frequency Number : " << result;
    return 0;
}