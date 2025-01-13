import random
from collections import Counter

def random_numbers_and_count(n, a, b):
    numbers = [random.randint(a, b) for _ in range(n)]
    counts = Counter(numbers)
    return numbers, counts

numbers, counts = random_numbers_and_count(10, 1, 5)
print("Numbers:", numbers)
print("Counts:", counts)
