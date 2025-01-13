# Hàm Insertion Sort
def insertion_sort(arr, left, right):
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Hàm Merge để hợp nhất hai mảng con đã sắp xếp
def merge(arr, left, mid, right):
    # Tạo các mảng tạm thời để lưu các phần tử
    n1 = mid - left + 1
    n2 = right - mid
    left_arr = arr[left:left + n1]
    right_arr = arr[mid + 1:mid + 1 + n2]

    i = j = 0
    k = left

    # Hợp nhất các mảng tạm thời vào mảng ban đầu
    while i < n1 and j < n2:
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
        else:
            arr[k] = right_arr[j]
            j += 1
        k += 1

    # Sao chép các phần tử còn lại nếu có
    while i < n1:
        arr[k] = left_arr[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = right_arr[j]
        j += 1
        k += 1

# Hàm Hybrid Merge Sort
def merge_sort_hybrid(arr, left, right):
    # Nếu mảng nhỏ hơn 10 phần tử, sử dụng Insertion Sort
    if right - left + 1 < 10:
        insertion_sort(arr, left, right)
    # Nếu mảng có nhiều phần tử hơn, sử dụng Merge Sort
    elif left < right:
        mid = (left + right) // 2

        # Sắp xếp đệ quy hai nửa mảng
        merge_sort_hybrid(arr, left, mid)
        merge_sort_hybrid(arr, mid + 1, right)

        # Hợp nhất các phần đã được sắp xếp
        merge(arr, left, mid, right)

# Hàm in mảng
def print_array(arr):
    print(" ".join(map(str, arr)))

# Kiểm thử thuật toán Hybrid Merge Sort
if __name__ == "__main__":
    arr = [10, 7, 8, 9, 1, 5, 3, 2, 6, 4]
    
    print("Mảng ban đầu:")
    print_array(arr)
    
    merge_sort_hybrid(arr, 0, len(arr) - 1)
    
    print("Mảng sau khi sắp xếp:")
    print_array(arr)
