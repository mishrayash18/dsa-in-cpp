#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mingroups(vector<vector<int>> intervals) {
    vector<int> starts = {};
    vector<int> ends = {};

    for (int i=0; i<intervals.size(); i++) {
        starts.push_back(intervals[i][0]);
        ends.push_back(intervals[i][1]);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int i=0;
    int j=0;
    int count = 0;
    int maxcount = INT16_MIN;

    while (i<starts.size()) {
        if (starts[i]<=ends[j]) {
            i++;
            count++;
        }

        else {
            j++;
            count--;
        }

        maxcount = max(count, maxcount);
        
    }

    return maxcount;
} 

int main() {
    vector<vector<int>> intervals = {{1,5}, {2,6}, {5,8}};
    int groups = mingroups(intervals);
    cout << groups;
}