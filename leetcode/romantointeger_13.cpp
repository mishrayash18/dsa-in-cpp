#include <iostream>
#include <string>
using namespace std;

int romantostring(string s) {
    int n = s.size();
    int curr = 0;
    for (int i=0; i<n; i++) {
        
        switch (s[i]) {
            case 'I' :
                curr+=1;
                if (s[i+1] == 'V' || s[i+1] == 'X') curr-=2;
                break;
            case 'V' :
                curr+=5;
                break;
            case 'X' :
                curr+=10;
                if (s[i+1] == 'L' || s[i+1] == 'C') curr-=20;
                break;
            case 'L' :
                curr+=50;
                break;
            case 'C' :
                curr+=100;
                if (s[i+1] == 'D' || s[i+1] == 'M') curr-=200; 
                break;
            case 'D' :
                curr+=500;
                break;
            case 'M' :
                curr+=1000;
                break;
        }
    }
    return curr;
}

int main() {
    int ans = romantostring("IV");
    cout << ans;
    return 0;
}