#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string prefix;
    cin >> prefix;
    
    stack<int> st;
    
    // Duyệt biểu thức tiền tố từ phải sang trái
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char token = prefix[i];
        
        // Nếu token là một chữ số (toán hạng)
        if (isdigit(token)) {
            st.push(token - '0');  // chuyển ký tự thành số
        } 
        // Nếu token là một toán tử
        else {
            // Lưu ý: khi pop, phần tử đầu tiên lấy ra là toán hạng bên trái
            int operand1 = st.top(); st.pop();
            int operand2 = st.top(); st.pop();
            int result = 0;
            
            switch(token) {
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
                    result = operand1 / operand2; // giả sử không chia cho 0
                    break;
            }
            st.push(result);
        }
    }
    
    // Phần tử duy nhất trong stack chính là kết quả của biểu thức tiền tố
    cout << st.top();
    
    return 0;
}
