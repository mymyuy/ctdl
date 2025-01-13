function insertion_sort!(arr)
    n = length(arr)
    for i in 2:n
        key = arr[i]
        j = i - 1

        # Di chuyển các phần tử lớn hơn key một vị trí về phía sau
        while j >= 1 && arr[j] > key
            arr[j + 1] = arr[j]
            j -= 1
        end
        arr[j + 1] = key
    end
end

function print_array(arr)
    println(join(arr, " "))
end

# Chạy chương trình
arr = [12, 11, 13, 5, 6]
insertion_sort!(arr)
println("Sorted array: ", join(arr, " "))
