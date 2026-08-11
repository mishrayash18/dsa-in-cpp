#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> tTOs;
    unordered_map<char, char> sTOt;

    if (s.size()!=t.size()) return false;

    for (int i=0; i<s.size(); i++) {
        if (sTOt.find(s[i]) != sTOt.end()) {
            
            if (sTOt[s[i]] != t[i]) return false;
        }

        sTOt[s[i]] = t[i];
    }

    for (int i=0; i<t.size(); i++) {
        if (tTOs.find(t[i]) != tTOs.end()) {

            if (tTOs[t[i]] != s[i]) return false;
        }

        tTOs[t[i]] = s[i];
    }

    return true;
    
}

int main() {
    cout << isIsomorphic("egg", "add");
} 