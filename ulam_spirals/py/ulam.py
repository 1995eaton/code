from PIL import Image
from random import randrange
from math import e
import numpy

class PrimeChart:

    def __init__(self, side_length, both = False, prime_color = 0xffffff, nonprime_color = 0x000000, skew_ratio = 1):
        self.side_length = side_length
        self.skew_ratio = skew_ratio
        self.prime_color = prime_color
        self.nonprime_color = nonprime_color
        self.sieve = numpy.ones(((self.side_length**2)+7, ), dtype=numpy.bool)

        # Initiate sieve

        for i in range(2, int(side_length)):
            self.sieve[i*i::i] = False
        self.sieve[:2] = False
        print("Sieve generation finished")

        if both == True:
            self.Grid()
            self.Spiral()

    def Grid(self):
        img = Image.new("1", (int(self.side_length/self.skew_ratio), int(self.side_length*self.skew_ratio)), self.nonprime_color)
        width, height = img.size
        c = 0
        for x in range(0, width):
            for y in range(0, height):
                if self.sieve[(x)+(width*y)]:
                    c+=1
                    img.putpixel((x, y), self.prime_color)

        img.save("GRID-{0}.png".format(self.side_length))
        print("Grid generation finished")


    def Spiral(self):
        n, i, c = range(3)
        x = (self.side_length+1)//2
        y = x-1
        img = Image.new("1", [self.side_length]*2, self.nonprime_color)
        img.putpixel((x, y), self.prime_color)
        for l in range((self.side_length-1)//2):
            for n in range(i):
                y, c = y-1, c+1
                if self.sieve[c]:
                    img.putpixel((x, y), self.prime_color)
            i+=1
            for n in range(i):
                x, c = x-1, c+1
                if self.sieve[c]:
                    img.putpixel((x, y), self.prime_color)
            for n in range(i):
                y, c = y+1, c+1
                if self.sieve[c]:
                    img.putpixel((x, y), self.prime_color)
            i+=1 
            for n in range(i):
                x, c = x+1, c+1
                if self.sieve[c]:
                    img.putpixel((x, y), self.prime_color)
        img.save("ULAM-{0}.png".format(self.side_length))
        print("Spiral generation finished")


def main():
    p = PrimeChart(500, both = True)


if __name__ == '__main__':
    main()
