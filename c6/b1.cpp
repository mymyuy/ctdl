#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<string> q;
    q.push("1");
    
    for (int i = 0; i < n; i++) {
        string s = q.front();
        q.pop();
        cout << s << " ";
        
        // Thêm hai số nhị phân tiếp theo vào queue
        q.push(s + "0");
        q.push(s + "1");
    }
    
    return 0;
}
