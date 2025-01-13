#include <iostream>
#include <vector>
#include <algorithm>  // Thêm thư viện để sử dụng hàm swap

using namespace std;

// Hàm median_of_three chọn pivot là trung vị của ba phần tử: low, mid và high.
int median_of_three(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;  // Tính giá trị của mid

    if (arr[low] > arr[mid]) {
        swap(arr[low], arr[mid]);  // Đảm bảo arr[low] <= arr[mid]
    }
    if (arr[low] > arr[high]) {
        swap(arr[low], arr[high]);  // Đảm bảo arr[low] <= arr[high]
    }
    if (arr[mid] > arr[high]) {
        swap(arr[mid], arr[high]);  // Đảm bảo arr[mid] <= arr[high]
    }

    return mid;  // Trả về chỉ số của phần tử trung vị
}

// Hàm partition sử dụng median làm pivot
int partition_median(vector<int>& arr, int low, int high) {
    int median = median_of_three(arr, low, high);  // Tính toán median
    swap(arr[median], arr[high]);  // Đổi median với phần tử cuối (pivot)

    // Hàm partition cơ bản để phân chia mảng
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // Đặt pivot vào đúng vị trí
    return i + 1;
}

// Hàm quickSort sử dụng median làm pivot
void quickSort_median(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition_median(arr, low, high);  // Lấy chỉ số pivot

        quickSort_median(arr, low, p - 1);  // Sắp xếp phần bên trái
        quickSort_median(arr, p + 1, high);  // Sắp xếp phần bên phải
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Mảng ban đầu: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    quickSort_median(arr, 0, arr.size() - 1);  // Gọi quickSort

    cout << "Mảng sau khi sắp xếp: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
