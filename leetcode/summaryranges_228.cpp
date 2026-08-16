#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int> nums) {
    vector<string> ans;
    vector<int> ranges;
    int i =0;
    
    while (i<nums.size()) {
        int j = i;
        
        while (j+1 < nums.size() && nums[j+1] == nums[j]+1) {
            j++;
        }
        ranges.push_back(nums[i]);
        ranges.push_back(nums[j]);

        i=j+1;
    }
    
    for (int i=0; i<ranges.size(); i+=2) {
        if (ranges[i] == ranges[i+1]) {
            int num = ranges[i];
            string s = to_string(num);
            ans.push_back(s);
        }

        else {
            int start = ranges[i];
            int end = ranges[i+1];
            string s = to_string(start) + "->" + to_string(end);
            ans.push_back(s);
        }
    }
    return ans;
}

int main() {
    vector<string> result = summaryRanges({0,1,2,4,5,7});
    for (string val : result) {
        cout << val << endl;
    } 
}