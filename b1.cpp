#include <iostream>
#include <vector>
#include <climits> // Để sử dụng INT_MIN

int FindMax(const std::vector<int>& arr) {
    if (arr.empty()) {
        return INT_MIN; // Trả về INT_MIN nếu mảng trống
    }
    
    int max_value = arr[0]; // Khởi tạo giá trị lớn nhất ban đầu là phần tử đầu tiên
    for (int num : arr) {   // Duyệt từng phần tử trong mảng
        if (num > max_value) {
            max_value = num; // Cập nhật giá trị lớn nhất nếu tìm thấy phần tử lớn hơn
        }
    }
    return max_value;
}

int main() {
    std::vector<int> arr = {1, 3, 2, 5, 4}; // Ví dụ mảng
    int max_value = FindMax(arr);
    if (max_value == INT_MIN) {
        std::cout << "Mảng trống" << std::endl;
    } else {
        std::cout << "Giá trị lớn nhất: " << max_value << std::endl;
    }
    return 0;
}
