#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

string s; // biểu thức ban đầu
vector<pair<int,int>> pairs; // lưu các cặp ngoặc (vị trí mở, vị trí đóng)
set<string> results; // lưu các biểu thức thu được (tự động sắp xếp theo thứ tự từ điển)

// DFS sinh tập hợp các lựa chọn xóa các cặp ngoặc
// idx: chỉ số hiện tại trong danh sách các cặp
// removed: vector boolean với độ dài = số cặp, true nghĩa là cặp đó bị xóa
void dfs(int idx, vector<bool>& removed) {
    if(idx == pairs.size()){
        // Nếu không xóa cặp nào thì bỏ qua (không in ra biểu thức ban đầu)
        bool anyRemoved = false;
        for(bool b : removed)
            if(b) { anyRemoved = true; break; }
        if(!anyRemoved) return;
        
        // Xây dựng biểu thức mới bằng cách loại bỏ các dấu ngoặc đã xóa
        string expr = "";
        vector<bool> removeMark(s.size(), false);
        for (int i = 0; i < pairs.size(); i++){
            if(removed[i]){
                removeMark[pairs[i].first] = true;
                removeMark[pairs[i].second] = true;
            }
        }
        for (int i = 0; i < s.size(); i++){
            if(!removeMark[i])
                expr.push_back(s[i]);
        }
        results.insert(expr);
        return;
    }
    
    // Không xóa cặp ngoặc tại vị trí idx
    removed[idx] = false;
    dfs(idx + 1, removed);
    
    // Xóa cặp ngoặc tại vị trí idx
    removed[idx] = true;
    dfs(idx + 1, removed);
    // Quay lui (mặc dù ở đây không cần vì chúng ta ghi đè luôn)
    removed[idx] = false;
}

int main() {
    getline(cin, s);
    
    // Bước 1: Xác định các cặp ngoặc khớp bằng cách dùng stack
    stack<int> st;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')'){
            int openPos = st.top();
            st.pop();
            pairs.push_back({openPos, i});
        }
    }
    // Để duyệt đệ quy theo thứ tự từ trái sang phải,
    // ta sắp xếp các cặp theo vị trí dấu ngoặc mở
    sort(pairs.begin(), pairs.end());
    
    vector<bool> removed(pairs.size(), false);
    dfs(0, removed);
    
    // Bước 4: In kết quả (set tự động sắp xếp theo thứ tự từ điển)
    for(auto &expr : results)
        cout << expr << "\n";
        
    return 0;
}
