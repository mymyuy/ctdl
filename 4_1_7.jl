function count_characters(s)
    return Dict(c => count(x -> x == c, s) for c in unique(s))
end
println(count_characters("hello world"))
