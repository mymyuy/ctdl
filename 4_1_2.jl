function is_prime(n)
    if n <= 1 return false end
    for i in 2:sqrt(n)
        if n % i == 0 return false end
    end
    return true
end
println(is_prime(17))
