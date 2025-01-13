#include <iostream>
#include <vector>
#include <algorithm>  // Thư viện để sử dụng hàm min

using namespace std;

// Hàm hợp nhất (merge) hai phần của mảng
void merge(vector<int>& arr, int left_start, int mid, int right_end) {
    int n1 = mid - left_start + 1;
    int n2 = right_end - mid;

    vector<int> left(n1), right(n2);

    // Sao chép dữ liệu vào mảng phụ
    for (int i = 0; i < n1; i++) {
        left[i] = arr[left_start + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    // Hợp nhất hai mảng vào mảng ban đầu
    int i = 0, j = 0, k = left_start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Sao chép phần còn lại của mảng left (nếu có)
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Sao chép phần còn lại của mảng right (nếu có)
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Hàm Bottom-Up Merge Sort
void bottomUpMergeSort(vector<int>& arr) {
    int n = arr.size();

    // Duyệt qua các kích thước phần tử
    for (int curr_size = 1; curr_size < n; curr_size = 2 * curr_size) {
        // Duyệt qua các mảng con có kích thước curr_size
        for (int left_start = 0; left_start < n; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);  // Sửa tính toán mid
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);  // Sửa tính toán right_end
            merge(arr, left_start, mid, right_end);  // Hợp nhất các phần
        }
    }
}

// Hàm in mảng
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    cout << "Mảng ban đầu: ";
    printArray(arr);
    
    bottomUpMergeSort(arr);  // Gọi hàm Bottom-Up Merge Sort

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr);
    
    return 0;
}
