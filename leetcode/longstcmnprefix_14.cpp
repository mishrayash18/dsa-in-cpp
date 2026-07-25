#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestcommonprefix(vector <string>& strs) {
    if (strs.empty()) return "";

    string first = strs[0];

    for (int i=0; i<strs.size(); i++) {
        char c = first[i];

        for (int j=1; j<strs.size(); j++) {
            if (i>=strs[j].size() || strs[j][i] != c) {
                return first.substr(0, i);
            }
        }
    }
    return first;
}

int main() {
    vector <string> strs = {"flowers", "flight", "flow"};
    string ans = longestcommonprefix(strs);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}