#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstuniqchar(string s) {
    unordered_map<char, int> m;
    queue<int> q;
    int n=s.size();

    for (int i=0; i<n; i++) {
        if (m.find(s[i])==m.end()) {
            q.push(i);
        }
        m[s[i]]++; //INCREASING FREQUENCY

        while (!q.empty() && m[s[q.front()]]>1) {
            q.pop();
        }
    }
    if (q.empty()) return -1;
    return q.front();
}

int main() {
    string s = "level";
    int ans = firstuniqchar(s);
    cout << ans;
    return 0;
}