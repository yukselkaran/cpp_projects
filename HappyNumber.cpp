#include <iostream>
using namespace std;

int getSumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool HappyNumber(int n) {
    int slow = n;
    int fast = n;
    do {
        slow = getSumOfSquares(slow);  
        fast = getSumOfSquares(getSumOfSquares(fast));  

        if (fast == 1 || slow == 1) {
            return true;
        }
    } while (slow != fast);

    return false;
}

int main() {
    cout << boolalpha << HappyNumber(19) << endl;
    cout << boolalpha << HappyNumber(2) << endl; 
}
