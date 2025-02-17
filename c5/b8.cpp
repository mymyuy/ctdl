#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert Prefix expression to Postfix expression
string prefixToPostfix(string prefix) {
    stack<string> s;
    int length = prefix.size();

    // Traverse the prefix expression in reverse order
    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand, push it to the stack
        if (!isOperator(c)) {
            string op(1, c);
            s.push(op);
        }
        // If the character is an operator
        else {
            // Pop two operands from the stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Concatenate the two operands and the operator
            string temp = op1 + op2 + c;

            // Push the concatenated string back to the stack
            s.push(temp);
        }
    }

    // The final result will be at the top of the stack
    return s.top();
}

int main() {
    string prefix;

    // Input the prefix expression
    cout << "Enter the prefix expression: ";
    cin >> prefix;

    // Convert prefix to postfix
    string postfix = prefixToPostfix(prefix);

    // Output the postfix expression
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}