#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm kiểm tra ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    string postfix;
    cin >> postfix;
    
    stack<string> st;
    
    // Duyệt qua từng ký tự trong biểu thức hậu tố
    for (char c : postfix) {
        if (isOperator(c)) {
            // Khi gặp toán tử, pop ra 2 phần tử để làm toán hạng
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            // Tạo biểu thức trung tố có đầy đủ dấu ngoặc
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        } else {
            // Nếu gặp toán hạng, chuyển thành chuỗi và push vào stack
            st.push(string(1, c));
        }
    }
    
    // Kết quả nằm ở phần tử duy nhất của stack
    cout << st.top();
    
    return 0;
}
