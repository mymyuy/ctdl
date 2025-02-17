#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull N;
ull countBDN = 0;

// Hàm sinh các số BDN (số chỉ gồm 0 và 1, có nghĩa)
void generateBDN(ull num) {
    if(num > N)
        return;
    // Nếu num <= N, num là một số BDN hợp lệ
    countBDN++;
    // Sinh số tiếp theo bằng cách thêm chữ số 0 và 1 ở cuối
    generateBDN(num * 10);      // append "0"
    generateBDN(num * 10 + 1);    // append "1"
}

int main(){
    cin >> N;
    generateBDN(1);  // Bắt đầu từ số 1 (số BDN đầu tiên)
    cout << countBDN;
    return 0;
}
