puts (3..1000).select { |n| n % 5 == 0 or n % 3 == 0 }.inject(:+)
