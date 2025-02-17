#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    // Đọc mảng từ input (các số cách nhau bởi khoảng trắng)
    vector<int> A;
    int x;
    while(cin >> x){
        A.push_back(x);
    }
    
    int n = A.size();
    if(n == 0) return 0;
    
    // Mảng chứa chỉ số của next greater, khởi tạo với -1
    vector<int> nextGreater(n, -1);
    // Tính next greater cho từng phần tử
    stack<int> st;
    for (int i = 0; i < n; i++){
        // Trong khi stack không rỗng và phần tử hiện tại lớn hơn phần tử tại chỉ số top
        while(!st.empty() && A[i] > A[st.top()]){
            nextGreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Các phần tử còn lại trong stack không có next greater nên vẫn giữ -1.
    
    // Tính next smaller cho từng phần tử
    vector<int> nextSmaller(n, -1);
    while(!st.empty()) st.pop(); // dọn sạch stack
    for (int i = 0; i < n; i++){
        while(!st.empty() && A[i] < A[st.top()]){
            nextSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Các phần tử còn lại trong stack không có next smaller nên giữ -1.
    
    // Tính kết quả cho mỗi phần tử:
    // Kết quả là NS của phần tử NG của A[i] nếu tồn tại, ngược lại là -1.
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++){
        int idxNG = nextGreater[i];
        if(idxNG != -1){
            int idxNS = nextSmaller[idxNG];
            if(idxNS != -1)
                ans[i] = A[idxNS];
            else
                ans[i] = -1;
        } else {
            ans[i] = -1;
        }
    }
    
    // In kết quả
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
