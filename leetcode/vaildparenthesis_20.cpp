#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class stack {
vector <char> vec;
public:

    void push(char val) {
        vec.push_back(val);
    }

    void pop() {
        vec.pop_back();
    }

    int top() {
        return vec[vec.size()-1];
    }

    bool empty() {
        return (vec.size()==0);
    }

    bool validparenthesis(string str) {
        for (int i=0; i<str.length(); i++) {
            if (empty()) {
                if (str[i]==')' || str[i]=='}' || str[i]==']'){
                    return false;
                }
            }

            if (str[i]=='(' || str[i]=='{' || str[i]=='[') {
                push(str[i]);
            }

            else if (str[i] == ')' && top() == '(') pop();
            else if (str[i] == '}' && top() == '{') pop();
            else if (str[i] == ']' && top() == '[') pop();
            else return false;

        }
        if (empty()) return true;
        else return false; 
    }
};

int main() {
    stack s;
    if (s.validparenthesis("(({}))")) cout << "valid";
    else cout << "invalid";
    return 0;
}