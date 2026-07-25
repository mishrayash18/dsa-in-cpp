#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector <int> nextgreaterelement(vector<int> nums1, vector<int> nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    vector <int> ans(nums1.size());

    for (int i=nums2.size()-1; i>=0; i--) {

        while (!s.empty() && s.top()<=nums2[i]) s.pop();

        if (s.empty()) m[nums2[i]]=-1;

        else if (s.top()>nums2[i]) m[nums2[i]]=s.top();

        s.push(nums2[i]);

    }

    for (int i=0; i<ans.size(); i++) {
        ans[i] = m[nums1[i]];
    }

    return ans;
    
}

int main() {
    vector <int> nums2 = {1,3,4,2};
    vector <int> nums1 = {4,1,2};

    vector <int> ans = nextgreaterelement(nums1, nums2);
    for (int val : ans) {
        cout << val << " ";
    }
    return 0;
}