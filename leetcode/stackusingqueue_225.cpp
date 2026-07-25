// // BRUTE FORCE APPROACH (SC = O(n))
// #include <iostream>
// #include <queue>
// using namespace std;

// class stack {
// private:
//     queue <int> q1, q2;
// public:

//     void push(int x) {
//         q1.push(x);
//     }

//     int pop() {
//         if (q1.empty()) return -1;

//         while (q1.size()>1) {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         int val=q1.front();
//         q1.pop();

//         swap(q1, q2);
//         return val;
//     }
    
//     int top() {
//         if (q1.empty()) return -1;

//         while (q1.size()>1) {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         int val=q1.front();
//         q2.push(q1.front());
//         q1.pop();

//         swap(q1, q2);

//         return val;
//     }

//     bool empty() {
//         return q1.empty();
//     }
// };

// int main() {
//     stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     cout << s.top() << endl;
//     cout << s.pop() << endl;
//     cout << s.top() << endl;
// }









// OPTIMIZED APPROACH
#include <iostream>
#include <queue>
using namespace std;

class stack {
private:
    queue <int> q1;

public:
    void push(int x) {
        queue <int> q2;
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;

        int val=q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) return -1;

        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    return 0;
}