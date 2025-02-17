#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm xác định độ ưu tiên của các toán tử
int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

// Hàm chuyển đổi biểu thức trung tố sang hậu tố
string infixToPostfix(const string &infix) {
    stack<char> st;
    string postfix = "";
    
    for (char ch : infix) {
        // Nếu ký tự là toán hạng (giả sử là các chữ cái)
        if(isalpha(ch)) {
            postfix.push_back(ch);
        }
        // Nếu là dấu mở ngoặc, đưa vào stack
        else if(ch == '(') {
            st.push(ch);
        }
        // Nếu là dấu đóng ngoặc, pop đến khi gặp dấu mở ngoặc
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            if(!st.empty())
                st.pop(); // loại bỏ dấu '('
        }
        // Nếu là toán tử
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Pop các toán tử có độ ưu tiên cao hơn hoặc bằng toán tử hiện tại
            while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }
    
    // Sau khi duyệt xong, pop các toán tử còn lại trong stack
    while(!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }
    
    return postfix;
}

int main() {
    string infix;
    getline(cin, infix);
    
    cout << infixToPostfix(infix);
    
    return 0;
}
