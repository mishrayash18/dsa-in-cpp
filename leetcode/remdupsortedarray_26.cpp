#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeduplicates(vector<int> nums) {
    if (nums.size() == 0) return 0;
    
    int k = 0;

    for (int i=1; i<nums.size(); i++) {
        if (nums[i] != nums[k]) {
            k++;
            nums[k] = nums[i];
        }
    }

    return k+1;
    
}

int main() {
    vector<int> nums = {0,1,1,1,2,2,3,3};
    int ans = removeduplicates(nums);
    cout << ans;
    return 0;
}