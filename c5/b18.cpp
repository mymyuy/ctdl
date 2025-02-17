#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main(){
    // Nhập mảng A từ input (các số cách nhau bởi khoảng trắng)
    vector<int> A;
    int x;
    while(cin >> x){
        A.push_back(x);
    }
    
    int n = A.size();
    
    // Đếm tần số xuất hiện của mỗi phần tử
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++){
        freq[A[i]]++;
    }
    
    // Vector ans để lưu kết quả
    vector<int> ans(n, -1);
    stack<int> st;  // Stack chứa chỉ số các phần tử
    
    // Duyệt từ phải sang trái
    for (int i = n - 1; i >= 0; i--){
        // Pop các phần tử có tần số nhỏ hơn hoặc bằng tần số của A[i]
        while (!st.empty() && freq[A[st.top()]] <= freq[A[i]])
            st.pop();
        
        // Nếu stack không rỗng, phần tử phía trên đỉnh là phần tử có tần số lớn hơn gần nhất bên phải
        if (!st.empty())
            ans[i] = A[st.top()];
        else
            ans[i] = -1;
        
        // Push chỉ số hiện tại vào stack
        st.push(i);
    }
    
    // In kết quả
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}
