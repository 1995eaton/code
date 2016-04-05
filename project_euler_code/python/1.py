def pu1(n):
    n -= 1
    def f(x):
        r = n // x
        return x * (r * r + r >> 1)
    return f(3) + f(5) - f(15)

print(pu1(1000))
