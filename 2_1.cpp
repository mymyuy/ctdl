#include <iostream>
#include <vector>

int LinearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) { // Duyệt qua từng phần tử trong mảng
        if (arr[i] == target) {  // So sánh với giá trị cần tìm
            return i;  // Nếu tìm thấy, trả về chỉ số
        }
    }
    return -1;  // Nếu không tìm thấy, trả về -1
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9};  // Ví dụ mảng
    int target = 5;  // Giá trị cần tìm
    int index = LinearSearch(arr, target);
    if (index != -1) {
        std::cout << "Tìm thấy tại chỉ số: " << index << std::endl;
    } else {
        std::cout << "Không tìm thấy giá trị " << target << std::endl;
    }
    return 0;
}
