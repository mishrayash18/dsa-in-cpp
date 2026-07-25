#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector <int> nextgreaterelememt(vector<int> nums1, vector<int> nums2) {
    int n = nums2.size();
    unordered_map <int, int> m;
    stack <int> s;
    vector <int> ans(nums1.size());
    
    for (int i=2*n-1; i>=0; i--) {

        while (!s.empty() && s.top()<=nums2[i%n]) s.pop();

        if (s.empty()) m[nums2[i%n]]=-1;

        else if (s.top()>nums2[i%n]) m[nums2[i%n]] = s.top();

        s.push(nums2[i%n]);
    }

    for (int i=0; i<ans.size(); i++) {
        ans[i]=m[nums1[i]];
    }
    return ans;
}

int main() {
    vector <int> nums2 = {1,2,1};
    vector <int> nums1 = {1,2,1};

    vector <int> ans = nextgreaterelememt(nums1, nums2);
    for (int val : ans) {
        cout << val << " ";
    }
    return 0;
}