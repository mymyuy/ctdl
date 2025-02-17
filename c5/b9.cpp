#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    // Có thể mở rộng nếu có thêm các toán tử khác
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main(){
    string postfix;
    cin >> postfix;
    
    stack<string> st;
    
    // Duyệt từ trái sang phải biểu thức hậu tố
    for (char c : postfix) {
        // Nếu là toán hạng, chuyển về chuỗi và push vào stack
        if (!isOperator(c)) {
            st.push(string(1, c));
        }
        else { // Nếu là toán tử
            // Pop toán hạng phải và toán hạng trái từ stack
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            
            // Tạo chuỗi tiền tố: toán tử + toán hạng trái + toán hạng phải
            string expr = c + operand1 + operand2;
            st.push(expr);
        }
    }
    
    // Kết quả cuối cùng nằm ở đỉnh stack
    cout << st.top() << endl;
    
    return 0;
}
