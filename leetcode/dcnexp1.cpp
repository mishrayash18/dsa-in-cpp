#include <iostream>
#include <cmath>
using namespace std;

int main() {

    string data, pattern, stuffedBit;
    string stuffedData = "", destuffedData = "";

    
    cout << "----------- SENDER -----------\n";

    cout << "Enter bit stream (15 to 20 bits): ";
    cin >> data;

    if (data.length() < 15 || data.length() > 20) {
        cout << "Invalid input length\n";
        return 0;
    }

    cout << "Enter pattern: ";
    cin >> pattern;

    cout << "Enter stuffed bit: ";
    cin >> stuffedBit;

    int m = pattern.length();

    // Bit Stuffing
    for (int i = 0; i < data.length(); i++) {
        stuffedData += data[i];

        if (stuffedData.length() >= m &&
            stuffedData.substr(stuffedData.length() - m, m) == pattern)
        {
            stuffedData += stuffedBit;
        }
    }

    cout << "\nStuffed Data: " << stuffedData << endl;

    // Frame calculation (8 bits per frame)
    int frameSize = 8;
    int totalFrames = ceil((double)stuffedData.length() / frameSize);

    cout << "Total number of frames: " << totalFrames << endl;



    
    cout << "\n----------- RECEIVER -----------\n";

    string receivedData, r_pattern, r_stuffedBit;

    cout << "Enter received stuffed data: ";
    cin >> receivedData;

    cout << "Enter pattern: ";
    cin >> r_pattern;

    cout << "Enter stuffed bit: ";
    cin >> r_stuffedBit;

    int rm = r_pattern.length();

    // De-stuffing
    for (int i = 0; i < receivedData.length(); i++) {

        destuffedData += receivedData[i];

        if (destuffedData.length() >= rm &&
            destuffedData.substr(destuffedData.length() - rm, rm) == r_pattern)
        {
            i++; // skip stuffed bit
        }
    }

    cout << "\nOriginal Data after De-stuffing: " << destuffedData << endl;

    return 0;
}
