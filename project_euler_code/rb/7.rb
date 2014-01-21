primes = [nil, nil, *2..500000]
(2..(500000**0.5).to_i).each { |i| (i*i..500000).step(i) { |i| primes[i] = nil } if primes[i] }
puts primes.compact[10000]
