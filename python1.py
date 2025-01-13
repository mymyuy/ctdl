def find_max(arr):
    if not arr:  # Kiểm tra mảng trống
        return None
    
    max_value = arr[0]  # Khởi tạo giá trị lớn nhất ban đầu là phần tử đầu tiên
    for num in arr:     # Duyệt từng phần tử trong mảng
        if num > max_value:
            max_value = num  # Cập nhật giá trị lớn nhất nếu tìm thấy phần tử lớn hơn
    return max_value

# Ví dụ mảng
arr = [1, 3, 2, 5, 4]
max_value = find_max(arr)
if max_value is None:
    print("Mảng trống")
else:
    print("Giá trị lớn nhất:", max_value)
