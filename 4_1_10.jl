using Random

function random_numbers_and_count(n, a, b)
    numbers = rand(a:b, n)
    counts = Dict(num => count(x -> x == num, numbers) for num in unique(numbers))
    return numbers, counts
end

numbers, counts = random_numbers_and_count(10, 1, 5)
println("Numbers: ", numbers)
println("Counts: ", counts)
