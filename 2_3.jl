function linear_search(arr, target)
    for (i, num) in enumerate(arr)  # Duyệt qua từng phần tử trong mảng
        if num == target  # So sánh với giá trị cần tìm
            return i - 1  # Julia bắt đầu từ chỉ số 1, trả về chỉ số bắt đầu từ 0
        end
    end
    return -1  # Nếu không tìm thấy, trả về -1
end

# Ví dụ mảng
arr = [1, 3, 5, 7, 9]
target = 5
index = linear_search(arr, target)
if index != -1
    println("Tìm thấy tại chỉ số: ", index)
else
    println("Không tìm thấy giá trị ", target)
end
