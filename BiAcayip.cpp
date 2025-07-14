#include <iostream>
using namespace std;

// Sayının basamaklarının karelerinin toplamını hesaplayan fonksiyon
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

    // Hızlı ve yavaş işaretçi yaklaşımı
    do {
        slow = getSumOfSquares(slow);  // Yavaş işaretçi 1 adım
        fast = getSumOfSquares(getSumOfSquares(fast));  // Hızlı işaretçi 2 adım

        // Eğer fast ve slow işaretçileri aynı sayıya gelirlerse, döngü var demektir
        if (fast == 1 || slow == 1) {
            return true;  // Mutlu sayı
        }
    } while (slow != fast);

    return false;  // Mutlu sayı değil
}

int main() {
    cout << boolalpha << HappyNumber(19) << endl;  // true
    cout << boolalpha << HappyNumber(2) << endl;   // false
}
