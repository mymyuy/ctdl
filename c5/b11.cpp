#include <iostream>
#include <stack>
#include <string>
#include <cctype> // để sử dụng hàm isdigit
using namespace std;

int main() {
    string expr;
    cin >> expr;
    
    stack<int> st;
    
    // Duyệt qua từng ký tự trong biểu thức hậu tố
    for (char c : expr) {
        if (isdigit(c)) {
            // Nếu là số, chuyển ký tự thành số và push vào stack
            st.push(c - '0');
        } else {
            // Nếu là toán tử, pop ra hai toán hạng từ stack
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            
            int result = 0;
            switch(c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2; // giả sử không có phép chia cho 0
                    break;
            }
            // Đẩy kết quả về lại stack
            st.push(result);
        }
    }
    
    // Phần tử duy nhất còn lại trên stack chính là kết quả của biểu thức
    cout << st.top();
    
    return 0;
}
