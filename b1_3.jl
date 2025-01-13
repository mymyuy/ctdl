function find_max(arr)
    if isempty(arr)  # Kiểm tra mảng trống
        return nothing
    end
    
    max_value = arr[1]  # Khởi tạo giá trị lớn nhất ban đầu là phần tử đầu tiên
    for num in arr      # Duyệt từng phần tử trong mảng
        if num > max_value
            max_value = num  # Cập nhật giá trị lớn nhất nếu tìm thấy phần tử lớn hơn
        end
    end
    return max_value
end

# Ví dụ mảng
arr = [1, 3, 2, 5, 4]
max_value = find_max(arr)
if isnothing(max_value)
    println("Mảng trống")
else
    println("Giá trị lớn nhất: ", max_value)
end
