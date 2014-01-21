import os

poker = (open("poker.txt", "r").read()).split('\n'); poker.pop()

values = ['2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A']
suits = ['D', 'S', 'H', 'C']

def vcount(i):
    c = 0; t = 0; cs = []
    for v in values:
        if i.count(v) == 1:
            if len(cs) == 0 or (len(cs) > 0 and values.index(v) == values.index(cs[len(cs) - 1]) + 1):
                t += 1
            cs.append(v)
        if i.count(v) == 2:
            c += 1
            if c == 1:
                fv = v
            if c == 2:
                return i, [2, v]
        if i.count(v) == 3:
            return i, [4, v]
    if c == 1:
        return i, [1, fv]
    if t == 5:
        return i, [5, cs[0]]

count = 0

for i in poker:
    vc1 = vcount(i[:14]); vc2 = vcount(i[14:])
    if vc1 and vc2:
        if vc1[1][0] > vc2[1][0]:
            count += 1
        if vc1[1][0] == vc2[1][0]:
            if values.index(vc1[1][1]) > values.index(vc2[1][1]):
                count += 1
    if not vc2:
        if vc1:
            count += 1
        if not vc1:
            for v in values:
                if v in i[:14]:
                    i1mv = v
                if v in i[14:]:
                    i2mv = v
            if values.index(i1mv) > values.index(i2mv):
                count += 1
print(count)
