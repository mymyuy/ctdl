#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    // Đọc dãy giá chứng khoán từ input
    vector<int> price;
    int x;
    while(cin >> x){
        price.push_back(x);
    }
    
    int n = price.size();
    vector<int> span(n, 0); // Span của từng ngày
    stack<int> st; // Stack chứa chỉ số của các ngày
    
    // Duyệt từng ngày
    for (int i = 0; i < n; i++){
        // Pop các ngày có giá nhỏ hơn hoặc bằng giá ngày i
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        
        // Nếu stack rỗng, nghĩa là không có ngày trước đó có giá lớn hơn
        if(st.empty())
            span[i] = i + 1;
        else
            span[i] = i - st.top();
        
        // Push ngày hiện tại vào stack
        st.push(i);
    }
    
    // In kết quả
    for (int i = 0; i < n; i++){
        cout << span[i] << " ";
    }
    
    return 0;
}
