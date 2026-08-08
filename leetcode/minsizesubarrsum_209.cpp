#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minSizeSubarrSum(vector<int> nums, int target) {
    int currlen = INT_MAX;
    int left = 0;
    int right = 0;
    int n = nums.size();
    int currsum = 0;

    while (right<n) {
        currsum+=nums[right];
        right++;

        while (currsum>=target) {
            currlen = min(currlen, (right-left));
            currsum -= nums[left];
            left++;
        }
    }

    if (currlen == INT_MAX) return 0;
    else return currlen;
}

int main() {
    cout << minSizeSubarrSum({2,3,1,2,4,3}, 7);
}