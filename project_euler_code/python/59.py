import os
import itertools
from string import ascii_lowercase as alpha

_open = (open("cipher1.txt", "r").read()).rsplit()
cipher = [int(i) for i in _open]

print(cipher)
keys = list(itertools.permutations([ord(a) for a in alpha], 3))
for k in keys:
	decrypt = []
	code = []
for c in range(0, len(cipher), 3):
	groups = cipher[c:c+3]
if len(groups) == 3:
	n = 0
while n < 3:
	s = k[n]^groups[n]
	decrypt.append(chr(s))
	code.append(s)
	n += 1
if "Gospel" in "".join(decrypt):
	print("".join(decrypt))
print(sum(code) + 46)
print(len("".join(decrypt)), len(cipher))
input("")
