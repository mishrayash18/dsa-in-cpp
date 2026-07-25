// // BRUTE FORCE APPROACH
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> rearrange(vector <int> nums) {
//     vector <int> neg, pos, result;
//     int n = nums.size();

//     for (int i=0; i<n; i++) {
//         if (nums[i]<0) neg.push_back(nums[i]);
        
//         else pos.push_back(nums[i]);
//     }

//     for (int i=0; i<n/2; i++) {
//         result.push_back(pos[i]);
//         result.push_back(neg[i]);
//     }
//     return result;
// }

// int main() {
//     vector <int> nums = {3,1,-2,-5,2,-4};
//     vector <int> result = rearrange(nums);
//     for (int val : result) {
//         cout << val << " ";
//     }
//     return 0;
// }










// // OPTIMIZED APPROACH
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> rearrange(vector <int> nums) {
//     int n = nums.size();
//     vector <int> result(n);
//     int posi=0, negi=1;

//     for (int x : nums) {
//         if (x>0) {
//             result[posi] = x;
//             posi+=2;
//         }
//         else {
//             result[negi] = x;
//             negi+=2;
//         }
//     }
//     return result;
// }

// int main() {
//     vector <int> nums = {3,1,-2,-5,2,-4};
//     vector <int> result = rearrange(nums);
//     for (int val : result) {
//         cout << val << " ";
//     }
//     return 0;
// }

