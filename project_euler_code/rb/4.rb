max = 0
(-999..-100).each { |a| (a*a < max)? break : (a..-100).each { |b| ((a*b < max) ? break : max = a*b) if (a*b).to_s == (a*b).to_s.reverse  } }
puts max
