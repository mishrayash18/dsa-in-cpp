#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int gasstation(vector<int> gas, vector<int> cost) {
    if (gas.size() != cost.size()) return -1;
    int n = gas.size();
    
    int totalgas=0, totalcost=0;
    for (int i=0; i<n; i++) {
        totalgas+=gas[i];
        totalcost+=cost[i];
    }
    if (totalgas<totalcost) return -1;

    int tank=0, total=0, start=0;
    for (int i=0; i<n; i++) {
        int gain = gas[i]-cost[i];
        tank+=gain;

        if (tank<0) {
            start=i+1;
            tank=0;
        }
    }

    return start;
}

int main() {
    vector<int> gas = {2,7,6,5};
    vector<int> cost = {10,2,1,3};

    int ans = gasstation(gas, cost);
    cout << ans;
    return 0;
}