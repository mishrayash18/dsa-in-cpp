#include <iostream>
using namespace std;

int reverse(int x) {
    int rev = 0;

    while (x!=0) {
        int digit = x%10;
        x/=10;

        rev = rev*10 + digit;

        if (rev>INT32_MAX || rev<INT32_MIN) return 0;
    }
    return rev;
}

int main() {
    int ans = reverse(23204);
    cout << ans;
}