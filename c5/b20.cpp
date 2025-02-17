#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(const string& s) {
    stack<int> countStack;     // Lưu số lặp
    stack<string> resultStack; // Lưu xâu tạm thời
    string current = "";
    int k = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            // Tích lũy số (hỗ trợ nhiều chữ số)
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            // Khi gặp '[', đẩy k và xâu hiện tại vào stack
            countStack.push(k);
            resultStack.push(current);
            // Reset current và k
            current = "";
            k = 0;
        } else if (c == ']') {
            // Khi gặp ']', pop số lặp và xâu tạm
            int repeat = countStack.top();
            countStack.pop();
            
            string decoded = resultStack.top();
            resultStack.pop();
            
            // Lặp xâu current theo số repeat và nối vào decoded
            for (int i = 0; i < repeat; i++){
                decoded += current;
            }
            current = decoded;
        } else {
            // Nếu là ký tự thường, nối vào current
            current.push_back(c);
        }
    }
    return current;
}

int main(){
    string s;
    // Sử dụng getline nếu có khoảng trắng trong xâu
    getline(cin, s);
    cout << decodeString(s) << endl;
    return 0;
}
