#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int missingNumber(vector<int> nums) {
    int n = nums.size();

    int sum = n*(n+1)/2;

    int numsum = 0;
    for (int i=0; i<nums.size(); i++) {
        numsum+=nums[i];
    }

    int result = sum-numsum;
    return result;
}

int main() {
    cout << missingNumber({0,1,3});
}