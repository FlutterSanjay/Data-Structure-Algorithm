// 539. Minimum Time Difference
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

#include<bits/stdc++.h>
using namespace std;

int minMinuteDiff(vector<string>timePoint){
    // convert into integer Format
    int n = timePoint.size();
    vector<int> minutes;

// convert into minute and store
    for (int i = 0; i < n;i++){
        string curr = timePoint[i];

        // subStr
        int hour = stoi(curr.substr(0, 2));
        int mint = stoi(curr.substr(3, 2));
        int totalMinute = hour * 60 + mint;
        minutes.push_back(totalMinute);
    }

    sort(minutes.begin(), minutes.end());
    int mini = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);
    }

    // when 00:00 then this case use
    int lastDiff = minutes[0] + 1440 - minutes[n - 1];
    mini = min(lastDiff, mini);
    return mini;
}

int main(){

    vector<string> timePoint = {"23:59", "00:00"};

    int minDiff = minMinuteDiff(timePoint);
    cout << minDiff << endl;
    return 0;
}