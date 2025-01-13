function fibonacci_recursive(n)
    return n <= 1 ? n : fibonacci_recursive(n-1) + fibonacci_recursive(n-2)
end

function fibonacci_iterative(n)
    a, b = 0, 1
    for _ in 1:n
        a, b = b, a + b
    end
    return a
end

println(fibonacci_recursive(10))
println(fibonacci_iterative(10))
