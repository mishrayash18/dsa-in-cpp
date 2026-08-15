#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE
// vector <int> productExceptSelf(vector<int> nums) {
//     vector<int> ans;
    
//     for (int i=0; i<nums.size(); i++) {
//         int leftProduct = 1;
//         int rightProduct = 1;

//         if (i==nums.size()-1) {
//             int j=0;
//             while (j<i) {
//                 leftProduct*=nums[j];
//                 j++;
//             }
//         }

//         else {
//             int j=0;
//             int k=i+1;
//             if (i==0){
//                 while (k<nums.size()) {
//                     rightProduct*=nums[k];
//                     k++;
//                 } 
//             }
//             else {
//                 while (j<i) {
//                     leftProduct*=nums[j];
//                     j++;
//                 }
//                 while (k<nums.size()) {
//                     rightProduct*=nums[k];
//                     k++;
//                 }
//             }
            
//         }

//         ans.push_back(leftProduct*rightProduct);
//     }
//     return ans;
// }


// OPTIMIZED
vector <int> productExceptSelf(vector<int> nums) {
    vector <int> ans(nums.size());
    int leftProduct=1;
    int rightProduct=1;

    for (int i=0; i<nums.size(); i++) {
        ans[i]=leftProduct;
        leftProduct*=nums[i];        
    }

    for (int j=nums.size()-1; j>-1; j--) {
        ans[j]*=rightProduct;
        rightProduct*=nums[j];
    }

    return ans;
}

int main() {
    vector<int> ans = productExceptSelf({1,2,3,4});
    for (int val : ans) {
        cout << val << endl;
    }
    return 0;
}