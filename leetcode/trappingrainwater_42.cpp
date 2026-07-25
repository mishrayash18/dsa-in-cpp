#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int watertrap(vector <int> heights) {
    int n=heights.size();
    stack <int> s;
    int totalwater = 0;
    for (int i=0; i<n; i++) {
        while (!s.empty() && heights[i] > heights[s.top()]) {
            int top = s.top();
            s.pop();
            if (s.empty()) break;
            int width = i-s.top()-1;
            int height = min(heights[i], heights[s.top()])-heights[top];
            int trapped = width*height;

            totalwater+=trapped;
        }
        s.push(i);
    }
    return totalwater;
}

int main() {
    vector <int> heights = {2,1,4,10,3,12};
    int totalwater = watertrap(heights);
    cout << totalwater << endl;
    return 0;
}