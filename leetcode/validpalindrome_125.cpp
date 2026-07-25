#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {

    for (int i=0; i<s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    s.erase(remove_if(s.begin(), s.end(), [](char c) {
        return !isalnum((unsigned char) c);
    }), s.end());

    string rev = "";

    for (int i=s.size()-1; i>=0; i--) {
        rev.push_back(s[i]);
    }

    return s == rev;

}

int main() {
    string s = "A man, a plan, a canal: panama";
    cout << isPalindrome(s);

}

