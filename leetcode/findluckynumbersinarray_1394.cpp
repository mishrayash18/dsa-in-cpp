#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLucky(vector<int> nums) {
    unordered_map<int, int> mp;
    int largestlucky = -1;

    for (int num : nums) {
        mp[num]++;
    }

    for (auto p : mp) {
        if (p.first == p.second && p.first>largestlucky) {
            largestlucky = p.first;
        }
    }
    return largestlucky;
}

int main() {
    cout << findLucky({2,2,3,4,5,6});
}