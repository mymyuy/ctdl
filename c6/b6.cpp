#include <iostream>
#include <cmath>
using namespace std;

int main(){
    unsigned int N;
    cin >> N;
    
    int steps = 0;
    
    // Khi N đã về 1 thì dừng.
    while(N > 1) {
        // Nếu N >= 4 và hợp số (có ước trong [2, sqrt(N)]), sử dụng thao tác (b)
        bool composite = false;
        int bestDivisor = 0; // lưu ước d lớn nhất
        // Nếu N < 4 thì không có ước nào (vì 2,3 là nguyên tố) -> phải dùng (a)
        if(N >= 4) {
            for (int d = 2; d * d <= N; d++){
                if(N % d == 0) {
                    composite = true;
                    if(d > bestDivisor) {
                        bestDivisor = d;
                    }
                }
            }
        }
        if(composite) {
            // Thao tác (b): giảm N thành N/d, với d là ước lớn nhất tìm được.
            N = N / bestDivisor;
            steps++;
        } else {
            // N là nguyên tố hoặc N < 4 → chỉ có thao tác (a)
            N = N - 1;
            steps++;
        }
    }
    
    cout << steps;
    return 0;
}
