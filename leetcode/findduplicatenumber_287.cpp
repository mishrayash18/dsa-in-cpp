#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int findDuplicate(vector<int> nums) {
    unordered_map<int, int> mp;

    for (int i=0; i<nums.size(); i++) {
        mp[nums[i]]++;
    }

    for (auto p : mp) {
        if (p.second>1) return p.first;
    }
    return -1;
}


int main() {
    cout << findDuplicate({1,3,4,2,2});
}