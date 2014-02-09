m = 0
for x in range(999, 100, -1):
    for y in range(999, 100, -1):
        if str(x*y)[::-1] == str(x*y):
            if x*y > m:
                m = x*y
                print(m)
