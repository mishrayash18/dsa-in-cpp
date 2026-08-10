#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int> nums) {
    vector<int> ans;
    int left = 0;
    int right = nums.size()-1;
    while (left<=right) {
        if (nums[left]*nums[left] <= nums[right]*nums[right]) {
            ans.push_back(nums[right]*nums[right]);
            right--;
        }

        else {
            ans.push_back(nums[left]*nums[left]);
            left++;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = sortedSquares({-4,-1,0,3,10});
    for (int val:nums) {
        cout << val << endl;
    }
}