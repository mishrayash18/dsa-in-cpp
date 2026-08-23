#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    
    int pivot = 0;
    int pivotindex = -1;
    for (int i=nums.size()-1; i-1>-1; i--) {
        if (nums[i]>nums[i-1]) {
            pivot = nums[i-1];
            pivotindex = i-1;
            break;
        }
    }

    if (pivotindex == -1) {
        sort(nums.begin(), nums.end());
        return;
    }

    int nextgreater = INT_MAX;
    int nextgreaterindex = 0;
    for (int i = pivotindex+1; i<nums.size(); i++) {
        if (nums[i] > pivot && nums[i] < nextgreater) {
            nextgreater = nums[i];
            nextgreaterindex = i;
        }
    }
    
    swap(nums[pivotindex], nums[nextgreaterindex]);

    sort(nums.begin()+pivotindex+1, nums.end());    
    
}