// // BRUTE FORCE APPROACH [TC = O(n*k)]
// #include <iostream>
// #include <vector>
// using namespace std;

// vector <int> slidingwindowmax(vector<int> nums, int winsize) {
//     vector<int> ans;
//     for (int i=0; i<=nums.size()-winsize; i++) {    //DETERMINES THE START OF A WINDOW, DOESNT LET THE WINDOW GO OUT OF BOUNDS
//         int currmax = INT16_MIN;
//         for (int j=i; j<i+winsize; j++) {
//             currmax = max(currmax, nums[j]);
//         }
//         ans.push_back(currmax);
//     }
//     return ans;
// }

// int main() {
//    vector<int> nums = {1,3,-1,-3,5,3,6,7};
//    vector<int> ans = slidingwindowmax(nums, 3);
//    for (int val : ans) {
//     cout << val << " ";
//    }
//    return 0; 
// }









// OPTIMISED APPROACH 
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingwindowmax(vector<int> nums, int winsize) {
    deque<int> dq;
    vector<int> ans;
    for (int i=0; i<nums.size(); i++) {
        
        while (!dq.empty() && dq.front() <= i-winsize) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i>=winsize-1) ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<int> ans = slidingwindowmax(nums, 3);
    for (int val : ans) {
        cout << val << " ";
    }
    return 0;
}