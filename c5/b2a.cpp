#include <iostream>
#include <stack>
#include <string>
using namespace std;

int countReversals(const string &expr) {
    int n = expr.size();
    // Với bài toán này, độ dài xâu luôn chẵn.
    // Nếu n không chẵn thì không thể cân bằng được.
    if(n % 2 != 0)
        return -1;  

    stack<char> st;
    // Ghép cặp các dấu ngoặc hợp lệ
    for (char ch : expr) {
        if (!st.empty() && st.top() == '(' && ch == ')')
            st.pop();
        else
            st.push(ch);
    }
    
    // Đếm số dấu ngoặc không ghép được
    int open = 0, close = 0;
    while (!st.empty()) {
        if (st.top() == '(')
            open++;
        else
            close++;
        st.pop();
    }
    
    // Số lần đảo cần thực hiện
    return (open + 1) / 2 + (close + 1) / 2;
}

int main() {
    string s;
    cin >> s;
    
    int result = countReversals(s);
    cout << result;
    
    return 0;
}
