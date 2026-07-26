// print n nos
// #include <iostream>
// using namespace std;

// void nNaturalNos(int n) {
//     if (n==1){
//         cout << "1\n";
//         return;
//     }
//     cout << n << '\n';
//     nNaturalNos(n-1);
// }

// int main() {
//     nNaturalNos(10);
// }




// factorial
// #include <iostream>
// using namespace std;

// int fact(int n) {
//     if (n==0) {
//         return 1;
//     }
//     return n*fact(n-1);
// }

// int main() {
//     int x = fact(4);
//     cout << x;
// }




// // sum of n nums
// #include <iostream>
// using namespace std;

// int sumNnums(int n) {
//     if (n==1) {
//         return 1;
//     }
//     return n + sumNnums(n-1);
// }

// int main() {
//     int x = sumNnums(4);
//     cout << x;
// }




// fibonacci numbers
// #include <iostream>
// using namespace std;

// int fibonacci(int n) {
//     if (n==1 || n==0) {
//         return n;
//     }
//     return fibonacci(n-1)+fibonacci(n-2);
// }

// int main() {
//     cout << fibonacci(4);
// }





// check if array is sorted or not
// #include <iostream>
// #include <vector>
// using namespace std;

// bool isSorted(vector <int> nums, int n) {
//     if (n==1||n==0) {
//         return true;
//     }
//     return nums[n-1] >= nums[n-2] && isSorted(nums, n-1);
// }

// int main() {
//     vector <int> nums = {1,2,4,5};
//     cout << isSorted(nums, nums.size());
// }






// binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector <int> nums, int target, int start, int end) {

    if (start>end){
        return -1;
    }
    
    int mid = (start+end)/2;

    if (nums[mid] == target) {
        return mid;
    }

    if (target>nums[mid]) {
        return binarySearch(nums, target, mid+1, end);
    }


    return binarySearch(nums, target, start, mid-1);
         
}

int main() {
    vector <int> nums = {9,4,3,11,7,15};
    sort(nums.begin(), nums.end());
    cout << binarySearch(nums, 11, 0, nums.size());
}