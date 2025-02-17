#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int n;
    // Đọc số cột (n) nếu cần, hoặc đọc trực tiếp dãy chiều cao.
    // Ví dụ: input: 6 2 5 4 5 1 6 (n = 7)
    vector<int> H;
    int x;
    while(cin >> x){
        H.push_back(x);
    }
    
    n = H.size();
    int maxArea = 0;
    stack<int> st; // chứa chỉ số của các cột

    for (int i = 0; i < n; i++){
        // Nếu stack không rỗng và chiều cao cột hiện tại < chiều cao cột ở đỉnh stack
        while (!st.empty() && H[i] < H[st.top()]){
            int topIdx = st.top();
            st.pop();
            int height = H[topIdx];
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    
    // Tính diện tích cho các cột còn lại trong stack
    while(!st.empty()){
        int topIdx = st.top();
        st.pop();
        int height = H[topIdx];
        int width = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, height * width);
    }
    
    cout << maxArea;
    return 0;
}
