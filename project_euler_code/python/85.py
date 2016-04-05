def count(w, h):
    s = 0
    for x in range(1, w + 1):
        for y in range(1, h + 1):
            s += (w - x + 1) * (h - y + 1)
    return s

mw, mh = 0, 0
diff = float('inf')
for w in range(1, 500):
    od = float('inf')
    for h in range(1, 500):
        a = w * h
        c = count(w, h)
        _diff = abs(2000000 - c)
        if _diff < diff:
            diff = _diff
            print(w, h, diff)
        if od < _diff:
            break
        od = _diff
