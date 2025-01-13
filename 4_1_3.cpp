#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) swap(arr[++i], arr[j]);
        }
        swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    quickSort(arr, 0, arr.size() - 1);
    for (int num : arr) cout << num << " ";
    return 0;
}
