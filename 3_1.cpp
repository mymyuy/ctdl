#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn key một vị trí về phía sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PrintArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    InsertionSort(arr);
    cout << "Sorted array: ";
    PrintArray(arr);
    return 0;
}
