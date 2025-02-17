#include <iostream>
#include <stack>
#include <string>
using namespace std;

string canonicalize(const string &expr) {
    string result = "";
    // Stack lưu ngữ cảnh dấu hiệu: +1 (dương), -1 (âm)
    stack<int> signStack;
    signStack.push(1);  // ngữ cảnh ban đầu: dương
    
    for (int i = 0; i < expr.size(); i++) {
        char c = expr[i];
        
        if (c == '+' || c == '-') {
            // Tính dấu hiệu hiệu quả: ngữ cảnh hiện hành nhân với dấu của toán tử
            int effective = signStack.top() * (c == '+' ? 1 : -1);
            // Ghi nhận toán tử theo dấu hiệu hiệu quả
            result.push_back(effective == 1 ? '+' : '-');
        }
        else if (c == '(') {
            // Nếu trước dấu '(' có dấu '-', thì ngữ cảnh bên trong đảo dấu
            if (i > 0 && expr[i-1] == '-')
                signStack.push(signStack.top() * -1);
            else
                signStack.push(signStack.top());
        }
        else if (c == ')') {
            // Kết thúc ngữ cảnh
            signStack.pop();
        }
        else {
            // Với các toán hạng (ký tự in thường) ta thêm trực tiếp vào kết quả
            result.push_back(c);
        }
    }
    
    // Nếu biểu thức chuẩn hoá bắt đầu bằng '+' thì bỏ dấu đó đi
    if (!result.empty() && result[0] == '+')
        result.erase(result.begin());
    
    return result;
}

int main() {
    string P1, P2;
    getline(cin, P1);
    getline(cin, P2);
    
    // Chuẩn hoá 2 biểu thức
    string canon1 = canonicalize(P1);
    string canon2 = canonicalize(P2);
    
    // So sánh
    if(canon1 == canon2)
        cout << "YES";
    else
        cout << "NO";
        
    return 0;
}
