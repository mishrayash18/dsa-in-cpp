#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> s;
    unordered_set<int> s1;
    for (int i=0; i<nums1.size(); i++) {
        s.insert(nums1[i]);
    }

    for (int i=0; i<nums2.size(); i++) {
        if (s.find(nums2[i]) != s.end()) s1.insert(nums2[i]);
    }

    vector<int> result = {};

    for (int val : s1) {
        result.push_back(val);
    }

    return result;
}

int main() {
    vector<int> ans = intersection({1,2,2,1}, {2,2});
    for (int val:ans) {
        cout << val << endl;
    }
}