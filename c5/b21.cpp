#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to find the maximum length of valid subexpressions using stack
int maxLengthOfValidParentheses(string P) {
    stack<int> s; // Stack to store indices of '('
    int maxLength = 0;
    s.push(-1); // Initialize stack with a base index

    for (int i = 0; i < P.size(); i++) {
        if (P[i] == '(') {
            // Push the index of '(' onto the stack
            s.push(i);
        } else {
            // Pop the top element from the stack
            s.pop();

            if (!s.empty()) {
                // If the stack is not empty, calculate the length of the valid subexpression
                maxLength = max(maxLength, i - s.top());
            } else {
                // If the stack is empty, push the current index as the new base
                s.push(i);
            }
        }
    }

    return maxLength;
}

int main() {
    string P;

    // Input the expression
    cout << "Enter the parentheses expression: ";
    cin >> P;

    // Find the maximum length of valid subexpressions
    int result = maxLengthOfValidParentheses(P);

    // Output the result
    cout << "Maximum length of valid subexpressions: " << result << endl;

    return 0;
}