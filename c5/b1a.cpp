#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidExpression(const string &expr) {
    stack<char> st;
    for (char ch : expr) {
        if (ch == ')') {
            bool operatorFound = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
            }
            if (st.empty()) {
                return false;
            }
            st.pop();
            if (!operatorFound) {
                return false;
            }
        } else {
            st.push(ch);
        }
    }
    return true;
}

int main() {
    string expr;
    getline(cin, expr);
    
    if (isValidExpression(expr))
        cout << "YES";
    else
        cout << "NO";
        
    return 0;
}
