#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeParentheses(const string &expr) {
    string result = "";
    // Stack lưu dấu hiệu hiện hành: +1 cho dấu dương, -1 cho dấu âm
    stack<int> signStack;
    signStack.push(1); // dấu hiệu ban đầu là dương

    for (int i = 0; i < expr.size(); i++) {
        char c = expr[i];
        if (c == '+' || c == '-') {
            // Tính dấu hiệu hiệu quả dựa trên dấu hiện hành.
            int effective = signStack.top() * (c == '+' ? 1 : -1);
            // Ghi nhận toán tử hiệu quả
            result.push_back(effective == 1 ? '+' : '-');
        } else if (c == '(') {
            // Kiểm tra toán tử ngay trước '(' để xác định dấu hiệu bên trong
            if (i > 0 && expr[i - 1] == '-') {
                // Nếu trước '(' là dấu '-', đảo dấu hiệu hiện hành
                signStack.push(-signStack.top());
            } else {
                // Nếu trước đó là '+' hoặc không có toán tử nào, giữ nguyên dấu hiệu
                signStack.push(signStack.top());
            }
        } else if (c == ')') {
            // Khi gặp dấu đóng ngoặc, loại bỏ dấu hiệu của cấp ngoặc đó
            signStack.pop();
        } else {
            // Với các ký tự toán hạng, ghi nhận trực tiếp
            result.push_back(c);
        }
    }
    
    // Nếu biểu thức bắt đầu bằng dấu '+', loại bỏ nó đi
    if (!result.empty() && result[0] == '+') {
        result.erase(result.begin());
    }
    return result;
}

int main() {
    string expr;
    cin >> expr;
    
    cout << removeParentheses(expr);
    return 0;
}
