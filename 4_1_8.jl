function linear_search(arr, target)
    for (i, val) in enumerate(arr)
        if val == target
            return i
        end
    end
    return -1
end
println(linear_search([1, 2, 3, 4, 5], 3))
