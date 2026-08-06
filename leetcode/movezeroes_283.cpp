#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int> nums) {
    int left=0;
    int right = 0;
    while (right<nums.size()) {

       if (nums[right]!=0) {
        swap(nums[left], nums[right]);
        left++;
        right++;
       }

       else {
        right++;
       }
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for (int val : nums) {
        cout << val << endl;
    }
}