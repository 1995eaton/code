#!/usr/bin/python

count = 1 # +1 for 200

for p100 in range(0, 201, 100):
    for p50 in range(0, 201, 50):
        if p50+p100 > 200:
            break
        for p20 in range(0, 201, 20):
            if p20+p50 +p100 > 200:
                break
            for p10 in range(0, 201, 10):
                if p10+p20+p50+p100 > 200:
                    break
                for p5 in range(0, 201, 5):
                    if p5+p10+p20+p50+p100 > 200:
                        break
                    for p2 in range(0, 201, 2):
                        if p2+p5+p10+p20+p50+p100 > 200:
                            break
                        if p2+p5+p10+p20+p50+p100 < 200:
                            count += 1
                        if p2+p5+p10+p20+p50+p100 == 200:
                            count += 1
print(count)
