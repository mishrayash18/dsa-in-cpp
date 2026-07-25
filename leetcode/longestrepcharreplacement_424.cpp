#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestrepcharreplacemnet(string str, int k) {
    unordered_map<char, int> m;
    int left=0;
    int maxlen=0;
    int maxfreq=0;

    for (int right=0; right<str.size(); right++) {
        char c = str[right];
        m[c]++;

        maxfreq = max(maxfreq, m[c]);
        
        int winsize = right-left+1;

        if (winsize-maxfreq>k) {
            m[str[left]]--;
            left++;
        }
    
        else {
            maxlen = max(maxlen, winsize);
        }
    }

    return maxlen;
}

int main() {
    string str = "AABACDA";
    int k = 3;
    int ans = longestrepcharreplacemnet(str, k);
    cout << ans;
    return 0;
}