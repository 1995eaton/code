def Fib(lim):
    a, b = 0, 1
    while a < lim:
        yield a
        a, b = b, a + b

print(sum([i for i in list(Fib(4000000)) if not i % 2]))
