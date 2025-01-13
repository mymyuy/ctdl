function compute_factorial(n)
    if n == 0 || n == 1
        return 1
    else
        return n * compute_factorial(n - 1)
    end
end

function main()
    println("Enter a number: ")
    input = readline()
    n = tryparse(Int, input)
    
    if isnothing(n) || n < 0
        println("Invalid input or factorial is not defined for negative numbers.")
    else
        result = compute_factorial(n)
        println("Factorial of $n is: $result")
    end
end

# Chạy chương trình
main()
