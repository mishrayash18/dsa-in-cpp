#include <iostream>
#include <vector>
using namespace std;

void getAllSubsets(vector<int> nums, vector<int> res, int i, vector<vector<int>> allsubsets) {
    if (i==nums.size()) {
        allsubsets.push_back({res});
        return;
    }

    res.push_back(nums[i]);
    getAllSubsets(nums, res, i+1, allsubsets);

    res.pop_back();

    getAllSubsets(nums, res, i+1, allsubsets);
    }

    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> allsubsets;
        vector<int> res;

        getAllSubsets(nums, res, 0, allsubsets);
        return allsubsets;
    }
