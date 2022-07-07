def fibonacci(n: int) -> int:
    # 0, 1, 1, 2, 3, 5, 8,13,21, 34, 55, 89
    # 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12
    # 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    u, v = 0, 1
    if n == 0:
        return u
    else:
        for i in range (1, n):
            u, v = v, u + v
        return v


for i in range(0,10):
    result = fibonacci(i)
    print(f"a_{i} = {result}")
