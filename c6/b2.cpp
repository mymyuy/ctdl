#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    // Sử dụng queue để lưu các chuỗi số được tạo
    queue<string> q;
    q.push("9");
    
    while(!q.empty()){
        string s = q.front();
        q.pop();
        
        // Tính giá trị dư của s khi chia cho N, xử lý dưới dạng chuỗi
        int rem = 0;
        for(char c : s){
            rem = rem * 10 + (c - '0');
            rem %= N;
        }
        
        // Nếu dư bằng 0, in kết quả và dừng chương trình
        if(rem == 0){
            cout << s;
            break;
        }
        
        // Nếu chưa chia hết, tạo 2 chuỗi mới và đẩy vào queue
        q.push(s + "0");
        q.push(s + "9");
    }
    
    return 0;
}
