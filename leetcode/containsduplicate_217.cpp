#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

bool containsDuplicate(vector<int> nums) {
    unordered_map<int, int> mp;

    for (int i=0; i<nums.size(); i++) {
        mp[nums[i]]++;
    }

    for (auto p : mp) {
        if (p.second>1) return true;
    }

    return false;
}

int main() {
    cout << containsDuplicate({1,4,1,5,6,7});
}