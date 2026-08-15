#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int calPoints(vector<string> operations) {
    stack<int> score;
    int result = 0;
    for (string val : operations) {
        if (val == "C") {
            score.pop();
        }
        
        else if (val == "D") {
            score.push(score.top()*2);
        }

        else if (val == "+") {
            int num = score.top();
            score.pop();
            int ans = num+score.top();
            score.push(num);
            score.push(ans);
        }

        else {
            int num = stoi(val);
            score.push(num);
        }
    }

    while (!score.empty()) {
        result+=score.top();
        score.pop();
    }

    return result;
    
}

int main() {
    int ans = calPoints({"5","2","C","D","+"});
    cout << ans;
}