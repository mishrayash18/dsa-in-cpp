#include <iostream>
#include <vector>
using namespace std;

int remelement(vector<int> nums, int val) {
    int k = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]!=val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {2,3,2,3};
    int ans = remelement(nums, 3);
    cout << ans;
    return 0;
}