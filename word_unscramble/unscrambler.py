import sys, re, os

def Unscramble(words, isFile):
  if os.path.isfile("dictionary"):
    dictionary = (open("dictionary", "r").read()).rsplit()
    if isFile and os.path.isfile(words):
      input_file = [i for i in re.sub("\W", " ", (open(words, "r").read()).lower()).split(" ") if len(i) != 0]
      for i0 in input_file:
        for i1 in dictionary:
          if len(i0) == len(i1) and sorted(i0) == sorted(i1):
            print(i1)
    else:
      for i0 in words:
        for i1 in dictionary:
          if len(i0) == len(i1) and i0 == sorted(i1):
            print(i1)
  else:
    print("Dictionary does not exist")

def main():
  if sys.argv[1] == "-f":
    Unscramble(str(sys.argv[2]), 1)
  else:
    Unscramble([sorted(str(i)) for i in sys.argv], 0)

if __name__ == "__main__":
  main()
