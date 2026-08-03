#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool detectCapitalUse(string word) {
    int capcount = 0;
    for (char ch : word) {
        if (isupper(ch)) capcount++;
    }
    if (capcount==word.size()) return true;
    if (capcount==0) return true;
    if (capcount==1 && isupper(word[0])) return true;
    else return false;
}

int main() {
    cout << detectCapitalUse("Hello") << endl;
    cout << detectCapitalUse("HELLO") << endl;
    cout << detectCapitalUse("hello") << endl;
    cout << detectCapitalUse("HEllo") << endl;


}