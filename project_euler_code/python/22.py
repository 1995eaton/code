
import os
import re

name_open = open("names.txt", "r")
name_read = name_open.read()
name_list = re.findall(r"[A-Z]{1,}", name_read)
name_list_sort = sorted(name_list)

alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]

total_value_sum = 0
for n in name_list_sort:
 value = name_list_sort.index(n) + 1
 z_count = 0
 score_sum = 0
 for n2 in list(n):
  letter_score = alphabet.index(n2) + 1
  score_sum += letter_score
 total_value = score_sum * value
 total_value_sum += total_value
print(total_value_sum)
