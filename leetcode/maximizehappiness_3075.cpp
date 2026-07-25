#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximizehappiness(vector <int> happiness, int k) {
    int n = happiness.size();
    sort(happiness.end(), happiness.begin(), greater <int> ());
    int curr = 0;
    int picksofar = 0;
    for (int i=0; i<k; i++) {
        
        int gain = happiness[i]-picksofar;

        if (gain>0) {
            curr+=gain;
        }
        else {
            picksofar++;
        }        
    }
    return curr;
}

int main() {
    vector <int> happiness {2,5,3,1,6};
    int ans = maximizehappiness(happiness, 3);
    cout << ans;
    return 0;
}