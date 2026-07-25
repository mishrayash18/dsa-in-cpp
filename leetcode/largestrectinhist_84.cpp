#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestrect(vector <int> heights) {
    stack<int> s;
    int n=heights.size();
    int maxarea=0;

    for (int i=0; i<n; i++) {
        while (!s.empty() && heights[i]<heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i-s.top()-1;

            maxarea=max(maxarea, height*width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int height = heights[s.top()];
        s.pop();
        int width = s.empty() ? n : n-s.top()-1;

        maxarea=max(maxarea, height*width);
    }
    
    return maxarea;
}

int main() {
    vector <int> heights = {2,1,5,6,2,3};
    int maxarea=largestrect(heights);
    cout << maxarea << endl;
    return 0;
}