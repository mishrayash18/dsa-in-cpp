#include <iostream>
#include <vector>
using namespace std;

bool knows(int a, int b, vector<vector<int>> M) {
    return M[a][b] == 1;
}

int celebrity(vector<vector<int>> M) {
    int n = M.size();
    int cand=0;

    for (int i=1; i<n; i++) {
        if (knows(cand, i, M)) cand=i;        
    }

    for (int i=0; i<n; i++) {
        if (i!=cand && (knows(cand,i,M) || !knows(i, cand, M))) return -1;
    }
    return cand;
}

int main() {
    vector<int> people = {1,2,3,4,5};
    vector<vector<int>> M = {
        {0, 0, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 1, 0}
    };

    int celeb = celebrity(M);
    if (celeb==-1) {
        cout << "no celebrity exists\n";
    }

    else {
        cout << "celebrity is person "<< people[celeb] << endl;
    }

    
    return 0;
}