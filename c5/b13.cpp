#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Hàm xác định độ ưu tiên của toán tử
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Hàm thực hiện phép tính giữa hai số với toán tử op
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // phép chia theo số nguyên, giả sử b != 0
    }
    return 0;
}

int evaluateExpression(const string &s) {
    stack<int> values;   // Stack chứa các số
    stack<char> ops;     // Stack chứa các toán tử và dấu ngoặc

    for (int i = 0; i < s.length(); i++) {
        // Bỏ qua khoảng trắng (nếu có)
        if(s[i] == ' ')
            continue;
        
        // Nếu là dấu mở ngoặc thì đẩy vào stack toán tử
        if(s[i] == '(') {
            ops.push(s[i]);
        }
        // Nếu gặp một số (có thể nhiều chữ số)
        else if(isdigit(s[i])) {
            int val = 0;
            while(i < s.length() && isdigit(s[i])) {
                val = (val * 10) + (s[i] - '0');
                i++;
            }
            i--; // vì vòng lặp for cũng sẽ tăng i thêm 1
            values.push(val);
        }
        // Nếu gặp dấu đóng ngoặc, xử lý cho đến khi gặp dấu mở ngoặc
        else if(s[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty())
                ops.pop(); // loại bỏ dấu '('
        }
        // Nếu gặp toán tử
        else {
            // Pop các toán tử có độ ưu tiên cao hơn hoặc bằng toán tử hiện tại
            while(!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            // Đẩy toán tử hiện tại vào stack
            ops.push(s[i]);
        }
    }
    
    // Sau khi duyệt hết biểu thức, tiến hành tính toán các toán tử còn lại
    while(!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    
    return values.top();
}

int main(){
    string expression;
    getline(cin, expression);
    cout << evaluateExpression(expression);
    return 0;
}
