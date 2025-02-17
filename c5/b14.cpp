#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;  // Nhập mẫu biểu thức chỉ gồm I và D
    int n = s.size();
    
    stack<int> st;
    string result = "";
    
    // Duyệt từ 0 đến n (nếu i == n, tức kết thúc mẫu, cần pop các phần tử còn lại)
    for (int i = 0; i <= n; i++) {
        st.push(i + 1);
        
        // Nếu đã hết mẫu hoặc ký tự hiện tại là 'I', pop toàn bộ stack
        if (i == n || s[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    cout << result << endl;
    return 0;
}
