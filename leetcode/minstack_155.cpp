// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// class minstack {
// public:
//     stack <int> mins;
//     stack <int> mains;

//     minstack(){  };

//     int push(int val) {
//         mains.push(val);
//         if (val<mins.top() || mins.empty()) mins.push(val);
//     }

//     int pop() {
//         if (mains.top()==mins.top()) mins.pop();
//         mains.pop();    
//     }

//     int getmin() {
//         return mins.top();
//     }
    
//     int top() {
//         return mains.top();
//     }
// };

// int main() {
//     minstack s;
//     s.push(10);
//     s.push(20);
//     s.push(5);
//     cout << "Min: " << s.getmin() << endl; 
//     s.pop();
//     cout << "Top: " << s.top() << endl;   
//     cout << "Min: " << s.getmin() << endl; 
//     return 0;
// }