#include <iostream>
#include <stack>
using namespace std;

class queue {
private:
    stack <int> s1;
    stack <int> s2;
public:
    queue() {};

    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s1.empty()) return -1;

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int val=s2.top();
        s2.pop();
        
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return val;
    }

    int peek() {
        if (s1.empty()) return -1;

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int val = s2.top();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return val;
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop();
}