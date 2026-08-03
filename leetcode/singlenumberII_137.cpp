#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumberII(vector<int> nums) {
    unordered_map<int, int> mp;
    for (int num : nums) {
        mp[num]++;
    }
    for (auto p : mp) {
        if (p.second == 1) return p.first;
    }
}

int main() {
    cout << singleNumberII({0,1,0,1,0,1,99});
}