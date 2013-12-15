
def isBouncy(n):
    ng = [int(i) for i in str(n)]
    dec = 0; inc = 0; stillinc = False; stilldec = False
    for i in range(0, len(ng) - 1):
        if ng[i] != ng[i+1]:
            if ng[i] > ng[i+1]:
                inc+=1
                stillinc = True
                stilldec = False
            else:
                dec+=1
                stilldec = True
                stillinc = False
        if (stillinc == True and dec >= 1) or (stilldec == True and inc >= 1):
            return True
    return False

lim = 50000000
bnums = 0
for i in range(1, lim + 1):
    if isBouncy(i):
        bnums += 1
        print(i, ": ", (bnums / i) * 100, "%", sep="")
        if bnums / i == 0.99:
            print(i, ": ", (bnums / i) * 100, "%", sep="")
            break
