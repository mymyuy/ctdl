#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm kiểm tra ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    string prefix;
    cin >> prefix;
    
    stack<string> st;
    
    // Duyệt biểu thức tiền tố từ phải sang trái
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        // Nếu ký tự là toán tử
        if (isOperator(c)) {
            // Lấy ra hai toán hạng từ stack
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            // Tạo biểu thức trung tố với dấu ngoặc đầy đủ
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        } else {
            // Nếu ký tự là toán hạng, đưa vào stack dưới dạng chuỗi
            st.push(string(1, c));
        }
    }
    
    // Kết quả là phần tử duy nhất còn lại trên stack
    cout << st.top();
    
    return 0;
}
