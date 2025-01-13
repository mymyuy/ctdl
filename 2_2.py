def linear_search(arr, target):
    for i, num in enumerate(arr):  # Duyệt qua từng phần tử trong mảng
        if num == target:  # So sánh với giá trị cần tìm
            return i  # Nếu tìm thấy, trả về chỉ số
    return -1  # Nếu không tìm thấy, trả về -1

# Ví dụ mảng
arr = [1, 3, 5, 7, 9]
target = 5
index = linear_search(arr, target)
if index != -1:
    print(f"Tìm thấy tại chỉ số: {index}")
else:
    print(f"Không tìm thấy giá trị {target}")
