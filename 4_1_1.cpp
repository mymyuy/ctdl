#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << sumArray(arr) << endl;
    return 0;
}
