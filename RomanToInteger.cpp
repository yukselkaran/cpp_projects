#include <iostream>
#include <string>
using namespace std;
int value(char c);
int RomanToInteger(string s);
int main() {
    cout << RomanToInteger("MLIX") << endl;
}
int value(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int RomanToInteger(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        int current = value(s[i]);
        int next = value(s[i + 1]);

        if (current < next) {
            sum += (next - current);
            i++;
        }
        else {
            sum += current;
        }
    }
    return sum;
}
