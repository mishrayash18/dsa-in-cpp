#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxConsOnes(vector<int> nums) {
    int count = 0;
    int maxcount = INT_MIN;

    for (int i=0; i<nums.size(); i++) {
        if (nums[i]!=1) count = 0;
        
        else {
           count++;
           if (count>maxcount) maxcount = count; 
        }
        
    }
    return maxcount;
}

int main() {
    cout << maxConsOnes({1,1,0,1,1,1});
}