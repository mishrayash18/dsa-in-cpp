#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> topKfreq(vector<int> nums, int k) {
    unordered_map<int, int> mp;
    vector<int> keys;
    vector<int> ans;

    for (int i=0; i<nums.size(); i++) {
        mp[nums[i]]++;
    }
    vector<pair<int,int>> freq(mp.begin(), mp.end());

    sort(freq.begin(), freq.end(), [](auto &a, auto&b) {
        return a.second>b.second;
    });

    for (auto p : freq) {
        keys.push_back(p.first);
    }

    for (int i=0; i<k; i++) {
        ans.push_back(keys[i]);
    }

    return ans;
}

int main() {
    vector<int> ans = topKfreq({1,2,1,1,1,2,2,3,3,3,3,3,4,4}, 3);
    for (int val : ans) {
        cout << val << endl;
    }
}