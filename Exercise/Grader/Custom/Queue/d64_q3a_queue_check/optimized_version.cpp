#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int mFront, mSize, mCap, last, n, cor;

bool isFull() {
    return (last == mFront) && (mSize == mCap);
}

int calculate_mFront() {
    return (last - mSize + mCap) % mCap;
}

int calculate_mSize() {
    return (last - mFront + mCap) % mCap;
}

int calculate_mCap() {
    int cap = mFront + mSize - last; // TODO fix this equation
    return cap == 0 ? (last + 1) : cap;
}

int calculate_last() {
    return (mFront + mSize) % mCap;
}

void checkAndOutput(ofstream &out, int calculatedValue, int actualValue) {
    if (calculatedValue == actualValue) {
        cout << "OK" << endl;
        out << "OK" << endl;
    } else {
        cout << "WRONG " << calculatedValue << endl;
        out << "WRONG " << calculatedValue << endl;
    }
}

void handleCase(ofstream &out) {
    int temp;
    switch (cor) {
        case 0:
            if (isFull()) {
                cout << "OK" << endl;
                out << "OK" << endl;
            } else if (calculate_last() == last && calculate_mCap() <= mCap && calculate_mFront() == mFront && calculate_mSize() == mSize) {
                cout << "OK" << endl;
                out << "OK" << endl;
            } else {
                cout << "WRONG" << endl;
                out << "WRONG" << endl;
            }
            break;
        case 1:
            temp = calculate_mFront();
            checkAndOutput(out, temp, mFront);
            break;
        case 2:
            temp = calculate_mSize();
            if (isFull()) {
                cout << "OK" << endl;
                out << "OK" << endl;
            } else if ((mSize <= mCap) && (temp == mSize)) {
                cout << "OK" << endl;
                out << "OK" << endl;
            } else {
                checkAndOutput(out, temp, mSize);
            }
            break;
        case 3:
            temp = calculate_mCap();
            if (isFull()) {
                cout << "OK" << endl;
                out << "OK" << endl;
            } else if ((mCap >= mSize) && (((last >= mFront + mSize) && (mCap >= temp)) || ((last < mFront + mSize) && (mCap == temp)))) {
                cout << "OK" << endl;
                out << "OK" << endl;
            } else {
                checkAndOutput(out, temp, mCap);
            }
            break;
        case 4:
            temp = calculate_last();
            checkAndOutput(out, temp, last);
            break;
    }
}

int main() {
    ofstream out("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> mFront >> mSize >> mCap >> last >> cor;
        handleCase(out);
    }
    return 0;
}