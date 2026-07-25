// // CRC
// #include <iostream>
// #include <cstring>
// using namespace std;

// void xorOperation(char *dividend, char *divisor, int n) {
//     for (int i = 1; i < n; i++) {
//         dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
//     }
// }

// void crc(char *data, char *divisor) {
//     int dataLen = strlen(data);
//     int divLen = strlen(divisor);

//     char temp[20], encoded[20];

//     strcpy(temp, data);

//     for (int i = 0; i < divLen - 1; i++)
//         temp[dataLen + i] = '0';

//     temp[dataLen + divLen - 1] = '\0';

//     char remainder[20];
//     strncpy(remainder, temp, divLen);

//     for (int i = 0; i <= dataLen - 1; i++) {
//         if (remainder[0] == '1')
//             xorOperation(remainder, divisor, divLen);

//         memmove(remainder, remainder + 1, divLen - 1);
//         remainder[divLen - 1] = temp[i + divLen];
//     }

//     cout << "\nParity bits (CRC): " << remainder;

//     strcpy(encoded, data);
//     strcat(encoded, remainder);

//     cout << "\nEncoded data: " << encoded << endl;

//     // Receiver side
//     cout << "\n--- Receiver Side ---\n";

//     char recv[20];
//     cout << "Enter received data: ";
//     cin >> recv;

//     strncpy(remainder, recv, divLen);

//     for (int i = 0; i <= strlen(recv) - divLen; i++) {
//         if (remainder[0] == '1')
//             xorOperation(remainder, divisor, divLen);

//         memmove(remainder, remainder + 1, divLen - 1);
//         remainder[divLen - 1] = recv[i + divLen];
//     }

//     if (strchr(remainder, '1'))
//         cout << "Error detected\n";
//     else
//         cout << "No error\n";
// }

// int main() {
//     char data[20], divisor[10];

//     cout << "Enter data (7-8 bits): ";
//     cin >> data;

//     cout << "Enter divisor (3-4 bits): ";
//     cin >> divisor;

//     crc(data, divisor);

//     return 0;
// }






// hamming code
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