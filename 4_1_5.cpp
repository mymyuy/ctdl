#include <iostream>
using namespace std;

int fibonacci_recursive(int n) {
    return n <= 1 ? n : fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n) {
    int a = 0, b = 1, c = 0;
    for (int i = 1; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    cout << fibonacci_recursive(10) << endl;
    cout << fibonacci_iterative(10) << endl;
    return 0;
}
