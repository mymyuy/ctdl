#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;  // Nhập xâu chứa các ký tự '(' và ')'
    
    stack<int> st;
    st.push(-1);  // Khởi tạo với -1 để hỗ trợ tính toán chiều dài
    int maxLen = 0;
    
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(') {
            st.push(i);
        } else { // s[i] == ')'
            st.pop();  // Pop một phần tử ra khỏi stack
            if (st.empty()) {
                // Nếu stack rỗng, push vị trí hiện tại làm cơ sở cho dãy mới
                st.push(i);
            } else {
                // Chiều dài dãy ngoặc đúng hiện tại = i - vị trí đỉnh stack
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    
    cout << maxLen;
    return 0;
}
