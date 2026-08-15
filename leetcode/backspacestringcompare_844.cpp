#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> s1;
    stack<char> s2;
    

    for (char c : s) {
        if (c == '#' && !s1.empty()) {
            s1.pop();
        }
        else if (c == '#' && s1.empty()) continue;

        else {
            s1.push(c);
        }
    }

    for (char c : t) {
        if (c == '#' && !s2.empty()) {
            s2.pop();
        }
        else if (c == '#' && s2.empty()) continue;

        else {
            s2.push(c);
        }
    }

    while (!s1.empty() && !s2.empty()) {
        if (s1.top() != s2.top()) return false;
        s1.pop();
        s2.pop();
    }

    return s1.empty() && s2.empty();
}

int main() {
    cout << backspaceCompare("ab#c", "ad#c");
}