import random

# Hàm partition
def partition(arr, low, high):
    pivot = arr[high]  # Chọn phần tử cuối làm pivot
    i = low - 1  # Chỉ số của phần tử nhỏ hơn pivot

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Đổi chỗ arr[i] và arr[j]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Đặt pivot vào đúng vị trí
    return i + 1

# Hàm randomized_partition
def randomized_partition(arr, low, high):
    pivot_index = random.randint(low, high)  # Chọn ngẫu nhiên một chỉ số pivot
    arr[pivot_index], arr[high] = arr[high], arr[pivot_index]  # Đổi vị trí pivot với phần tử cuối
    return partition(arr, low, high)

# Hàm quick_sort_randomized
def quick_sort_randomized(arr, low, high):
    if low < high:
        p = randomized_partition(arr, low, high)  # Lấy chỉ số phân hoạch
        quick_sort_randomized(arr, low, p - 1)  # Sắp xếp phần bên trái
        quick_sort_randomized(arr, p + 1, high)  # Sắp xếp phần bên phải
# Ví dụ sử dụng
arr = [10, 7, 8, 9, 1, 5]
print("Mảng ban đầu:", arr)

quick_sort_randomized(arr, 0, len(arr) - 1)

print("Mảng sau khi sắp xếp:", arr)