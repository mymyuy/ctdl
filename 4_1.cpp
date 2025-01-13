#include <iostream>
using namespace std;

long long ComputeFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * ComputeFactorial(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        long long result = ComputeFactorial(n);
        cout << "Factorial of " << n << " is: " << result << endl;
    }

    return 0;
}
