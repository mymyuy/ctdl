function factorial(n)
    return n == 0 ? 1 : n * factorial(n - 1)
end
println(factorial(5))
