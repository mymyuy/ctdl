import Base: push!, pop!, display  # Import các phương thức cần thiết

mutable struct Stack
    elements::Vector{Any}  # Khai báo kiểu dữ liệu của `elements`
    Stack() = new(Vector{Any}())  # Hàm tạo mặc định
end

function push!(s::Stack, item)
    push!(s.elements, item)  # Thêm phần tử vào ngăn xếp
    println("Đã thêm '$item' vào ngăn xếp.")
end

function pop!(s::Stack)
    if !isempty(s.elements)
        item = pop!(s.elements)  # Lấy phần tử cuối cùng ra khỏi ngăn xếp
        println("Đã lấy '$item' ra khỏi ngăn xếp.")
        return item
    else
        println("Ngăn xếp trống!")
        return nothing
    end
end

function peek(s::Stack)
    if !isempty(s.elements)
        return s.elements[end]  # Truy cập phần tử cuối cùng
    else
        println("Ngăn xếp trống!")
        return nothing
    end
end

function is_empty(s::Stack)
    return isempty(s.elements)  # Kiểm tra ngăn xếp rỗng
end

function display(s::Stack)
    println("Ngăn xếp (đỉnh đến đáy): ", reverse(s.elements))  # In ngăn xếp từ đỉnh đến đáy
end

function main()
    stack = Stack()
    push!(stack, "Sách A")
    push!(stack, "Sách B")
    push!(stack, "Sách C")

    display(stack)

    top_item = peek(stack)
    println("Phần tử ở đỉnh ngăn xếp: ", top_item)

    pop!(stack)

    display(stack)

    println("Ngăn xếp có trống không? ", is_empty(stack) ? "Có" : "Không")
end

main()
