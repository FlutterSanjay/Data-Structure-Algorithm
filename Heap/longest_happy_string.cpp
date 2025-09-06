// Longest Happy String
// T.C - O(a+b+c) && S.C - O(1);

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> p;
string LongestHappyString(int a, int b, int c)
{

    priority_queue<p, vector<p>> pq;

    string result = "";

    if (a > 0)
    {
        pq.push({a, 'a'});
    }

    if (b > 0)
    {
        pq.push({b, 'b'});
    }

    if (c > 0)
    {
        pq.push({c, 'c'});
    }

    while (!pq.empty())
    {
        int currCount = pq.top().first;
        char currChar = pq.top().second;
        pq.pop();

        if (result.length() >= 2 && result[result.length() - 1] == currChar && result[result.length() - 2] == currChar)
        {
            // currChar not get used;

            if (pq.empty())
            {
                break;
            }

            int nextCount = pq.top().first;
            char nextChar = pq.top().second;
            pq.pop();

            result.push_back(nextChar);
            nextCount--;

            if (nextCount > 0)
            {
                pq.push({nextCount, nextChar});
            }
            // pq.push({currCount, currChar});
        }
        else
        {
            currCount--;
            result.push_back(currChar);
        }
        if (currCount > 0)
        {
            pq.push({currCount, currChar});
        }
    }
    return result;
}
int main()
{
    int a = 1;
    int b = 1;
    int c = 7;
    string result = LongestHappyString(a, b, c);
    cout << "The Longest Happy String : " << result;

    return 0;
}
