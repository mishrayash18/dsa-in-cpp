#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> missingElement(vector<int> nums) {
    sort(nums.begin(), nums.end());

    vector<int> ans;

    for (int i = 0; i < nums.size() - 1; i++) {

        if (nums[i + 1] - nums[i] > 1) {

            for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
                ans.push_back(j);
            }

        }
    }

    return ans;
}

int main() {

    vector<int> nums = {5, 1, 7};

    vector<int> ans = missingElement(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}