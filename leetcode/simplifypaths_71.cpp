#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPaths(string path) {
    stack<string> stk1;
    stack<string> stk2;

    string ans;
    string temp = "";
    int i=0;
    
    while (i<path.size()) {
        int j=i;
        while (j<path.size() && path[j]!='/') {
            temp+=path[j];
            j++;
        }
        i=j+1;

        if (temp == ".") {
            temp="";
            continue;
        }

        else if (temp == ".." && !stk1.empty()) {
            stk1.pop();
            temp="";
        }

        else if (temp == ".." && stk1.empty()) {
            temp="";
            continue;
        }

        else {
            if (!temp.empty()) stk1.push(temp);
            temp="";
        }
        
    }

    while (!stk1.empty()) {
        stk2.push(stk1.top());
        stk1.pop();
    }

    if (stk2.empty()) {
        ans+='/';
        return ans;
    }

    while (!stk2.empty()) {
        ans+='/';
        ans+=stk2.top();
        stk2.pop();
    }

    return ans;

}

int main() {
    string result = simplifyPaths("/.../a/../b/c/../d/./");
    cout << result;
}