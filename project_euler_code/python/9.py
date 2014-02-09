def main():
    for a in range(2, 500):
        for b in range(a, 500):
            for c in range(b, 500):
                if a + b + c == 1000:
                    if a**2 + b**2 == c**2:
                        return a*b*c
                if a + b + c > 1000:
                    break

print(main())
