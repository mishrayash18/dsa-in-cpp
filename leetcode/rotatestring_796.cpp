#include <iostream>
#include <string>
using namespace std;

bool rotatestring (string s1, string goal) {
    if (s1.length() != goal.length()) return false;
    
    string concat = goal+goal;

    if (concat.find(s1) != string::npos) {
        return true;
    }
    else return false;
    
}

int main() {
    cout << rotatestring ("bcdea", "abcde");
}