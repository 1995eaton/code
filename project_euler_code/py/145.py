#!/usr/bin/python
#lim = 10**9
lim = 100000001
c=0
for i in range(1, lim):
    if i % 10 != 0:
        if (i % 2 == 0 and int(str(i)[0]) % 2 != 0) or (i % 2 != 0 and int(str(i)[0]) % 2 == 0):
            b = False
            irev = int(str(i)[::-1])
            add = str(i + irev)
            for ii in add:
                if int(ii) % 2 == 0:
                    b = False
                    break
                b = True
            if b == True:
                print(i, irev, add)
                c += 1

print(c)
