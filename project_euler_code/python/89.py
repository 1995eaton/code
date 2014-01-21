import os, sys, math, re
numerals = (open("roman.txt", "r").read()).split("\n")

def fromRoman(roman):
    total = 0
    sval = [["XC", 90], ["XL", 40], ["IX", 9], ["IV", 4], ["CD", 400], ["CM", 900]]
    val = [["M", 1000], ["D", 500], ["C", 100], ["L", 50], ["X", 10], ["V", 5], ["I", 1]]
    for x, y in sval:
        if x in roman:
            roman = re.sub(x, "", roman); total += y
    for xx, yy in val:
        total += roman.count(xx) * yy
    return total

def toRoman(decimal):
    roman = ""
    if decimal >= 900:
        if decimal % 1000 >= 900:
            roman += "CM"; decimal -= 900
            roman += "M" * math.floor(decimal/1000)
            decimal -= 1000 * math.floor(decimal/1000)

        roman += "M" * math.floor(decimal/1000)
        decimal -= 1000 * math.floor(decimal/1000)
    if decimal >= 100:
        if decimal % 1000 >= 500:
            roman += "D"; decimal -= 500
        elif decimal % 1000 >= 400:
            roman += "CD"; decimal -= 400

        roman += "C" * math.floor(decimal/100)
        decimal -= 100 * math.floor(decimal/100)
    if decimal >= 10 and decimal < 90:
        if decimal >= 50:
            roman += "L"; decimal -= 50
        if decimal >= 40:
            roman += "XL"; decimal -= 40

        roman += "X" * math.floor(decimal/10)
        decimal -= 10 * math.floor(decimal/10)

    if decimal >= 90:
        roman += "XC"; decimal -= 90
    if decimal == 9:
        roman += "IX"; decimal = 0
    if decimal >= 5:
        roman += "V"; decimal -= 5
    if decimal == 4:
        roman += "IV"; decimal = 0
    roman += "I" * decimal
    return roman

originalLen = 0
simplifiedLen = 0
for n in numerals:
    originalLen += len(n)
    toDecimal = fromRoman(n)
    decimaltoRoman = toRoman(toDecimal)
    simplifiedLen += len(decimaltoRoman)
    print(decimaltoRoman)

print("\nOriginal:  ", originalLen)
print("After:     ", simplifiedLen)
print("Difference:", originalLen - simplifiedLen)
