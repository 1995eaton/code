import os

def main():

 s = (open("s.txt", "r").read()).strip('\n')

 l1 = list(a + b for a, b in zip(s[0::2], s[1::2]))
 l2 = []
 for x in range(len(l1) - 60):
  vert = [l1[x], l1[x + 20], l1[x + 40], l1[x + 60], int(l1[x]) * int(l1[x + 20]) * int(l1[x + 40]) * int(l1[x + 60])]
  l2.append(vert)
 for y in range(len(l1) - 63):
  digr = l1[y], l1[y + 21], l1[y + 42], l1[y + 63], int(l1[y]) * int(l1[y + 21]) * int(l1[y + 42]) * int(l1[y + 63])
  l2.append(digr)
 for z in range(3, len(l1) - 60):
  digl = (l1[z], l1[z + 19], l1[z + 38], l1[z + 57], int(l1[z]) * int(l1[z + 19]) * int(l1[z + 38]) * int(l1[z + 57]))
  l2.append(digl)
 for a in range(len(l1) - 3):
  hor = (l1[a], l1[a + 1], l1[a + 2], l1[a + 3], int(l1[a]) * int(l1[a + 1]) * int(l1[a + 2]) * int(l1[a + 3]))
  l2.append(hor)

 print(sorted(l2, key=lambda num: num[4]))


main()
