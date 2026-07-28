// binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector <int> nums, int target, int start, int end) {

    if (start>end){
        return -1;
    }
    
    int mid = (start+end)/2;

    if (nums[mid] == target) {
        return mid;
    }

    if (target>nums[mid]) {
        return binarySearch(nums, target, mid+1, end);
    }


    return binarySearch(nums, target, start, mid-1);
         
}

int main() {
    vector <int> nums = {9,4,3,11,7,15};
    sort(nums.begin(), nums.end());
    cout << binarySearch(nums, 11, 0, nums.size());
}