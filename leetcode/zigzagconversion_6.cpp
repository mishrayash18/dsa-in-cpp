#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numrows) {
    if (numrows==1) return s;

    int currow=0;
    int dir=1;
    vector <string> rows(numrows);
    
    for (char c : s) {
        rows[currow].push_back(c);

        if (currow==0) dir = 1;
        else if (currow==numrows-1) dir = -1;

        currow+=dir;
    }
    
    string ans;
    for (string r : rows) ans += r;

    return ans;
}

int main() {
    string ans = convert("paypalishiring", 4);
    cout << ans;
    return 0;
}