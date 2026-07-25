#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockspan(vector<int> stocks) {
    stack<int> s;
    vector<int> span(stocks.size());

    for (int i=0; i<stocks.size(); i++) {
        while (!s.empty() && stocks[s.top()] <= stocks[i]) {
            s.pop();
        }

        if (s.empty()) span[i]=i+1;
        else span[i]=i-s.top();

        s.push(i);

    }
    return span;
}

int main() {
    vector<int> stocks={100,80,60,70,60,75,85};
    vector <int> ans = stockspan(stocks);

    for(int val : ans) {
        cout << val << " ";
    }
    return 0;
}