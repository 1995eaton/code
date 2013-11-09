#!/usr/bin/python
import itertools
l1 = list(str("0123456789"))
l2 = list(itertools.permutations(l1, len(l1)))
print(sorted(l2)[1000000 - 1])
