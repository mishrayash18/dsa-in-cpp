#include <iostream>
#include <cmath>
using namespace std;

// calculate number of parity bits
int calcParityBits(int d) {
    int r = 0;
    while (pow(2, r) < (d + r + 1))
        r++;
    return r;
} 

// check if number is power of 2
bool isPowerOfTwo(int x) {
    return (x && !(x & (x - 1)));
}

int main() {


    int d, n;

    cout << "SENDER SIDE\n";
    cout << "Provide value of d (data bits): ";
    cin >> d;

    int r = calcParityBits(d);

    cout << "Enter value of n (total Hamming code length): ";
    cin >> n;

    int data[d];
    cout << "Enter data bits:\n";
    for (int i = 0; i < d; i++)
        cin >> data[i];

    int hamming[n + 1];

    // Place data & parity positions
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if (isPowerOfTwo(i))
            hamming[i] = 0;
        else
            hamming[i] = data[j++];
    }

    // Calculate parity bits
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for (int k = 1; k <= n; k++) {
            if (k & pos)
                parity ^= hamming[k];
        }
        hamming[pos] = parity;
    }

    cout << "\nLength of Hamming Code = " << n << endl;

    cout << "Parity bits: ";
    for (int i = 0; i < r; i++)
        cout << hamming[(int)pow(2, i)] << " ";

    cout << "\nHamming Code: ";
    for (int i = 1; i <= n; i++)
        cout << hamming[i] << " ";


    cout << "\n\nRECEIVER SIDE\n";

    int received[n + 1];

    cout << "Enter received Hamming code:\n";
    for (int i = 1; i <= n; i++)
        cin >> received[i];

    int parityBits[r];
    cout << "Enter parity bits:\n";
    for (int i = 0; i < r; i++)
        cin >> parityBits[i];

    int errorPos = 0;

    // Syndrome calculation
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for (int k = 1; k <= n; k++) {
            if (k & pos)
                parity ^= received[k];
        }

        if (parity != 0)
            errorPos += pos;
    }

    cout << "\nLength of original message = " << d << endl;

    if (errorPos == 0)
        cout << "No error\n";
    else {
        cout << "Error in bit position = " << errorPos << endl;
        received[errorPos] ^= 1;

        cout << "Corrected Hamming Code: ";
        for (int i = 1; i <= n; i++)
            cout << received[i] << " ";
    }

    return 0;
}