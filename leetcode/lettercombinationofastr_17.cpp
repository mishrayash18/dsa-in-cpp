#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <string> keypad = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void solve (string digits, int idx, string curr, vector<string> &ans) {
    if (idx == digits.size()) {
        ans.push_back(curr);
        return;
    }

    int digit = digits[idx] - '0';
    for (char c : keypad[digit]) {
        solve(digits, idx+1, curr+c, ans);
    }
}

vector<string> lettercombinations(string digits) {
    vector<string> ans;
    if (digits.empty()) return ans;

    solve(digits, 0, "", ans);
    return ans;
}



int main() {
    string digits = "23";
    vector<string> ans = lettercombinations(digits);
    for (string s : ans) {
        cout << s << " ";
    }
    return 0;
}