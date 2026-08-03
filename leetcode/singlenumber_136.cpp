#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> nums) {
    int ans = 0;
    for (int i=0; i<nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}

int main() {
    cout << singleNumber({4,1,4,2,2});
}