#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestsubstrinstr(string str) {
    unordered_map<char, int> s;
    int maxlen=0, left=0;

    for (int right=0; right<str.size(); right++) {
        char c = str[right];
        if (s.find(c) == s.end()) {
            s[c] = right;
        }

        else {
            left = max(left, s[c]+1);
            s[c] = right;
        }

        maxlen = max(maxlen, right-left+1);
    }
    return maxlen;
}

int main() {
    string str = "abcabcbb";
    int ans = longestsubstrinstr(str);
    cout << ans;
    return 0;
}

