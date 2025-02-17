#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int S, T;
    cin >> S >> T;
    
    // Nếu S >= T, chỉ cần trừ đi 1 từng bước
    if(S >= T){
        cout << S - T;
        return 0;
    }
    
    // Xác định giới hạn trên cho BFS
    int maxVal = 2 * T;  // có thể là 2*T, vì T < 10000 nên maxVal < 20000
    
    vector<int> dist(maxVal+1, -1);  // lưu khoảng cách từ S đến mỗi giá trị, -1 nghĩa chưa thăm
    queue<int> q;
    
    dist[S] = 0;
    q.push(S);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        // Nếu đạt đến T, in ra số bước và dừng
        if(cur == T){
            cout << dist[cur];
            return 0;
        }
        
        // Thao tác 1: nhân 2
        int nxt = cur * 2;
        if(nxt <= maxVal && dist[nxt] == -1){
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
        
        // Thao tác 2: trừ 1
        nxt = cur - 1;
        if(nxt > 0 && dist[nxt] == -1){  // giá trị phải dương
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    return 0;
}
