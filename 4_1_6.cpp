#include <iostream>
#include <vector>
using namespace std;

int maxInArray(const vector<int>& arr) {
    int max_val = arr[0];
    for (int num : arr) {
        if (num > max_val) max_val = num;
    }
    return max_val;
}

int main() {
    vector<int> arr = {3, 5, 2, 9, 1};
    cout << maxInArray(arr) << endl;
    return 0;
}
