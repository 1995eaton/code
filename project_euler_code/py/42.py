#!/usr/bin/python

import string, os, re; from collections import Counter
nzc = [[x[0], x[1]] for x in zip(Counter([sum([((string.ascii_lowercase).index(i)+1) for i in str(x)]) for x in re.findall(r"\b(\w+)\b", (open("words.txt", "r")).read().lower())]).values(), set(Counter([sum([((string.ascii_lowercase).index(i)+1) for i in str(x)]) for x in re.findall(r"\b(\w+)\b", (open("words.txt", "r")).read().lower())]).elements()))]
print(sum([x[0] for x in nzc if x[1] in [int((n/2)*(n+1)) for n in range(1, max(nzc[len(nzc)-1])) if (n/2)*(n+1) < max(nzc[len(nzc)-1])]]))
print(sum([x[0] for x in nzc if x[1] in [int((n/2)*(n+1)) for n in range(1, max(nzc[len(nzc)-1])) if (n/2)*(n+1) < max(nzc[len(nzc)-1])]]))
