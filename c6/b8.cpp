#include <iostream>
#include <unordered_set>

using namespace std;

// Function to check if a number satisfies the conditions
bool isValidNumber(int num) {
    unordered_set<int> digits; // To track unique digits
    while (num > 0) {
        int digit = num % 10; // Extract the last digit
        // Check if the digit is greater than 5
        if (digit > 5) return false;
        // Check if the digit is already seen
        if (digits.find(digit) != digits.end()) return false;
        digits.insert(digit); // Mark the digit as seen
        num /= 10; // Remove the last digit
    }
    return true;
}

// Function to count valid numbers in the range [L, R]
int countValidNumbers(int L, int R) {
    int count = 0;
    for (int num = L; num <= R; ++num) {
        if (isValidNumber(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    int L, R;

    // Input the range [L, R]
    cout << "Enter L and R: ";
    cin >> L >> R;

    // Count the valid numbers
    int result = countValidNumbers(L, R);

    // Output the result
    cout << "Number of valid numbers in range [" << L << ", " << R << "]: " << result << endl;

    return 0;
}